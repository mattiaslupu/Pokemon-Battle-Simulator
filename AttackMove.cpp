#include "AttackMove.h"
#include "Pokemon.h"

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
    double damage = ((2.0 * attacker.getLevel() / 5.0 + 2)
                     * this->power
                     * (double)attacker.getAttack() / defender.getDefense())
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

void AttackMove::save(std::ostream& out) const {
    out << "PHYSICAL," << name << "," << static_cast<int>(type) << ","
        << accuracy << "," << maxPp << "," << power << "\n";
}
