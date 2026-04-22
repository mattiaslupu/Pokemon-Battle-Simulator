#pragma once
#include "PhysicalMove.h"
class SpAttackMove : public PhysicalMove{
    SpAttackMove();
    SpAttackMove(std::string);
    SpAttackMove(std::string, int);
    SpAttackMove(std::string, int, int);
    SpAttackMove(std::string, int, int, Type);
    SpAttackMove(std::string, int, int,Type, int);
    SpAttackMove(std::string, int, int, Type, int, int);
    SpAttackMove(std::string, int, int, Type, int, int, MoveCategory);
    SpAttackMove(const SpAttackMove &obj);
    ~SpAttackMove() override;
    SpAttackMove& operator=(const SpAttackMove &obj);
    int getDamage(const Pokemon& attacker, const Pokemon& defender) const override;
};

