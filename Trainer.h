#pragma once
#include "Pokemon.h"

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
    Trainer& operator=(const Trainer& obj);
    friend std::istream& operator>>(std::istream&is, Trainer &obj);
    friend std::ostream& operator<<(std::ostream&os, const Trainer &obj);
    void addPokemon(Pokemon *);
    Pokemon* getActivePokemon();
    bool switchPokemon(int);
    bool hasAlivePokemon();
    void healTeam();
    void healPokemon(int);
    int getTeamSize();



};


