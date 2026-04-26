
#include "PhysicalMove.h"
#include "Pokemon.h"

PhysicalMove::PhysicalMove() : Move(), power(0){}

PhysicalMove::PhysicalMove(std::string name) : Move(name), power(0){}

PhysicalMove::PhysicalMove(std::string name, int power) : Move(name) {
    this->power=power;
}


PhysicalMove::PhysicalMove(std::string name, int power, int accuracy) : Move(name, accuracy) {
    this->power=power;
}

PhysicalMove::PhysicalMove(std::string name, int power, int accuracy, Type type) : Move(name, accuracy, type) {
    this->power=power;
}

PhysicalMove::PhysicalMove(std::string name, int power, int accuracy, Type type, int pp) : Move(name, accuracy, type, pp) {
    this->power=power;
}

PhysicalMove::PhysicalMove(std::string name, int power, int accuracy, Type type, int pp, int maxPp) : Move(name, accuracy, type, pp, maxPp) {
    this->power=power;
}

PhysicalMove::PhysicalMove(std::string name, int power, int accuracy, Type type, int pp, int maxPp, MoveCategory category) : Move(name, accuracy, type, pp, maxPp, category) {
    this->power=power;
}

PhysicalMove::PhysicalMove(const PhysicalMove &obj) : Move(obj), power(obj.power){}

PhysicalMove &PhysicalMove::operator=(const PhysicalMove &obj) {
    if (this!=&obj) Move::operator=(obj);
    return *this;
}

PhysicalMove::~PhysicalMove() {}

void PhysicalMove::applyEffect(Pokemon& target){}

void PhysicalMove::setPower(int p) {
    if (p < 0) this->power = 0;
    else this->power = p;
}
