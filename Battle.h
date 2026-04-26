#pragma once
#include "Pokemon.h"
#include "Trainer.h"
#include "TypeChart.h"
#include "Pokedex.h"
#include <iostream>

class Battle {
private:
    Trainer* player1;
    Trainer* player2;
    TypeChart typeChart;
    Pokedex* pokedex;
    int turnCount;
    bool isVsAI;
    void applyDamage(Pokemon* attacker, Pokemon* defender, Move*);
    void playTurn();
    void checkFaint(Trainer* attacker, Trainer* defender);
    void handlePostBattleRewards(Trainer* winner);
    Move* getMoveFromPlayer(Trainer* player);

public:
    Battle();
    Battle(Trainer* );
    Battle(Trainer* , Trainer*);
    Battle(Trainer* , Trainer* , Pokedex* );
    Battle(Trainer* , Trainer* , Pokedex* , int);
    Battle(Trainer* , Trainer* , Pokedex* , int, bool);
    Battle(const Battle & obj);
    ~Battle();
    Battle & operator=(const Battle & obj);
    friend std::istream& operator>>(std::istream& is, Battle & obj);
    friend std::ostream& operator<<(std::ostream& os, const Battle & obj);
    void start(bool);
    bool isOver() const;
    Trainer* getWinner() const;
    Move* chooseBestMoveAI(Trainer* computer, Pokemon* target);
};
