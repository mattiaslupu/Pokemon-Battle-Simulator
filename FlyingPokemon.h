#pragma once
#include "Pokemon.h"

class FlyingPokemon : public virtual Pokemon {
public:
    FlyingPokemon();
    FlyingPokemon(std::string);
    FlyingPokemon(std::string, int);
    FlyingPokemon(std::string, int, int);
    FlyingPokemon(std::string, int, int, int);
    FlyingPokemon(std::string, int, int, int, int);
    FlyingPokemon(std::string, int, int, int, int, int);
    FlyingPokemon(std::string, int, int, int, int, int, int);
    FlyingPokemon(std::string, int, int, int, int, int, int, int);
    FlyingPokemon(std::string, int, int, int, int, int, int, int, int);
    FlyingPokemon(std::string, int, int, int, int, int, int, int, int, int);
    FlyingPokemon(std::string, int, int, int, int, int, int, int, int, int, std::string);

    FlyingPokemon(const FlyingPokemon &obj);
    FlyingPokemon& operator=(const FlyingPokemon &obj);
    ~FlyingPokemon();

    Type getType() const override;
    Pokemon* evolve() override;
};