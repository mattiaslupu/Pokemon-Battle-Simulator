#include "Pokemon.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

Pokemon::Pokemon() :id(noPokemons++){
    this->name = "N/A";
    this->hp = 0;
    this->maxHp = 0;
    this->attack = 0;
    this->defense = 0;
    this->spAttack = 0;
    this->spDefense = 0;
    this->speed = 0;
    this->level = 1;
    this->evLevel = 0;
    this->evolutionName = "None";
    this->moves.clear();
}

Pokemon::Pokemon(std::string name) :id(noPokemons++){
    this->name = name;
    this->hp = 0;
    this->maxHp = 0;
    this->attack = 0;
    this->defense = 0;
    this->spAttack = 0;
    this->spDefense = 0;
    this->speed = 0;
    this->level = 1;
    this->evLevel = 0;
    this->evolutionName = "None";
    this->moves.clear();
}

Pokemon::Pokemon(std::string name, int hp): id(noPokemons++) {
    this->name = name;
    this->hp = hp;
    this->maxHp = hp;
    this->attack = 0;
    this->defense = 0;
    this->spAttack = 0;
    this->spDefense = 0;
    this->speed = 0;
    this->level = 1;
    this->evLevel = 0;
    this->evolutionName = "None";
    this->moves.clear();
}

Pokemon::Pokemon(std::string name, int hp, int maxHp) : id(noPokemons++){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->attack = 0;
    this->defense = 0;
    this->spAttack = 0;
    this->spDefense = 0;
    this->speed = 0;
    this->level = 1;
    this->evLevel = 0;
    this->evolutionName = "None";
    this->moves.clear();
}

Pokemon::Pokemon(std::string name, int hp, int maxHp, int attack) : id(noPokemons++){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->attack = attack;
    this->defense = 0;
    this->spAttack = 0;
    this->spDefense = 0;
    this->speed = 0;
    this->level = 1;
    this->evLevel = 0;
    this->evolutionName = "None";
    this->moves.clear();
}

Pokemon::Pokemon(std::string name, int hp, int maxHp, int attack, int defense) : id(noPokemons++){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->attack = attack;
    this->defense = defense;
    this->spAttack = 0;
    this->spDefense = 0;
    this->speed = 0;
    this->level = 1;
    this->evLevel = 0;
    this->evolutionName = "None";
    this->moves.clear();
}

Pokemon::Pokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack) : id(noPokemons++){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->attack = attack;
    this->defense = defense;
    this->spAttack = spAttack;
    this->spDefense = 0;
    this->speed = 0;
    this->level = 1;
    this->evLevel = 0;
    this->evolutionName = "None";
    this->moves.clear();
}

Pokemon::Pokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense) : id(noPokemons++){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->attack = attack;
    this->defense = defense;
    this->spAttack = spAttack;
    this->spDefense = spDefense;
    this->speed = 0;
    this->level = 1;
    this->evLevel = 0;
    this->evolutionName = "None";
    this->moves.clear();
}

Pokemon::Pokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed) : id(noPokemons++){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->attack = attack;
    this->defense = defense;
    this->spAttack = spAttack;
    this->spDefense = spDefense;
    this->speed = speed;
    this->level = 1;
    this->evLevel = 0;
    this->evolutionName = "None";
    this->moves.clear();
}

Pokemon::Pokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level) : id(noPokemons++){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->attack = attack;
    this->defense = defense;
    this->spAttack = spAttack;
    this->spDefense = spDefense;
    this->speed = speed;
    this->level = level;
    this->evLevel = 0;
    this->evolutionName = "None";
    this->moves.clear();
}

Pokemon::Pokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel) : id(noPokemons++){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->attack = attack;
    this->defense = defense;
    this->spAttack = spAttack;
    this->spDefense = spDefense;
    this->speed = speed;
    this->level = level;
    this->evLevel = evLevel;
    this->evolutionName = "None";
    this->moves.clear();
}

Pokemon::Pokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName) : id(noPokemons++){
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->attack = attack;
    this->defense = defense;
    this->spAttack = spAttack;
    this->spDefense = spDefense;
    this->speed = speed;
    this->level = level;
    this->evLevel = evLevel;
    this->evolutionName = evolutionName;
    this->moves.clear();
}

Pokemon::Pokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName, std::vector<Move *> moves): id(noPokemons++) {
    this->name = name;
    this->hp = hp;
    this->maxHp = maxHp;
    this->attack = attack;
    this->defense = defense;
    this->spAttack = spAttack;
    this->spDefense = spDefense;
    this->speed = speed;
    this->level = level;
    this->evLevel = evLevel;
    this->evolutionName = evolutionName;
    this->moves = moves;
}

Pokemon::Pokemon(Pokemon &obj) : id(noPokemons++){
    this->name = obj.name;
    this->hp = obj.hp;
    this->maxHp = obj.maxHp;
    this->attack = obj.attack;
    this->defense = obj.defense;
    this->spAttack = obj.spAttack;
    this->spDefense = obj.spDefense;
    this->speed = obj.speed;
    this->level = obj.level;
    this->evLevel = obj.evLevel;
    this->evolutionName = obj.evolutionName;
    this->moves = obj.moves;
}

Pokemon& Pokemon::operator=(const Pokemon &obj) {
    if (this==&obj) return *this;
    this->name = obj.name;
    this->hp = obj.hp;
    this->maxHp = obj.maxHp;
    this->attack = obj.attack;
    this->defense = obj.defense;
    this->spAttack = obj.spAttack;
    this->spDefense = obj.spDefense;
    this->speed = obj.speed;
    this->level = obj.level;
    this->evLevel = obj.evLevel;
    this->evolutionName = obj.evolutionName;
    this->moves = obj.moves;

    return *this;
}

Pokemon::~Pokemon(){};
void Pokemon::setName(std::string newName) {
    name = newName;
}

int Pokemon::getHp() const {
    return hp;
}
void Pokemon::setHp(int newHp) {
    hp = newHp;
}

int Pokemon::getMaxHp() const {
    return maxHp;
}

int Pokemon::getAttack() const {
    return attack;
}

int Pokemon::getDefense() const {
    return defense;
}

int Pokemon::getSpAttack() const {
    return spAttack;
}

int Pokemon::getSpDefense() const {
    return spDefense;
}

int Pokemon::getSpeed() const {
    return speed;
}

int Pokemon::getLevel() const {
    return level;
}
void Pokemon::setLevel(int newLevel) {
    level = newLevel;
}

int Pokemon::getEvLevel() const {
    return evLevel;
}

std::ostream& operator<<(std::ostream& os, Pokemon &obj) {
    ///TO DO: Error handle
    os<<"Id: "<<obj.getId()<<"\n";
    os<<"Name: "<<obj.getName()<<"\n";
    os<<"Attack: "<<"\n";
    os<<"Defense"<<"\n";
    os<<"HP: "<<"\n";
    os<<"Max HP: "<<"\n";
    os<<"Special Attack: "<<"\n";
    os<<"Special Defense: "<<"\n";
    os<<"Speed: "<<"\n";
    os<<"Level: "<<"\n";
    if (obj.evLevel!=0) {
        os<<"Evolution Level: "<<"\n";
        os<<"Evolution Name: "<<"\n";
    }
    else os<<"This Pokemon does not evolve";
    os<<"Moves Learned: "<<"\n";
    return os;

}

std::istream& operator>>(std::istream &is, Pokemon &obj) {
    //TO DO: error handling
    std::string name;
    int hp;
    int maxHp;
    int attack;
    int defense;
    int spAttack;
    int spDefense;
    int speed;
    int level;
    int evLevel;
    std::cout<<"Name: ";
    is>>name;
    obj.setName(name);
    std::cout<<"HP: ";
    is>>hp;
    obj.setHp(hp);
    std::cout<<"Max HP: ";
    obj.maxHp=maxHp;
    std::cout<<"Attack: ";
    is>>attack;
    obj.attack=attack;
    std::cout<<"Defense";
    is>>defense;
    obj.defense=defense;
    std::cout<<"Special Attack: ";
    is>>spAttack;
    obj.spAttack=spAttack;
    std::cout<<"Special Defense: ";
    is>>spDefense;
    obj.spDefense=spDefense;
    std::cout<<"Speed: ";
    is>>speed;
    obj.speed=speed;
    std::cout<<"Level: ";
    is>>level;
    obj.setLevel(level);
    std::cout<<"Evolution level: ";
    is>>evLevel;
    obj.evLevel=evLevel;
    std::cout<<"Evolution Name: ";
    std::string evName;
    is>>evName;
    obj.evolutionName=evName;
    return is;
}

void Pokemon::takeDamage(int damage) {
    hp-=damage;
}

void Pokemon::levelUp() {
    level+=1;
    maxHp += std::max(1, maxHp / 33);
    hp += std::max(1, maxHp / 33);
    attack += std::max(1, attack / 33);
    defense += std::max(1, defense / 33);
    spAttack += std::max(1, spAttack / 33);
    spDefense += std::max(1, spDefense / 33);
    speed += std::max(1, speed / 33);
}

void Pokemon::learnMove(Move * newMove) {
    int option;
    if (moves.size()<4) {
        moves.push_back(newMove);
    }
    else {
        std::cout<<name<<" already has 4 moves\n<<Which move do you want to forget?\n";
        for (int i=0; i<moves.size(); i++) {
            std::cout<<i+1<<") "<<moves[i]->getName()<<"\n";
        }
        std::cout<<"5) Don't learn\n";
        ///TO DO: Try and catch
        std::cin>>option;
        if (option<=1 && option>=4) {
            forgetMove(option-1);
            moves.push_back(newMove);
        }
        else if (option == 5) {
            std::cout<<"Gave up on learning "<<newMove->getName();
            delete newMove;
        }
    }
}

void Pokemon::forgetMove(int index) {
    delete moves[index];
    moves.erase(moves.begin() + index);
}

bool Pokemon::isFainted() const {
    if (hp<=0) return true;
    else return false;
}
