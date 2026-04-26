
#include "FirePokemon.h"

FirePokemon::FirePokemon() : Pokemon(){}
FirePokemon::FirePokemon(std::string name) : Pokemon(name) {}
FirePokemon::FirePokemon(std::string name, int hp) : Pokemon(name, hp){}
FirePokemon::FirePokemon(std::string name, int hp, int maxHp) : Pokemon(name, hp, maxHp){}
FirePokemon::FirePokemon(std::string name, int hp, int maxHp, int attack) : Pokemon(name, hp, maxHp, attack){}
FirePokemon::FirePokemon(std::string name, int hp, int maxHp, int attack,int defense) : Pokemon(name, hp, maxHp, attack, defense){}
FirePokemon::FirePokemon(std::string name, int hp, int maxHp, int attack,int defense, int spAttack) : Pokemon(name, hp, maxHp, attack, defense, spAttack){}
FirePokemon::FirePokemon(std::string name, int hp, int maxHp, int attack,int defense, int spAttack, int spDefense) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense){}
FirePokemon::FirePokemon(std::string name, int hp, int maxHp, int attack,int defense, int spAttack, int spDefense, int speed) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed){}
FirePokemon::FirePokemon(std::string name, int hp, int maxHp, int attack,int defense, int spAttack, int spDefense, int speed, int level) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level){}
FirePokemon::FirePokemon(std::string name, int hp, int maxHp, int attack,int defense, int spAttack, int spDefense, int speed, int level, int evLevel) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel){}
FirePokemon::FirePokemon(std::string name, int hp, int maxHp, int attack,int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel, evolutionName){};
FirePokemon::FirePokemon(std::string name, int hp, int maxHp, int attack, int defense,int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName, StatusType status): Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel, evolutionName, status) {}
FirePokemon::FirePokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName, StatusType status, int statusDuration) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel, evolutionName, status, statusDuration) {}

FirePokemon::FirePokemon(const FirePokemon &obj): Pokemon(obj) {}
FirePokemon& FirePokemon::operator=(const FirePokemon& obj) {
    if (this != &obj) Pokemon::operator=(obj);
    return *this;
}

FirePokemon::~FirePokemon() {

}

Type FirePokemon::getType() const{
    return FIRE;
};

