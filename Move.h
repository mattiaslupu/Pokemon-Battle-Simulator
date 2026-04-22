#pragma once
#include "Pokemon.h"
#include <iostream>
#include <string>

enum MoveCategory { PHYSICAL, SPECIAL, STATUS };
enum StatusType { NONE, BURN, SLEEP, PARALYSIS, POISON };

class Move {
protected:
    const int id;
    static int noMoves;
    std::string name;
    int accuracy;
    Type type;
    int pp;
    int maxPp;
    MoveCategory category;
public:
    Move();
    Move(std::string);
    Move(std::string, int);
    Move(std::string, int, Type);
    Move(std::string, int, Type, int);
    Move(std::string, int, Type, int, int);
    Move(std::string, int, Type, int, int, MoveCategory);
    Move(const Move &obj);
    virtual ~Move();
    MoveCategory getCategory() const;
    Move& operator=(const Move &obj);
    friend std::istream& operator<<(std::istream &is, Move& obj);
    friend std::ostream& operator>>(std::ostream &os, const Move & obj);
    void useMove();
    void restorePP();
    virtual int getDamage(const Pokemon& attacker, const Pokemon& defender) const = 0;
    virtual void applyEffect(Pokemon& target) = 0;

};