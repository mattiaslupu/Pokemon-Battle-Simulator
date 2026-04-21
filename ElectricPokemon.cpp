#include "Pokemon.h"
#include "ElectricPokemon.h"

ElectricPokemon::ElectricPokemon() : Pokemon() {}
ElectricPokemon::ElectricPokemon(std::string name) : Pokemon(name) {}
ElectricPokemon::ElectricPokemon(std::string name, int hp) : Pokemon(name, hp) {}
ElectricPokemon::ElectricPokemon(std::string name, int hp, int maxHp) : Pokemon(name, hp, maxHp) {}
ElectricPokemon::ElectricPokemon(std::string name, int hp, int maxHp, int attack) : Pokemon(name, hp, maxHp, attack) {}
ElectricPokemon::ElectricPokemon(std::string name, int hp, int maxHp, int attack, int defense) : Pokemon(name, hp, maxHp, attack, defense) {}
ElectricPokemon::ElectricPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack) : Pokemon(name, hp, maxHp, attack, defense, spAttack) {}
ElectricPokemon::ElectricPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense) {}
ElectricPokemon::ElectricPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed) {}
ElectricPokemon::ElectricPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level) {}
ElectricPokemon::ElectricPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel) {}
ElectricPokemon::ElectricPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel, evolutionName) {}

ElectricPokemon::ElectricPokemon(const ElectricPokemon &obj) : Pokemon(obj) {}

ElectricPokemon& ElectricPokemon::operator=(const ElectricPokemon& obj) {
    if (this != &obj) { Pokemon::operator=(obj); }
    return *this;
}

ElectricPokemon::~ElectricPokemon() {}

Type ElectricPokemon::getType() const {
    return ELECTRIC;
}

Pokemon* ElectricPokemon::evolve() {

}