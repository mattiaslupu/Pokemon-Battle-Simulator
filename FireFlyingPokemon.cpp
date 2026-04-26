
#include "FireFlyingPokemon.h"

FireFlyingPokemon::FireFlyingPokemon() : Pokemon(), FirePokemon(), FlyingPokemon(){
}

FireFlyingPokemon::FireFlyingPokemon(std::string name) :Pokemon(name), FirePokemon(), FlyingPokemon(){
}


FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp): Pokemon(name, hp), FirePokemon(), FlyingPokemon(){}

FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp, int maxHp): Pokemon(name, hp, maxHp), FirePokemon(), FlyingPokemon(){}

FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp, int maxHp, int attack) : Pokemon(name, hp, maxHp, attack), FirePokemon(), FlyingPokemon(){}

FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense) : Pokemon(name, hp, maxHp, attack, defense), FirePokemon(), FlyingPokemon(){}

FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack) : Pokemon(name, hp, maxHp, attack, defense, spAttack), FirePokemon(), FlyingPokemon(){}

FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense), FirePokemon(), FlyingPokemon(){}

FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed), FirePokemon(), FlyingPokemon(){}

FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level), FirePokemon(), FlyingPokemon(){}

FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel), FirePokemon(), FlyingPokemon(){}


FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName) : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel, evolutionName), FirePokemon(), FlyingPokemon(){}

FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense,
                                     int spAttack, int spDefense, int speed, int level, int evLevel,
                                     std::string evolutionName, StatusType status)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status),
      FirePokemon(), FlyingPokemon() {}

FireFlyingPokemon::FireFlyingPokemon(std::string name, int hp, int maxHp, int attack, int defense,
                                     int spAttack, int spDefense, int speed, int level, int evLevel,
                                     std::string evolutionName, StatusType status, int statusDuration)
    : Pokemon(name, hp, maxHp, attack, defense, spAttack, spDefense, speed,
              level, evLevel, evolutionName, status, statusDuration),
      FirePokemon(), FlyingPokemon() {}
FireFlyingPokemon::FireFlyingPokemon(const FireFlyingPokemon &obj) : Pokemon(obj), FirePokemon(), FlyingPokemon(){}

FireFlyingPokemon &FireFlyingPokemon::operator=(const FireFlyingPokemon &obj) {
    if (this!=&obj) Pokemon::operator=(obj);
    return *this;
}

FireFlyingPokemon::~FireFlyingPokemon() {

}

Type FireFlyingPokemon::getType() const {
    return FIRE_FLYING;
}

