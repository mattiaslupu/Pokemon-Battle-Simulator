#include "Battle.h"

Battle::Battle() : player1(nullptr), player2(nullptr), pokedex(nullptr), turnCount(1), isVsAI(false){}

Battle::Battle(Trainer * p1): player1(p1), player2(nullptr), pokedex(nullptr), turnCount(1), isVsAI(false){}

Battle::Battle(Trainer *p1, Trainer *p2) : player1(p1), player2(p2), pokedex(nullptr), turnCount(1), isVsAI(false){}

Battle::Battle(Trainer *p1, Trainer *p2, Pokedex *dex) : player1(p1), player2(p2), pokedex(dex), turnCount(1), isVsAI(false){}

Battle::Battle(Trainer *p1, Trainer *p2, Pokedex *dex, int count) : player1(p1), player2(p2), pokedex(dex), turnCount(count), isVsAI(false){}

Battle::Battle(Trainer *p1, Trainer *p2, Pokedex *dex, int count, bool ai) : player1(p1), player2(p2), pokedex(dex), turnCount(count), isVsAI(ai){}

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
      std::cout << "Starting turn count (default 1): ";
      is >> obj.turnCount;
      if (obj.player1 != nullptr && obj.player2 != nullptr) {
            std::cout << "Match confirmed: " << obj.player1->getName()
                      << " vs " << obj.player2->getName() << "\n";
            std::cout << "Are both players ready? (yes/no): ";
            std::string ready;
            is >> ready;

            if (ready != "yes") {
                  std::cout << "Warning: Players marked as NOT READY.\n";
            }
      } else {
            std::cout << "Warning: One or both trainers are missing! Assign them in main.\n";
      }

      return is;
}
Battle::~Battle(){}

void Battle::applyDamage(Pokemon *attacker, Pokemon *defender, Move* moveUsed) {
      int damage = moveUsed->getDamage(*attacker, *defender);
      if (damage>0) {
            double multiplier = typeChart.getMultiplier(moveUsed->getType(), defender->getType());
            int finalDamage = static_cast<int>(damage * multiplier);
            defender->takeDamage(finalDamage);
            std::cout << defender->getName() << " lost " << finalDamage << " HP!\n";
      }
      moveUsed->applyEffect(*defender);
}

void Battle::checkFaint(Trainer* attacker, Trainer* defender) {
      Pokemon* target = defender->getActivePokemon();
      if (target->isFainted()) {
            std::cout << "\n[BATTLE] " << target->getName() << " has fainted!\n";
            Pokemon* winner = attacker->getActivePokemon();
            std::cout << "[XP] " << winner->getName() << " defeated the opponent and leveled up!\n";
            winner->levelUp();
            if (defender->hasAlivePokemon()) {
                  std::cout << "[ACTION] " << defender->getName() << ", send out your next Pokemon!\n";
            } else {
                  std::cout << "[GAME OVER] " << defender->getName() << " has no more Pokemon left!\n";
            }
      }
}

void Battle::handlePostBattleRewards(Trainer *winner) {
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

Move *Battle::chooseBestMoveAI(Trainer *computer, Pokemon *target) {
      Pokemon * aiPokemon = computer->getActivePokemon();
      std::vector<Move*> moves= aiPokemon->getMoves();

      if (moves.empty()) return nullptr;

      Move* bestMove = moves[0];
      float bestMultiplier = 0 ;
      for (int i=0; i<moves.size(); i++) {
            float mult= typeChart.getMultiplier(moves[i]->getType(), target->getType());
            if (mult>bestMultiplier) {
                  bestMultiplier=mult;
                  bestMove=moves[i];
            }
      }
      return bestMove;
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

void Battle::playTurn() {
      Pokemon* p1Active = player1->getActivePokemon();
      Pokemon* p2Active = player2->getActivePokemon();
      Move* move1 = Menu::showBattleOptions(player1);
      Move* move2 = nullptr;

      if (isVsAI) {
            move2=chooseBestMoveAI(player2, p1Active);
      }
      else {
            move2=Menu::showBattleOptions(player2);
      }

      bool p1First = p1Active->getSpeed() > p2Active->getSpeed();
      if (p1First) {
            if (move1) applyDamage(p1Active, p2Active, move1);
            checkFaint(player1, player2);
            if (!p2Active->isFainted() && move2) {
                  applyDamage(p2Active, p1Active, move2);
                  checkFaint(player2, player1);
            }
            else {
                  if (move2) applyDamage(p2Active, p1Active, move2);
                  checkFaint(player2, player1);

                  if (!p1Active->isFainted() && move1) {
                        applyDamage(p1Active, p2Active, move1);
                        checkFaint(player1, player2);
                  }
            }
      }
}


bool Battle::isOver() const {
      return !player1->hasAlivePokemon() || !player2->hasAlivePokemon();
}

void Battle::start(bool vsAI) {
      this->isVsAI = vsAI;
      std::cout << "\n=== BATTLE START! ===\n";
      std::cout << player1->getName() << " VS " << player2->getName() << "\n\n";

      while (!isOver()) {
            playTurn();
      }
      Trainer* winner = getWinner();

      if (winner != nullptr) {
            handlePostBattleRewards(winner);
      } else {
            std::cout << "\n[BATTLE] It's a draw! Both trainers are out of Pokemon!\n";
      }
}
