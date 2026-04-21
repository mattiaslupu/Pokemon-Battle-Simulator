#pragma once
#include "Pokemon.h"
class GrassPokemon : public virtual Pokemon {
public:
    GrassPokemon();
    GrassPokemon(std::string);
    GrassPokemon(std::string, int);
    GrassPokemon(std::string, int, int);
    GrassPokemon(std::string, int, int, int);
    GrassPokemon(std::string, int, int, int, int);
    GrassPokemon(std::string, int, int, int, int, int);
    GrassPokemon(std::string, int, int, int, int, int, int);
    GrassPokemon(std::string, int, int, int, int, int, int, int);
    GrassPokemon(std::string, int, int, int, int, int, int, int, int);
    GrassPokemon(std::string, int, int, int, int, int, int, int, int, int);
    GrassPokemon(std::string, int, int, int, int, int, int, int, int, int, std::string);
    GrassPokemon(const GrassPokemon &obj);
    GrassPokemon& operator=(const GrassPokemon &obj);
    ~GrassPokemon();
    Type getType() const override;
    Pokemon* evolve() override;
};