#pragma once
#include "Pokemon.h"
#include <vector>
#include <string>

class WaterPokemon : public virtual Pokemon {
public:
    WaterPokemon();
    WaterPokemon(std::string);
    WaterPokemon(std::string, int);
    WaterPokemon(std::string, int, int);
    WaterPokemon(std::string, int, int, int);
    WaterPokemon(std::string, int, int, int, int);
    WaterPokemon(std::string, int, int, int, int, int);
    WaterPokemon(std::string, int, int, int, int, int, int);
    WaterPokemon(std::string, int, int, int, int, int, int, int);
    WaterPokemon(std::string, int, int, int, int, int, int, int, int);
    WaterPokemon(std::string, int, int, int, int, int, int, int, int, int);
    WaterPokemon(std::string, int, int, int, int, int, int, int, int, int, std::string);
    WaterPokemon(std::string, int, int, int, int, int, int, int, int, int, std::string, std::vector<Move*>);
    WaterPokemon(const WaterPokemon &obj);
    WaterPokemon& operator=(const WaterPokemon &obj);
    ~WaterPokemon();
    Type getType() const override;
    Pokemon* evolve() override;
};