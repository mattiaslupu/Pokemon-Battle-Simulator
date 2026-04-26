#pragma once
#include "Pokemon.h"

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
    WaterPokemon(std::string, int, int, int, int, int, int, int, int, int, std::string, StatusType);
    WaterPokemon(std::string, int, int, int, int, int, int, int, int, int, std::string, StatusType, int);
    WaterPokemon(const WaterPokemon &obj);
    WaterPokemon& operator=(const WaterPokemon &obj);
    ~WaterPokemon();
    Type getType() const override;
};