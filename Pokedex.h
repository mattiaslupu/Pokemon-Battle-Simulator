#pragma once
#include "Pokemon.h"
#include <fstream>
#include <sstream>
#include <iostream>

class Pokedex {
private:
    std::vector<Pokemon* > entries;
public:
    Pokedex();
    Pokedex(std::vector<Pokemon*>);
    ~Pokedex();
    Pokedex(const Pokedex& other);
    Pokedex& operator=(const Pokedex& other);
    void loadFromFile(const std::string& filename);
    Pokemon* createByName(const std::string& name) const;
    friend std::ostream& operator<<(std::ostream& os, const Pokedex& obj);
    friend std::istream& operator>>(std::istream& is, Pokedex& obj);

};