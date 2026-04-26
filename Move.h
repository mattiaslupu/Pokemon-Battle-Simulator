#pragma once
#include "utils.h"
#include <iostream>
#include <string>



class Pokemon;
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
    Type getType() const;
    MoveCategory getCategory() const;
    Move& operator=(const Move &obj);
    friend std::istream& operator>>(std::istream &is, Move& obj);
    friend std::ostream& operator<<(std::ostream &os, const Move & obj);
    std::string getName() const;
    void useMove();
    void restorePP();
    virtual int getDamage(const Pokemon& attacker, const Pokemon& defender) const = 0;
    virtual void applyEffect(Pokemon& target) = 0;
    virtual void save(std::ostream& out) const = 0;
    void setName(const std::string& n) { name = n; }
    void setType(Type t) { type = t; }
    void setAccuracy(int acc) {
        if(acc < 0 || acc > 100) throw std::invalid_argument("Accuracy must be 0-100");
        accuracy = acc;
    }
    void setPP(int pp) {
        if(pp < 0) throw std::invalid_argument("PP cannot be negative");
        this->pp=pp;
    }

    void setMaxPP(int pp) {
        if(pp < 0) throw std::invalid_argument("PP cannot be negative");
        this->maxPp=pp;
    }



};