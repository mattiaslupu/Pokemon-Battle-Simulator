#pragma once

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
    FirePokemon(const FirePokemon &obj);
    FirePokemon& operator=(const FirePokemon &obj);
    ~FirePokemon();
    Type getType() const override;
    Pokemon* evolve() override;
};


