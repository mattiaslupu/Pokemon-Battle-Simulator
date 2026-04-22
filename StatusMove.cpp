#include "StatusMove.h"

StatusMove::StatusMove() : Move(), effect(NONE), duration(0) {
    this->category = STATUS;
}

StatusMove::StatusMove(std::string name) : Move(name), effect(NONE), duration(0) {
    this->category = STATUS;
}


StatusMove::StatusMove(std::string name, int accuracy) : Move(name, accuracy), effect(NONE), duration(0) {
    this->category = STATUS;
}


StatusMove::StatusMove(std::string name, int accuracy, int pp) : Move(name, accuracy, NORMAL, pp), effect(NONE), duration(0) {
    this->category = STATUS;
}

StatusMove::StatusMove(std::string name, int accuracy, int pp, Type type) : Move(name, accuracy, type, pp), effect(NONE), duration(0) {
    this->category = STATUS;
}


StatusMove::StatusMove(std::string name, int accuracy, int pp, Type type, StatusType effect, int duration)
    : Move(name, accuracy, type, pp, pp, STATUS) {
    this->effect = effect;
    this->duration = duration;
}

StatusMove::StatusMove(const StatusMove &obj) : Move(obj) {
    this->effect = obj.effect;
    this->duration = obj.duration;
}

StatusMove::~StatusMove() {}

StatusMove &StatusMove::operator=(const StatusMove &obj) {
    if (this != &obj) {
        Move::operator=(obj);
        this->effect = obj.effect;
        this->duration = obj.duration;
    }
    return *this;
}


int StatusMove::getDamage(const Pokemon& attacker, const Pokemon& defender) const {
    return 0;
}

void StatusMove::applyEffect(Pokemon& target) {
    target.applyStatus(this->effect, this->duration);
}
