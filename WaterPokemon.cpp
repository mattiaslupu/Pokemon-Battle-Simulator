
#include "WaterPokemon.h"

WaterPokemon::WaterPokemon() : Pokemon(){}
WaterPokemon::WaterPokemon(std::string name) : Pokemon(name) {}
WaterPokemon::WaterPokemon(std::string name, int hp) : Pokemon(name, hp){}
WaterPokemon::WaterPokemon(std::string name, int hp, int maxHp) : Pokemon(name, hp, maxHp){}
WaterPokemon::WaterPokemon(std::string name, int hp, int maxHp, int attack) : Pokemon(name, hp, maxHp, attack){}
WaterPokemon::WaterPokemon(std::string name, int hp, int maxHp, int attack, int defense) : Pokemon(name, hp, maxHp, attack, defense){}
WaterPokemon::WaterPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack) : Pokemon(name, hp, maxHp, attack, defense, spAttack){}
WaterPokemon::WaterPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense){}
WaterPokemon::WaterPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed){}
WaterPokemon::WaterPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level){}
WaterPokemon::WaterPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel){}
WaterPokemon::WaterPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel, evolutionName){};
WaterPokemon::WaterPokemon(std::string name, int hp, int maxHp, int attack, int defense,
                           int spAttack, int spDefense, int speed, int level, int evLevel,
                           std::string evolutionName, StatusType status)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status) {}

WaterPokemon::WaterPokemon(std::string name, int hp, int maxHp, int attack, int defense,
                           int spAttack, int spDefense, int speed, int level, int evLevel,
                           std::string evolutionName, StatusType status, int statusDuration)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status, statusDuration) {}

WaterPokemon::WaterPokemon(const WaterPokemon &obj): Pokemon(obj) {}

WaterPokemon& WaterPokemon::operator=(const WaterPokemon& obj) {
    if (this != &obj) {
        Pokemon::operator=(obj);
    }
    return *this;
}

Type WaterPokemon::getType() const {
    return WATER;
};

WaterPokemon::~WaterPokemon() {
}
