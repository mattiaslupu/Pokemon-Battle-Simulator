#include "Pokemon.h"
#include "FlyingPokemon.h"

FlyingPokemon::FlyingPokemon() : Pokemon() {}
FlyingPokemon::FlyingPokemon(std::string name) : Pokemon(name) {}
FlyingPokemon::FlyingPokemon(std::string name, int hp) : Pokemon(name, hp) {}
FlyingPokemon::FlyingPokemon(std::string name, int hp, int maxHp) : Pokemon(name, hp, maxHp) {}
FlyingPokemon::FlyingPokemon(std::string name, int hp, int maxHp, int attack) : Pokemon(name, hp, maxHp, attack) {}
FlyingPokemon::FlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense) : Pokemon(name, hp, maxHp, attack, defense) {}
FlyingPokemon::FlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack) : Pokemon(name, hp, maxHp, attack, defense, spAttack) {}
FlyingPokemon::FlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense) {}
FlyingPokemon::FlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed) {}
FlyingPokemon::FlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level) {}
FlyingPokemon::FlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel) {}
FlyingPokemon::FlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel, evolutionName) {}
FlyingPokemon::FlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense,
                             int spAttack, int spDefense, int speed, int level, int evLevel,
                             std::string evolutionName, StatusType status)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status) {}

FlyingPokemon::FlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense,
                             int spAttack, int spDefense, int speed, int level, int evLevel,
                             std::string evolutionName, StatusType status, int statusDuration)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status, statusDuration) {}
FlyingPokemon::FlyingPokemon(const FlyingPokemon &obj) : Pokemon(obj) {}

FlyingPokemon& FlyingPokemon::operator=(const FlyingPokemon& obj) {
    if (this != &obj) { Pokemon::operator=(obj); }
    return *this;
}

FlyingPokemon::~FlyingPokemon() {}

Type FlyingPokemon::getType() const {
    return FLYING;
}

Pokemon* FlyingPokemon::evolve() {

}