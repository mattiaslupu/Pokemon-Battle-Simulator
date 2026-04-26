#include "Pokemon.h"
#include "RockPokemon.h"

RockPokemon::RockPokemon() : Pokemon() {}
RockPokemon::RockPokemon(std::string name) : Pokemon(name) {}
RockPokemon::RockPokemon(std::string name, int hp) : Pokemon(name, hp) {}
RockPokemon::RockPokemon(std::string name, int hp, int maxHp) : Pokemon(name, hp, maxHp) {}
RockPokemon::RockPokemon(std::string name, int hp, int maxHp, int attack) : Pokemon(name, hp, maxHp, attack) {}
RockPokemon::RockPokemon(std::string name, int hp, int maxHp, int attack, int defense) : Pokemon(name, hp, maxHp, attack, defense) {}
RockPokemon::RockPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack) : Pokemon(name, hp, maxHp, attack, defense, spAttack) {}
RockPokemon::RockPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense) {}
RockPokemon::RockPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed) {}
RockPokemon::RockPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level) {}
RockPokemon::RockPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel) {}
RockPokemon::RockPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel, evolutionName) {}
RockPokemon::RockPokemon(std::string name, int hp, int maxHp, int attack, int defense,
                         int spAttack, int spDefense, int speed, int level, int evLevel,
                         std::string evolutionName, StatusType status)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status) {}

RockPokemon::RockPokemon(std::string name, int hp, int maxHp, int attack, int defense,
                         int spAttack, int spDefense, int speed, int level, int evLevel,
                         std::string evolutionName, StatusType status, int statusDuration)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status, statusDuration) {}
RockPokemon::RockPokemon(const RockPokemon &obj) : Pokemon(obj) {}

RockPokemon& RockPokemon::operator=(const RockPokemon& obj) {
    if (this != &obj) { Pokemon::operator=(obj); }
    return *this;
}

RockPokemon::~RockPokemon() {}

Type RockPokemon::getType() const {
    return ROCK;
}

