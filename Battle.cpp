#include "Battle.h"
#include <limits>
#include "TypeChart.h"
#include "PhysicalMove.h"
#include "AttackMove.h"
#include "StatusMove.h"
#include "SpAttackMove.h"

Battle::Battle() : player1(nullptr), player2(nullptr), pokedex(nullptr), turnCount(1), isVsAI(false){typeChart.loadFromFile("typechart.txt");}

Battle::Battle(Trainer * p1): player1(p1), player2(nullptr), pokedex(nullptr), turnCount(1), isVsAI(false){typeChart.loadFromFile("typechart.txt");}

Battle::Battle(Trainer *p1, Trainer *p2) : player1(p1), player2(p2), pokedex(nullptr), turnCount(1), isVsAI(false){typeChart.loadFromFile("typechart.txt");}

Battle::Battle(Trainer *p1, Trainer *p2, Pokedex *dex) : player1(p1), player2(p2), pokedex(dex), turnCount(1), isVsAI(false){typeChart.loadFromFile("typechart.txt");}

Battle::Battle(Trainer *p1, Trainer *p2, Pokedex *dex, int count) : player1(p1), player2(p2), pokedex(dex), turnCount(count), isVsAI(false){typeChart.loadFromFile("typechart.txt");}

Battle::Battle(Trainer *p1, Trainer *p2, Pokedex *dex, int count, bool ai) : player1(p1), player2(p2), pokedex(dex), turnCount(count), isVsAI(ai){typeChart.loadFromFile("typechart.txt");}

Battle::Battle(const Battle &obj): player1(obj.player1),
      player2(obj.player2),
      pokedex(obj.pokedex),
      typeChart(obj.typeChart),
      turnCount(obj.turnCount) , isVsAI(obj.isVsAI){
}

Battle &Battle::operator=(const Battle &obj) {
      if (this != &obj) {
            this->player1 = obj.player1;
            this->player2 = obj.player2;
            this->pokedex = obj.pokedex;
            this->typeChart = obj.typeChart;
            this->turnCount = obj.turnCount;
            this->isVsAI = obj.isVsAI;
      }
      return *this;
}

      std::ostream& operator<<(std::ostream& os, const Battle& obj) {
            os << "Player 1: ";
            if (obj.player1 != nullptr) {
                  os << obj.player1->getName();
            } else {
                  os << "EMPTY SLOT";
            }

            os << "\n      VS\n";

            os << "Player 2: ";
            if (obj.player2 != nullptr) {
                  os << obj.player2->getName();
            } else {
                  os << "EMPTY SLOT";
            }

            os<<"Turn count: "<<obj.turnCount;
            return os;
      }

std::istream& operator>>(std::istream& is, Battle& obj) {
      if (obj.player1 == nullptr || obj.player2 == nullptr)
            throw std::runtime_error("Cannot configure battle — trainers are null");

      std::cout << "Starting turn count (default 1): ";
      is >> obj.turnCount;
      if (is.fail() || obj.turnCount < 1) {
            is.clear();
            is.ignore(1000, '\n');
            throw std::invalid_argument("Turn count must be at least 1");
      }

      std::cout << "Are both players ready? (yes/no): ";
      std::string ready;
      is >> ready;
      if (ready != "yes")
            throw std::runtime_error("Players not ready — battle cancelled");

      return is;
}

Battle::~Battle(){}

void Battle::applyDamage(Pokemon* attacker, Pokemon* defender, Move* move) {
      if (!move || !attacker || !defender) return;
      int baseDamage = 0;
      auto* phys = dynamic_cast<PhysicalMove*>(move);
      auto* spec = dynamic_cast<SpAttackMove*>(move);
      if (phys) baseDamage = phys->getPower();
      else if (spec) baseDamage = spec->getPower();
      if (baseDamage <= 0) {
            std::cout << attacker->getName() << " used " << move->getName() << "!\n";
            return;
      }
      double multiplier = 1.0;
      try {
            multiplier = typeChart.getMultiplier(move->getType(), defender->getType());
      } catch (...) {
            multiplier = 1.0;
      }
      int finalDamage = static_cast<int>(baseDamage * multiplier);
      defender->takeDamage(finalDamage);
      std::cout << attacker->getName() << " used " << move->getName() << "!\n";
      if (multiplier > 1.0) std::cout << "  It's super effective!\n";
      else if (multiplier < 1.0 && multiplier > 0) std::cout << "  It's not very effective...\n";
      std::cout << "  " << defender->getName() << " lost " << finalDamage << " HP ("
                << defender->getHp() << " remaining).\n";
}

void Battle::handlePostBattleRewards(Trainer *winner) {
      if (winner == nullptr)
            throw std::invalid_argument("Winner cannot be null");
      if (pokedex == nullptr)
            throw std::runtime_error("Pokedex is null — cannot check evolutions");
      std::cout<<"Congratulations! "<<winner->getName()<<" has won the battle!";
      for (int i=0; i<winner->getTeamSize(); i++) {
            Pokemon*p= winner->getPokemon(i);
            if (p->getLevel()>=p->getEvLevel() && p->getEvolutionName()!="NONE") {
                  std::cout<<p->getName()<<" is evolving! ...\n";
                  std::cout<<"Your "<<p->getName()<<" has evolved into a "<<p->getEvolutionName()<<"\n";
                  Pokemon * evolved = pokedex ->createByName(p->getEvolutionName());
                  p->transferProgressTo(evolved);
                  winner->replacePokemon(i, evolved);
                  delete p;

            }
      }
}

Move* Battle::chooseBestMoveAI(Trainer* computer, Pokemon* target) {
      if (computer == nullptr || target == nullptr)
            throw std::invalid_argument("Cannot choose move — null trainer or target");
      Pokemon* aiPokemon = computer->getActivePokemon();
      std::vector<Move*> moves = aiPokemon->getMoves();
      if (moves.empty())
            throw std::runtime_error(aiPokemon->getName() + " has no moves");
      Move* bestMove = moves[0];
      float bestMultiplier = -1.0f;
      for (int i = 0; i < moves.size(); i++) {
            float mult = 1.0f;
            try {
                  mult = typeChart.getMultiplier(moves[i]->getType(), target->getType());
            } catch (...) {
                  mult = 1.0f;
            }
            if (mult > bestMultiplier) {
                  bestMultiplier = mult;
                  bestMove = moves[i];
            }
      }
      return bestMove;
}

Move* Battle::getMoveFromPlayer(Trainer* player) {
      Pokemon* p = player->getActivePokemon();
      auto moves = p->getMoves();

      while (true) {
            std::cout << "\nCe atac foloseste " << p->getName() << "?\n";
            for (int i = 0; i < (int)moves.size(); i++) {
                  std::cout << i + 1 << ". " << moves[i]->getName() << "\n";
            }
            std::cout << "> ";

            int choice;
            std::cin >> choice;

            if (std::cin.fail() || choice < 1 || choice > (int)moves.size()) {
                  std::cout << "Invalid option! Choose a number between 1 and " << moves.size() << ".\n";
                  std::cin.clear();
                  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                  return moves[choice - 1];
            }
      }
}

bool Battle::checkFaint(Trainer* victim, Trainer* attacker) {
      Pokemon* active = victim->getActivePokemon();
      if (active->getHp() <= 0) {
            std::cout << "\n[!] " << active->getName() << " fainted!\n";

            if (victim->hasAlivePokemon()) {
                  for (int i = 0; i < victim->getTeamSize(); i++) {
                        if (victim->getPokemon(i)->getHp() > 0) {
                              victim->switchPokemon(i + 1);
                              std::cout << victim->getName() << " sent out " << victim->getActivePokemon()->getName() << "!\n";
                              break;
                        }
                  }
                  return false;
            } else {
                  return true;
            }
      }
      return false;
}

Trainer* Battle::getWinner() const {
      if (!isOver()) {
            return nullptr;
      }
      if (player1->hasAlivePokemon()) {
            return player1;
      }
      else if (player2->hasAlivePokemon()) {
            return player2;
      }
      return nullptr;
}



bool Battle::isOver() const {
      return !player1->hasAlivePokemon() || !player2->hasAlivePokemon();
}

void Battle::start(bool vsAI) {
      bool battleOver = false;
      this->isVsAI = vsAI;
      while (!battleOver) {
            try {
                  playTurn();
                  if (player1->getActivePokemon()->getHp() <= 0) {
                        battleOver = checkFaint(player1, player2);
                  }
                  if (!battleOver && player2->getActivePokemon()->getHp() <= 0) {
                        battleOver = checkFaint(player2, player1);
                  }

                  if (!player1->hasAlivePokemon() || !player2->hasAlivePokemon()) {
                        battleOver = true;
                  }
            } catch (const std::exception& e) {
                  std::cerr << "Battle error: " << e.what() << std::endl;
                  break;
            }
      }
      Trainer* currentWinner = nullptr;
      if (player1->hasAlivePokemon()) currentWinner = player1;
      else currentWinner = player2;
      std::cout << "\n*** WINNER: " << currentWinner->getName() << " ***\n";
}


void Battle::displayHUD() {
    Pokemon* p1A = player1->getActivePokemon();
    Pokemon* p2A = player2->getActivePokemon();

    if (!p1A || !p2A) return;

    std::cout << "\n========================================" << std::endl;
    std::cout << player1->getName() << "'s " << p1A->getName()
              << " HP: " << p1A->getHp() << "/" << p1A->getMaxHp() << std::endl;
    std::cout << player2->getName() << "'s " << p2A->getName()
              << " HP: " << p2A->getHp() << "/" << p2A->getMaxHp() << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void Battle::playTurn() {
      Pokemon* p1Active = player1->getActivePokemon();
      Pokemon* p2Active = player2->getActivePokemon();
      if (!p1Active || !p2Active) return;
      displayHUD();
      int choice1 = getBattleChoice(player1);
      if (choice1 == 2) {
            int newIdx;
            std::cout << "Enter the index of the Pokemon to switch to: ";
            std::cin >> newIdx;
            player1->switchPokemon(newIdx);
            p1Active = player1->getActivePokemon();
      }
      Move* move1 = (choice1 == 1) ? getMoveFromPlayer(player1) : nullptr;
      Move* move2 = nullptr;
      if (isVsAI) {
            move2 = chooseBestMoveAI(player2, p1Active);
      } else {
            int choice2 = getBattleChoice(player2);
            if (choice2 == 2) {
                  int newIdx;
                  std::cout << "Enter the index of the Pokemon to switch to: ";
                  std::cin >> newIdx;
                  player2->switchPokemon(newIdx);
                  p2Active = player2->getActivePokemon();
            }
            if (choice2 == 1) move2 = getMoveFromPlayer(player2);
      }
      bool p1First = p1Active->getSpeed() >= p2Active->getSpeed();
      if (p1First) {
            if (move1) applyDamage(p1Active, p2Active, move1);

            if (p2Active->getHp() > 0) {
                  if (move2) applyDamage(p2Active, p1Active, move2);
            } else {
                  checkFaint(player2, player1);
            }

            if (p1Active->getHp() <= 0) checkFaint(player1, player2);
      }
      else {
            if (move2) applyDamage(p2Active, p1Active, move2);

            if (p1Active->getHp() > 0) {
                  if (move1) applyDamage(p1Active, p2Active, move1);
            } else {
                  checkFaint(player1, player2);
            }

            if (p2Active->getHp() <= 0) checkFaint(player2, player1);
      }
}

int Battle::getBattleChoice(Trainer* t) {
      int choice;
      while (true) {
            std::cout << t->getName() << ", what will you do?\n";
            std::cout << "1. Fight\n";
            std::cout << "2. Switch Pokemon\n";
            std::cout << "> ";

            std::cin >> choice;

            if (std::cin.fail() || (choice != 1 && choice != 2)) {
                  std::cin.clear();
                  std::cin.ignore(1000, '\n');
                  std::cout << "Invalid option! Choose 1 or 2.\n";
            } else {
                  return choice;
            }
      }
}