#pragma once
#include "Move.h"
#include <iostream>
#include <string>

class PhysicalMove : public Move {
protected:
    int power;
public:
    PhysicalMove();
    PhysicalMove(std::string);
    PhysicalMove(std::string, int);
    PhysicalMove(std::string, int, int);
    PhysicalMove(std::string, int, int, Type);
    PhysicalMove(std::string, int, int,Type, int);
    PhysicalMove(std::string, int, int, Type, int, int);
    PhysicalMove(std::string, int, int, Type, int, int, MoveCategory);
    PhysicalMove(const PhysicalMove &obj);
    ~PhysicalMove() override;
    PhysicalMove& operator=(const PhysicalMove &obj);
    virtual int getDamage(const Pokemon& attacker, const Pokemon& defender) const = 0 ;
    void applyEffect(Pokemon& target) override;
};


