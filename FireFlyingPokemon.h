#pragma once
#include "FirePokemon.h"
#include "FlyingPokemon.h"

class FireFlyingPokemon : public FirePokemon, public FlyingPokemon {
public:
    FireFlyingPokemon();
    FireFlyingPokemon(std::string);
    FireFlyingPokemon(std::string, int);
    FireFlyingPokemon(std::string, int, int);
    FireFlyingPokemon(std::string, int, int, int);
    FireFlyingPokemon(std::string, int, int, int, int);
    FireFlyingPokemon(std::string, int, int, int, int, int);
    FireFlyingPokemon(std::string, int, int, int, int, int, int);
    FireFlyingPokemon(std::string, int, int, int, int, int, int, int);
    FireFlyingPokemon(std::string, int, int, int, int, int, int, int, int);
    FireFlyingPokemon(std::string, int, int, int, int, int, int, int, int, int);
    FireFlyingPokemon(std::string, int, int, int, int, int, int, int, int, int, std::string);
    FireFlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName, StatusType status);
    FireFlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName, StatusType status, int statusDuration);
    FireFlyingPokemon(const FireFlyingPokemon &obj);
    FireFlyingPokemon& operator=(const FireFlyingPokemon &obj);
    ~FireFlyingPokemon();
    Type getType() const override;
    Pokemon* evolve() override;
};