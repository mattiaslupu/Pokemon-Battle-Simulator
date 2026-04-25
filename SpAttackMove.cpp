
#include "SpAttackMove.h"


SpAttackMove::SpAttackMove() : PhysicalMove() {}

SpAttackMove::SpAttackMove(std::string name) : PhysicalMove(name) {}

SpAttackMove::SpAttackMove(std::string name, int power) : PhysicalMove(name, power) {}

SpAttackMove::SpAttackMove(std::string name, int power, int accuracy) : PhysicalMove(name, power, accuracy) {}

SpAttackMove::SpAttackMove(std::string name, int power, int accuracy, Type type) : PhysicalMove(name, power, accuracy, type) {}

SpAttackMove::SpAttackMove(std::string name, int power, int accuracy, Type type, int pp) : PhysicalMove(name, power, accuracy, type, pp) {}

SpAttackMove::SpAttackMove(std::string name, int power, int accuracy, Type type, int pp, int maxPp) : PhysicalMove(name, power, accuracy, type, pp, maxPp, PHYSICAL) {}

SpAttackMove::SpAttackMove(const SpAttackMove &obj) : PhysicalMove(obj) {}

SpAttackMove &SpAttackMove::operator=(const SpAttackMove &obj) {
    if (this != &obj) {
        PhysicalMove::operator=(obj);
    }
    return *this;
}


SpAttackMove::~SpAttackMove() {}


int SpAttackMove::getDamage(const Pokemon& attacker, const Pokemon& defender) const {
    double damage = ((2.0 * attacker.getLevel() / 5.0 + 2)
                    * this->power
                    * (double)attacker.getSpAttack() / defender.getSpDefense())
                    / 50.0 + 2;
    double stab = 1.0;
    if (this->type == attacker.getType()) {
        stab = 1.5;
    } else if (attacker.getType() == FIRE_FLYING && (this->type == FIRE || this->type == FLYING)) {
        stab = 1.5;
    }

    double totalDamage = damage * stab;
    return std::max(1, (int)totalDamage);
}
