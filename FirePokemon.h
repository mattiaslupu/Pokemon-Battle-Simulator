#pragma once
#include "Pokemon.h"

class FirePokemon : public virtual Pokemon{
public:
    FirePokemon();
    FirePokemon(std::string);
    FirePokemon(std::string, int);
    FirePokemon(std::string, int, int);
    FirePokemon(std::string, int, int, int);
    FirePokemon(std::string, int, int, int, int);
    FirePokemon(std::string, int, int, int, int, int);
    FirePokemon(std::string, int, int, int, int, int, int);
    FirePokemon(std::string, int, int, int, int, int, int, int);
    FirePokemon(std::string, int, int, int, int, int, int, int, int);
    FirePokemon(std::string, int, int, int, int, int, int, int, int, int);
    FirePokemon(std::string, int, int, int, int, int, int, int, int, int, std::string);
    FirePokemon(std::string, int, int, int, int, int, int, int, int, int, std::string, StatusType);
    FirePokemon(std::string, int, int, int, int, int, int, int, int, int, std::string, StatusType, int);
    FirePokemon(const FirePokemon &obj);
    FirePokemon& operator=(const FirePokemon &obj);
    ~FirePokemon() override;
    Type getType() const override;
};


