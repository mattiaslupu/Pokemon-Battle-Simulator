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
    FireFlyingPokemon(const FireFlyingPokemon &obj);
    FireFlyingPokemon& operator=(const FireFlyingPokemon &obj);
    ~FireFlyingPokemon();
    Type getType() const override;
    Pokemon* evolve() override;
};