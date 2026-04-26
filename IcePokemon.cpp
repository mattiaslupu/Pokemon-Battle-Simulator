#include "Pokemon.h"
#include "IcePokemon.h"

IcePokemon::IcePokemon() : Pokemon() {}
IcePokemon::IcePokemon(std::string name) : Pokemon(name) {}
IcePokemon::IcePokemon(std::string name, int hp) : Pokemon(name, hp) {}
IcePokemon::IcePokemon(std::string name, int hp, int maxHp) : Pokemon(name, hp, maxHp) {}
IcePokemon::IcePokemon(std::string name, int hp, int maxHp, int attack) : Pokemon(name, hp, maxHp, attack) {}
IcePokemon::IcePokemon(std::string name, int hp, int maxHp, int attack, int defense) : Pokemon(name, hp, maxHp, attack, defense) {}
IcePokemon::IcePokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack) : Pokemon(name, hp, maxHp, attack, defense, spAttack) {}
IcePokemon::IcePokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense) {}
IcePokemon::IcePokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed) {}
IcePokemon::IcePokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level) {}
IcePokemon::IcePokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel) {}
IcePokemon::IcePokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel, evolutionName) {}
IcePokemon::IcePokemon(std::string name, int hp, int maxHp, int attack, int defense,
                       int spAttack, int spDefense, int speed, int level, int evLevel,
                       std::string evolutionName, StatusType status)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status) {}

IcePokemon::IcePokemon(std::string name, int hp, int maxHp, int attack, int defense,
                       int spAttack, int spDefense, int speed, int level, int evLevel,
                       std::string evolutionName, StatusType status, int statusDuration)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status, statusDuration) {}
IcePokemon::IcePokemon(const IcePokemon &obj) : Pokemon(obj) {}

IcePokemon& IcePokemon::operator=(const IcePokemon& obj) {
    if (this != &obj) { Pokemon::operator=(obj); }
    return *this;
}

IcePokemon::~IcePokemon() {}

Type IcePokemon::getType() const {
    return ICE;
}

