#pragma once
#include "Pokemon.h"

class IcePokemon : public virtual Pokemon {
public:
    IcePokemon();
    IcePokemon(std::string);
    IcePokemon(std::string, int);
    IcePokemon(std::string, int, int);
    IcePokemon(std::string, int, int, int);
    IcePokemon(std::string, int, int, int, int);
    IcePokemon(std::string, int, int, int, int, int);
    IcePokemon(std::string, int, int, int, int, int, int);
    IcePokemon(std::string, int, int, int, int, int, int, int);
    IcePokemon(std::string, int, int, int, int, int, int, int, int);
    IcePokemon(std::string, int, int, int, int, int, int, int, int, int);
    IcePokemon(std::string, int, int, int, int, int, int, int, int, int, std::string);

    IcePokemon(const IcePokemon &obj);
    IcePokemon& operator=(const IcePokemon &obj);
    ~IcePokemon();

    Type getType() const override;
    Pokemon* evolve() override;
};