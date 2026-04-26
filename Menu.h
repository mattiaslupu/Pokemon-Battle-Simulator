#pragma once

#include "Trainer.h"
#include "Pokedex.h"
#include "Battle.h"
#include "TypeChart.h"
#include <iostream>
#include <string>

class Menu {
private:
    Pokedex* pokedex;
    TypeChart* typeChart;
    Trainer* player;
    Trainer* rival;

    void printSeparator() const;
    void printHpBar(int hp, int maxHp) const;

    void showMainMenu() const;
    void showTeam();
    void showPokedex() const;
    void choosePokemon();
    void switchPokemonMenu();
    void forgetMoveMenu();
    void startBattle();
    void showTypeChart() const;
    void editTypeChart();

public:
    Menu();
    ~Menu();

    void run();
};
