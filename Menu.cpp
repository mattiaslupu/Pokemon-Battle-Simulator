#include "Menu.h"
#include "utils.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "PhysicalMove.h"
#include "AttackMove.h"
#include "SpAttackMove.h"
#include "StatusMove.h"

Menu::Menu() {
    pokedex = new Pokedex();
    pokedex->loadFromFile("pokemon.txt");
    typeChart = new TypeChart();
    typeChart->loadFromFile("typechart.txt");


    player = new Trainer();
    rival = new Trainer("Rival");
}

Menu::~Menu() {
    delete pokedex;
    delete typeChart;
    delete player;
    delete rival;
}

void Menu::printSeparator() const {
    std::cout << "=====================================\n";
}

void Menu::printHpBar(int hp, int maxHp) const {
    int filled = (maxHp > 0) ? (hp * 20) / maxHp : 0;
    std::cout << "  HP [";
    for (int i = 0; i < 20; i++)
        std::cout << (i < filled ? "#" : "-");
    std::cout << "] " << hp << "/" << maxHp << "\n";
}

void Menu::run() {
    srand(static_cast<unsigned int>(time(0)));
    this->initGame();
    bool ok = true;
    while (ok) {
        showMainMenu();
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        std::cin.ignore(1000, '\n');

        try {
            switch (choice) {
                case 1: choosePokemon();    break;
                case 2: showTeam();         break;
                case 3: showPokedex();      break;
                case 4: startBattle();      break;
                case 5: showTypeChart();    break;
                case 6: editTypeChart();    break;
                case 7:
                    try {
                        player->saveToFile("save.txt");
                        std::cout << "Game saved successfully!\n";
                    } catch (std::runtime_error& e) {
                        std::cout << "Could not save: " << e.what() << "\n";
                    }
                    break;
                case 0:
                    ok = false;
                    break;
                default:
                    std::cout << "Invalid option. Try again.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    try {
        player->saveToFile("save.txt");
        std::cout << "Auto-saved successfully.\n";
    } catch (const std::exception& e) {
        std::cout << "Could not auto-save.\n";
    }

    std::cout << "Goodbye, " << player->getName() << "!\n";
}

void Menu::showMainMenu() const {
    printSeparator();
    std::cout << "     POKEMON BATTLE SIMULATOR\n";
    printSeparator();
    std::cout << "  Trainer : " << player->getName() << "\n";
    std::cout << "  Team    : " << player->getTeamSize() << "/6\n";
    printSeparator();
    std::cout << "  1. Choose Pokemon\n";
    std::cout << "  2. View Team\n";
    std::cout << "  3. View Pokedex\n";
    std::cout << "  4. Start Battle\n";
    std::cout << "  5. View Type Chart\n";
    std::cout << "  6. Edit Type Chart\n";
    std::cout << "  7. Save Game\n";
    std::cout << "  0. Exit\n";
    printSeparator();
    std::cout << "  > ";
}

void Menu::showTeam() {
    printSeparator();
    std::cout << "  YOUR TEAM\n";
    printSeparator();

    if (player->getTeamSize() == 0) {
        std::cout << "  No Pokemon in team!\n";
        return;
    }

    for (int i = 0; i < player->getTeamSize(); i++) {
        Pokemon* p = player->getPokemon(i);
        std::cout << "  " << i + 1 << ". " << *p << "\n";
        printHpBar(p->getHp(), p->getMaxHp());
    }

    printSeparator();
    std::cout << "  1. Switch active Pokemon\n";
    std::cout << "  2. Forget a move\n";
    std::cout << "  3. Learn a new move\n";
    std::cout << "  4. Heal team\n";
    std::cout << "  5. Release a Pokemon\n";
    std::cout << "  0. Back\n  > ";

    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "  Invalid input! Please enter a number.\n";
        return;
    }
    std::cin.ignore(1000, '\n');

    try {
        switch (choice) {
            case 1:
                switchPokemonMenu();
                break;
            case 2:
                forgetMoveMenu();
                break;
            case 3:
                learnMoveMenu();
                break;
            case 4:
                player->healTeam();
                std::cout << "  Team fully healed! Everyone is ready to fight.\n";
                break;
            case 5:
                removePokemonMenu();
                break;
            case 0:
                return;
            default:
                std::cout << "  Invalid choice. Try again!\n";
                break;
        }
    }
    catch (const std::exception& e) {
        std::cout << "\n  [Operation Failed]: " << e.what() << "\n";
    }
}

void Menu::showPokedex() const {
    printSeparator();
    std::cout << "  POKEDEX\n";
    printSeparator();
    std::cout << *pokedex;
}

void Menu::choosePokemon() {
    if (player->getTeamSize() >= 6) {
        std::cout << "Team is full! Max 6 Pokemon.\n";
        return;
    }

    showPokedex();
    std::cout << "\n  Enter Pokemon name to add: ";
    std::string name;
    std::getline(std::cin, name);

    try {
        Pokemon* p = pokedex->createByName(name);
        player->addPokemon(p);
        std::cout << name << " added to team!\n";
    } catch (std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void Menu::switchPokemonMenu() {
    std::cout << "  Switch to Pokemon (1-" << player->getTeamSize() << "): ";
    int index;
    std::cin >> index;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input!\n";
        return;
    }
    std::cin.ignore(1000, '\n');

    int targetIndex = index - 1;

    try {
        Pokemon* targetPokemon = player->getPokemon(targetIndex);
        if (targetPokemon == player->getActivePokemon()) {
            std::cout << targetPokemon->getName() << " is already out in battle!\n";
            return;
        }
        if (targetPokemon->getHp() <= 0) {
            std::cout << "Cannot switch — " << targetPokemon->getName() << " fainted!\n";
            return;
        }
        if (player->switchPokemon(targetIndex)) {
            std::cout << "Switched to " << targetPokemon->getName() << "!\n";
        }

    } catch (const std::out_of_range& e) {
        std::cout << "Invalid Pokemon index!\n";
    }
}

void Menu::forgetMoveMenu() {
    std::cout << "  Choose Pokemon (1-" << player->getTeamSize() << "): ";
    int pokemonIndex;
    std::cin >> pokemonIndex;
    std::cin.ignore();

    try {
        Pokemon* p = player->getPokemon(pokemonIndex - 1);
        std::cout << "  Moves:\n";
        auto moves = p->getMoves();
        for (int i = 0; i < (int)moves.size(); i++)
            std::cout << "  " << i + 1 << ". " << moves[i]->getName() << "\n";

        std::cout << "  Choose move to forget: ";
        int moveIndex;
        std::cin >> moveIndex;
        std::cin.ignore();

        p->forgetMove(moveIndex - 1);
        std::cout << "Move forgotten!\n";
    } catch (std::out_of_range& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void Menu::learnMoveMenu() {
    if (player->getTeamSize() == 0) {
        std::cout << "You have no Pokemon in your team!\n";
        return;
    }

    std::cout << "  Choose Pokemon to teach a move to (1-" << player->getTeamSize() << "): ";
    int pokemonIndex;
    if (!(std::cin >> pokemonIndex) || pokemonIndex < 1 || pokemonIndex > player->getTeamSize()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Error: Invalid Pokemon selection.\n";
        return;
    }
    std::cin.ignore(1000, '\n');

    try {
        Pokemon* p = player->getPokemon(pokemonIndex - 1);

        if (p->getMoves().size() >= 4) {
            std::cout << "Error: " << p->getName() << " already knows 4 moves!\n";
            return;
        }

        std::cout << "\n=== MOVE TUTOR ===\n";
        std::cout << "Select category:\n1. Physical\n2. Special\n3. Status\n> ";
        int category;
        if (!(std::cin >> category)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Error: Invalid category input.\n";
            return;
        }
        std::cin.ignore(1000, '\n');

        Move* newMove = nullptr;

        if (category == 1 || category == 2) {
            if (category == 1) newMove = new AttackMove();
            else newMove = new SpAttackMove();
            std::cin >> *newMove;
            std::cout << "  Enter Power (Damage): ";
            int pwr;
            if (!(std::cin >> pwr)) {
                delete newMove;
                throw std::invalid_argument("Power must be a number!");
            }
            if (category == 1) {
                auto* phys = dynamic_cast<PhysicalMove*>(newMove);
                if (phys) phys->setPower(pwr);
            } else {
                auto* spec = dynamic_cast<SpAttackMove*>(newMove);
                if (spec) spec->setPower(pwr);
            }

        } else if (category == 3) {
            StatusMove* sm = new StatusMove();
            newMove = sm;
            std::cin >> *newMove;
            std::cout << "  Enter Status Effect (e.g., BURN, SLEEP): ";
            std::string eff;
            std::cin >> eff;
            sm->setEffect(stringToStatus(eff));
            std::cout << "  Enter Duration (Turns): ";
            int dur;
            if (!(std::cin >> dur)) {
                delete newMove;
                throw std::invalid_argument("Duration must be a number!");
            }
            sm->setDuration(dur);
        } else {
            std::cout << "Error: Invalid category selection.\n";
            return;
        }
        p->learnMove(newMove);
        std::cout << "\nSuccess! " << p->getName() << " learned " << newMove->getName() << "!\n";

    } catch (const std::exception& e) {
        std::cout << "System Error: " << e.what() << "\n";
    }
}

void Menu::startBattle() {
    if (player->getTeamSize() == 0) {
        std::cout << "You need at least 1 Pokemon to battle!\n";
        return;
    }
    for (int i = 0; i < player->getTeamSize(); i++) {
        Pokemon* p = player->getPokemon(i);
        if (p->getMoves().empty()) {
            std::cout << "Error: " << p->getName() << " has no moves! Teach it a move before battling.\n";
            return;
        }
    }
    printSeparator();
    std::cout << "  BATTLE MODE\n";
    printSeparator();
    std::cout << "  1. vs Computer (AI)\n";
    std::cout << "  2. vs Player (local PvP)\n";
    std::cout << "  0. Back\n  > ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 0) return;

    delete rival;
    rival = new Trainer("Rival");
    for (int i = 0; i < 3; i++) {
        Pokemon* p = pokedex->getRandomPokemon();
        rival->addPokemon(p);
        assignDefaultMoves(p);
    }

    bool isAI = (choice == 1);
    Battle battle(player, rival, pokedex, 1, isAI);
    battle.start(isAI);

    Trainer* winner = battle.getWinner();
    printSeparator();
    if (winner == player)
        std::cout << "  You won!\n";
    else if (winner == rival)
        std::cout << "  You lost!\n";
    else
        std::cout << "  It's a draw!\n";
    printSeparator();

}

void Menu::showTypeChart() const {
    printSeparator();
    std::cout << "  TYPE CHART\n";
    printSeparator();
    std::cout << *typeChart;
}

void Menu::editTypeChart() {
    printSeparator();
    std::cout << "  EDIT TYPE CHART\n";
    printSeparator();
    try {
        std::cin >> *typeChart;
        std::cout << "Rule updated!\n";
    } catch (std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void Menu::removePokemonMenu() {
    try {
        if (player->getTeamSize() == 0) {
            throw std::runtime_error("Your team is empty! Capture some Pokemon first.");
        }

        std::cout << "\n=== RELEASE POKEMON ===\n";
        for (int i = 0; i < player->getTeamSize(); i++) {
            std::cout << i + 1 << ". " << player->getPokemon(i)->getName() << "\n";
        }

        std::cout << "Select (1-" << player->getTeamSize() << ") or 0 to Cancel: ";
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            throw std::invalid_argument("Input must be a numeric value!");
        }

        if (choice == 0) return;
        player->removePokemon(choice - 1);

        std::cout << "Pokemon successfully released.\n";

    }
    catch (const std::out_of_range& e) {
        std::cout << "[Index Error]: " << e.what() << "\n";
    }
    catch (const std::invalid_argument& e) {
        std::cout << "[Input Error]: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "[System Error]: " << e.what() << "\n";
    }
}


void Menu::assignDefaultMoves(Pokemon* p) {
    Type t = p->getType();

    AttackMove* physMove = new AttackMove(
        typeToString(t) + " Tackle", 80, 90,t,15, 15);

    SpAttackMove* specMove = new SpAttackMove(
        typeToString(t) + " Blast",  65, 95, t, 10,10);
    p->learnMove(physMove);
    p->learnMove(specMove);
}

void Menu::initGame() {
    try {
        player->loadFromFile("save.txt", *pokedex);
        std::cout << "Welcome back, " << player->getName() << "!\n";
    }
    catch (const std::exception& e) {
        std::cout << "\n[NEW ADVENTURE] No valid save found.\n";
        std::string n;
        std::cout << "What is your name, Trainer? ";
        std::getline(std::cin >> std::ws, n);
        player->setName(n);
        std::cout << "Welcome, " << n << "! It's time to choose your first Pokemon:\n";
        this->choosePokemon();
        std::cout << "\nPerfect! Your journey begins now.\n";
    }
}