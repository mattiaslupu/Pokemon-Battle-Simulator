#pragma once
#include "Move.h"
#include <iostream>
#include <string>



class StatusMove : public Move {
protected:
    StatusType effect;
    int duration;

public:
    StatusMove();
    StatusMove(std::string name);
    StatusMove(std::string name, int accuracy);
    StatusMove(std::string name, int accuracy, int pp);
    StatusMove(std::string name, int accuracy, int pp, Type type);
    StatusMove(std::string name, int accuracy, int pp, Type type, StatusType effect, int duration);

    StatusMove(const StatusMove &obj);
    ~StatusMove();
    StatusMove& operator=(const StatusMove &obj);

    int getDamage(const Pokemon& attacker, const Pokemon& defender) const override;

    void applyEffect(Pokemon& target) override;

    StatusType getEffect() const { return effect; }
};