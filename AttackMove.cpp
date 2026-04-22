#include "AttackMove.h"

AttackMove::AttackMove() : PhysicalMove() {}

AttackMove::AttackMove(std::string name) : PhysicalMove(name) {}

AttackMove::AttackMove(std::string name, int power) : PhysicalMove(name, power) {}

AttackMove::AttackMove(std::string name, int power, int accuracy) : PhysicalMove(name, power, accuracy) {}

AttackMove::AttackMove(std::string name, int power, int accuracy, Type type) : PhysicalMove(name, power, accuracy, type) {}

AttackMove::AttackMove(std::string name, int power, int accuracy, Type type, int pp) : PhysicalMove(name, power, accuracy, type, pp) {}

AttackMove::AttackMove(std::string name, int power, int accuracy, Type type, int pp, int maxPp) : PhysicalMove(name, power, accuracy, type, pp, maxPp, PHYSICAL) {}

AttackMove::AttackMove(const AttackMove &obj) : PhysicalMove(obj) {}

AttackMove &AttackMove::operator=(const AttackMove &obj) {
    if (this != &obj) {
        PhysicalMove::operator=(obj);
    }
    return *this;
}


AttackMove::~AttackMove() {}


int AttackMove::getDamage(const Pokemon& attacker, const Pokemon& defender) const {
   ///To DO
}

