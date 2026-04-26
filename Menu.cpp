#include "Menu.h"
#include "utils.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

Menu::Menu() {
    pokedex = new Pokedex();
    pokedex->loadFromFile("pokemon.txt");
    typeChart = new TypeChart();


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

    std::cout << "Enter your trainer name: ";
    std::string name;
    std::getline(std::cin, name);
    if (!name.empty()) {
        player->setName(name);
    } else {
        player->setName("Ash");
    }

    bool ok = true;
    while (ok) {
        showMainMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        try {
            switch (choice) {
                case 1: choosePokemon();    break;
                case 2: showTeam();         break;
                case 3: showPokedex();      break;
                case 4: startBattle();      break;
                case 5: showTypeChart();    break;
                case 6: editTypeChart();    break;
                case 0: ok = false;         break;
                default:
                    std::cout << "Invalid option. Try again.\n";
            }
        } catch (std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
        } catch (std::out_of_range& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
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
    std::cout << "  3. Heal team\n";
    std::cout << "  0. Back\n  > ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
        case 1: switchPokemonMenu(); break;
        case 2: forgetMoveMenu();    break;
        case 3:
            std::cout << "Team fully healed!\n";
            break;
        default: break;
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
    std::cin.ignore();

    if (!player->switchPokemon(index - 1))
        std::cout << "Cannot switch — Pokemon fainted!\n";
    else
        std::cout << "Switched to " << player->getActivePokemon()->getName() << "!\n";
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

void Menu::startBattle() {
    if (player->getTeamSize() == 0) {
        std::cout << "You need at least 1 Pokemon to battle!\n";
        return;
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