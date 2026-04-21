#pragma once
#include "Pokemon.h"

class ElectricPokemon : public virtual Pokemon {
public:
    ElectricPokemon();
    ElectricPokemon(std::string);
    ElectricPokemon(std::string, int);
    ElectricPokemon(std::string, int, int);
    ElectricPokemon(std::string, int, int, int);
    ElectricPokemon(std::string, int, int, int, int);
    ElectricPokemon(std::string, int, int, int, int, int);
    ElectricPokemon(std::string, int, int, int, int, int, int);
    ElectricPokemon(std::string, int, int, int, int, int, int, int);
    ElectricPokemon(std::string, int, int, int, int, int, int, int, int);
    ElectricPokemon(std::string, int, int, int, int, int, int, int, int, int);
    ElectricPokemon(std::string, int, int, int, int, int, int, int, int, int, std::string);

    ElectricPokemon(const ElectricPokemon &obj);
    ElectricPokemon& operator=(const ElectricPokemon &obj);
    ~ElectricPokemon();

    Type getType() const override;
    Pokemon* evolve() override;
};