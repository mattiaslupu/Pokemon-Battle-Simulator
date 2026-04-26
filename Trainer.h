#pragma once
#include "Pokemon.h"
#include <fstream>

class Pokemon;

class Trainer {
private:
    const int id;
    static int noTrainers;
    std::string name;
    std::vector<Pokemon*>team;
    int activePokemonIndex;
public:
    Trainer();
    Trainer(std::string);
    Trainer(std::string, int);
    Trainer(const Trainer & obj);
    ~Trainer();
    void setName(std::string);
    Trainer& operator=(const Trainer& obj);
    friend std::istream& operator>>(std::istream&is, Trainer &obj);
    friend std::ostream& operator<<(std::ostream&os, const Trainer &obj);
    std::string getName();
    void addPokemon(Pokemon *);
    Pokemon* getActivePokemon();
    void replacePokemon(int, Pokemon*);
    Pokemon* getPokemon(int);
    bool switchPokemon(int);
    bool hasAlivePokemon();
    void healTeam();
    void healPokemon(int);
    int getTeamSize();
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename, Pokedex& pokedex);
};


