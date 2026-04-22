#include "Pokemon.h"
#include "GrassPokemon.h"

GrassPokemon::GrassPokemon() : Pokemon() {}
GrassPokemon::GrassPokemon(std::string name) : Pokemon(name) {}
GrassPokemon::GrassPokemon(std::string name, int hp) : Pokemon(name, hp) {}
GrassPokemon::GrassPokemon(std::string name, int hp, int maxHp) : Pokemon(name, hp, maxHp) {}
GrassPokemon::GrassPokemon(std::string name, int hp, int maxHp, int attack) : Pokemon(name, hp, maxHp, attack) {}
GrassPokemon::GrassPokemon(std::string name, int hp, int maxHp, int attack, int defense) : Pokemon(name, hp, maxHp, attack, defense) {}
GrassPokemon::GrassPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack) : Pokemon(name, hp, maxHp, attack, defense, spAttack) {}
GrassPokemon::GrassPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense) {}
GrassPokemon::GrassPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed) {}
GrassPokemon::GrassPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level) {}
GrassPokemon::GrassPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel) {}
GrassPokemon::GrassPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel, evolutionName) {}

GrassPokemon::GrassPokemon(std::string name, int hp, int maxHp, int attack, int defense,
                           int spAttack, int spDefense, int speed, int level, int evLevel,
                           std::string evolutionName, StatusType status)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status) {}

GrassPokemon::GrassPokemon(std::string name, int hp, int maxHp, int attack, int defense,
                           int spAttack, int spDefense, int speed, int level, int evLevel,
                           std::string evolutionName, StatusType status, int statusDuration)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status, statusDuration) {}

GrassPokemon::GrassPokemon(const GrassPokemon &obj) : Pokemon(obj) {}

GrassPokemon& GrassPokemon::operator=(const GrassPokemon& obj) {
    if (this != &obj) { Pokemon::operator=(obj); }
    return *this;
}

GrassPokemon::~GrassPokemon() {}

Type GrassPokemon::getType() const {
    return GRASS;
}

Pokemon* GrassPokemon::evolve() {
}