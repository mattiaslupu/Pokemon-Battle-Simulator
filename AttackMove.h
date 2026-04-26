#pragma once
#include "PhysicalMove.h"

class AttackMove : public PhysicalMove{
public:
    AttackMove();
    AttackMove(std::string);
    AttackMove(std::string, int);
    AttackMove(std::string, int, int);
    AttackMove(std::string, int, int, Type);
    AttackMove(std::string, int, int,Type, int);
    AttackMove(std::string, int, int, Type, int, int);
    AttackMove(std::string, int, int, Type, int, int, MoveCategory);
    AttackMove(const AttackMove &obj);
    ~AttackMove() override;
    AttackMove& operator=(const AttackMove &obj);
    int getDamage(const Pokemon& attacker, const Pokemon& defender) const override;
    void save(std::ostream& out) const;
};



