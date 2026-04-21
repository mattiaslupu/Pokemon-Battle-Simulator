#pragma once
#include "Pokemon.h"

class RockPokemon : public virtual Pokemon {
public:
    RockPokemon();
    RockPokemon(std::string);
    RockPokemon(std::string, int);
    RockPokemon(std::string, int, int);
    RockPokemon(std::string, int, int, int);
    RockPokemon(std::string, int, int, int, int);
    RockPokemon(std::string, int, int, int, int, int);
    RockPokemon(std::string, int, int, int, int, int, int);
    RockPokemon(std::string, int, int, int, int, int, int, int);
    RockPokemon(std::string, int, int, int, int, int, int, int, int);
    RockPokemon(std::string, int, int, int, int, int, int, int, int, int);
    RockPokemon(std::string, int, int, int, int, int, int, int, int, int, std::string);
    RockPokemon(const RockPokemon &obj);
    RockPokemon& operator=(const RockPokemon &obj);
    ~RockPokemon();
    Type getType() const override;
    Pokemon* evolve() override;
};