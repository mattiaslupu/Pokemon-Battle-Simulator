#include "Pokemon.h"
#include "Move.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "AttackMove.h"
#include "SpAttackMove.h"
#include "StatusMove.h"
#include <sstream>
#include <fstream>
#include <string>

int Pokemon::noPokemons = 0;
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
    this->status=NONE;
    this->statusDuration=0;
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
    this->status=NONE;
    this->statusDuration=0;
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
    this->status=NONE;
    this->statusDuration=0;
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
    this->status=NONE;
    this->statusDuration=0;
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
    this->status=NONE;
    this->statusDuration=0;
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
    this->status=NONE;
    this->statusDuration=0;
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
    this->status=NONE;
    this->statusDuration=0;
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
    this->status=NONE;
    this->statusDuration=0;
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
    this->status=NONE;
    this->statusDuration=0;
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
    this->status=NONE;
    this->statusDuration=0;
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
    this->status=NONE;
    this->statusDuration=0;
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
    this->status=NONE;
    this->statusDuration=0;
}

Pokemon::Pokemon(const Pokemon &obj) : id(noPokemons++){
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
    this->status = obj.status;
    this->statusDuration = obj.statusDuration;
}
Pokemon::Pokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName, StatusType status): id(noPokemons++), name(name), hp(hp), maxHp(maxHp), attack(attack),
      defense(defense), spAttack(spAttack), spDefense(spDefense), speed(speed),
      level(level), evLevel(evLevel), evolutionName(evolutionName),
      status(status), statusDuration(0) {}

Pokemon::Pokemon(std::string name, int hp, int maxHp, int attack, int defense, int spAttack, int spDefense, int speed, int level, int evLevel, std::string evolutionName, StatusType status, int statusDuration)
    : id(noPokemons++), name(name), hp(hp), maxHp(maxHp), attack(attack),
      defense(defense), spAttack(spAttack), spDefense(spDefense), speed(speed),
      level(level), evLevel(evLevel), evolutionName(evolutionName),
      status(status), statusDuration(statusDuration) {}

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
    this->status = obj.status;
    this->statusDuration = obj.statusDuration;
    return *this;
}

Pokemon::~Pokemon() {
    for(size_t i = 0; i < moves.size(); i++) {
        delete moves[i];
    }
    moves.clear();
};
void Pokemon::setName(std::string newName) {
    name = newName;
}

int Pokemon::getHp() const {
    return hp;
}
void Pokemon::setHp(int newHp) {
    if (newHp < 0)
        throw std::invalid_argument("HP cannot be negative: " + std::to_string(newHp));
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
    if (newLevel < 1)
        throw std::invalid_argument("Level must be >= 1: " + std::to_string(newLevel));
    level = newLevel;
}

int Pokemon::getEvLevel() const {
    return evLevel;
}

std::ostream& operator<<(std::ostream& os, const Pokemon &obj) {
    os<<"Id: "<<obj.getId()<<"\n";
    os<<"Name: "<<obj.getName()<<"\n";
    os<<"Attack: "<<obj.getAttack()<<"\n";
    os<<"Defense: "<<obj.getDefense()<<"\n";
    os<<"HP: "<<obj.getHp()<<"\n";
    os<<"Max HP: "<<obj.getMaxHp()<<"\n";
    os<<"Special Attack: "<<obj.getSpAttack()<<"\n";
    os<<"Special Defense: "<<obj.getSpDefense()<<"\n";
    os<<"Speed: "<<obj.getSpeed()<<"\n";
    os<<"Level: "<<obj.getLevel()<<"\n";

    if (obj.getEvLevel() != 0) {
        os<<"Evolution Level: "<<obj.getEvLevel()<<"\n";
        os<<"Evolution Name: "<<obj.evolutionName<<"\n";
    }
    else os<<"This Pokemon does not evolve\n";

    os<<"Moves Learned: "<<obj.moves.size()<<"\n";

    os<<"Status: "<<obj.status<<"\n";
    os<<"Status duration: "<<obj.statusDuration<<"\n";
    return os;
}

std::istream& operator>>(std::istream& is, Pokemon& obj) {
    std::string name;
    int hp, maxHp, attack, defense, spAttack, spDefense, speed, level, evLevel, statusInput;

    std::cout << "Name: ";
    is >> name;
    if (name.empty()) throw std::invalid_argument("Name cannot be empty");
    obj.setName(name);

    std::cout << "HP: ";
    is >> hp;
    if (is.fail() || hp < 0) throw std::invalid_argument("HP must be non-negative");
    obj.setHp(hp);

    std::cout << "Max HP: ";
    is >> maxHp;
    if (is.fail() || maxHp < hp) throw std::invalid_argument("Max HP cannot be less than HP");
    obj.maxHp = maxHp;

    std::cout << "Attack: ";
    is >> attack;
    if (is.fail() || attack < 0) throw std::invalid_argument("Attack must be non-negative");
    obj.attack = attack;

    std::cout << "Defense: ";
    is >> defense;
    if (is.fail() || defense < 0) throw std::invalid_argument("Defense must be non-negative");
    obj.defense = defense;

    std::cout << "Special Attack: ";
    is >> spAttack;
    if (is.fail() || spAttack < 0) throw std::invalid_argument("SpAttack must be non-negative");
    obj.spAttack = spAttack;

    std::cout << "Special Defense: ";
    is >> spDefense;
    if (is.fail() || spDefense < 0) throw std::invalid_argument("SpDefense must be non-negative");
    obj.spDefense = spDefense;

    std::cout << "Speed: ";
    is >> speed;
    if (is.fail() || speed < 0) throw std::invalid_argument("Speed must be non-negative");
    obj.speed = speed;

    std::cout << "Level: ";
    is >> level;
    if (is.fail()) throw std::invalid_argument("Level must be a number");
    obj.setLevel(level);

    std::cout << "Evolution Level (-1 if none): ";
    is >> evLevel;
    if (is.fail()) throw std::invalid_argument("Evolution level must be a number");
    obj.evLevel = evLevel;

    std::cout << "Evolution Name (none if none): ";
    std::string evName;
    is >> evName;
    obj.evolutionName = evName;

    std::cout << "Status (0=NONE,1=BURN,2=SLEEP,3=PARALYSIS,4=POISON): ";
    is >> statusInput;
    if (is.fail() || statusInput < 0 || statusInput > 4)
        throw std::invalid_argument("Status must be between 0 and 4");
    obj.status = static_cast<StatusType>(statusInput);

    if (obj.status != NONE) {
        std::cout << "Status duration: ";
        is >> obj.statusDuration;
        if (is.fail() || obj.statusDuration < 0)
            throw std::invalid_argument("Status duration must be non-negative");
    } else {
        obj.statusDuration = 0;
    }
    return is;
}

void Pokemon::takeDamage(int damage) {
    if (damage < 0)
        throw std::invalid_argument("Damage cannot be negative: " + std::to_string(damage));
    hp -= damage;
    if (hp < 0) hp = 0;
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
    if (newMove == nullptr)
        throw std::invalid_argument("Cannot learn a null move");
    int option;
    if (moves.size() < 4) {
        moves.push_back(newMove);
    } else {
        std::cout << name << " already has 4 moves\nWhich move to forget?\n";
        for (int i = 0; i < (int)moves.size(); i++)
            std::cout << i + 1 << ") " << moves[i]->getName() << "\n";
        std::cout << "5) Don't learn\n";
        std::cin >> option;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            throw std::invalid_argument("Invalid input — expected a number");
        }
        if (option >= 1 && option <= 4) {
            forgetMove(option - 1);
            moves.push_back(newMove);
        } else if (option == 5) {
            std::cout << "Gave up on learning " << newMove->getName() << "\n";
            delete newMove;
        } else {
            throw std::invalid_argument("Option must be between 1 and 5");
        }
    }
}

void Pokemon::forgetMove(int index) {
    if (moves.size() <= 1) {
        throw std::invalid_argument("A Pokemon cannot forget its last move!");
    }

    if (index >= 0 && index < moves.size()) {
        delete moves[index];
        moves.erase(moves.begin() + index);
    } else {
        throw std::out_of_range("Invalid move index!");
    }
}

bool Pokemon::isFainted() const {
    if (hp<=0) return true;
    else return false;
}

void Pokemon::applyStatus(StatusType type, int duration) {
    if (duration < 0)
        throw std::invalid_argument("Status duration cannot be negative");
    if (this->status == NONE) {
        this->status = type;
        this->statusDuration = duration;
    }
}

void Pokemon::transferProgressTo(Pokemon* evolvedForm) {
    if (evolvedForm == nullptr)
        throw std::invalid_argument("Cannot transfer progress to null Pokemon");
    evolvedForm->level = this->level;
    evolvedForm->moves = this->moves;
    this->moves.clear();
    evolvedForm->hp = evolvedForm->maxHp;
    evolvedForm->status = NONE;
}

std::vector<Move *> Pokemon::getMoves() {
    return moves;
}

void Pokemon::heal() {
    hp = maxHp;
    status = NONE;
    statusDuration = 0;
    for (int i = 0; i < (int)moves.size(); i++)
        moves[i]->restorePP();
}

std::string Pokemon::getEvolutionName() const{
    return evolutionName;
}

std::string Pokemon::getName() const {
    return name;
}

int Pokemon::getId() const {
    return id;
}


void Pokemon::save(std::ofstream& out) const {
    out << name << ","
        << static_cast<int>(getType()) << ","
        << hp << "," << maxHp << ","
        << attack << "," << defense << ","
        << spAttack << "," << spDefense << ","
        << speed << "," << level << ","
        << evLevel << "," << evolutionName << ",\n";
    out << moves.size() << "\n";
    for (Move* m : moves) {
        m->save(out);
    }
}

void Pokemon::load(std::ifstream& in, std::string firstLine) {
    std::stringstream ss(firstLine);
    std::string token;

    std::getline(ss, name, ',');
    std::getline(ss, token, ',');     // Sărim peste tip (e setat de Pokedex)
    std::getline(ss, token, ','); hp = std::stoi(token);
    std::getline(ss, token, ','); maxHp = std::stoi(token);
    std::getline(ss, token, ','); attack = std::stoi(token);
    std::getline(ss, token, ','); defense = std::stoi(token);
    std::getline(ss, token, ','); spAttack = std::stoi(token);
    std::getline(ss, token, ','); spDefense = std::stoi(token);
    std::getline(ss, token, ','); speed = std::stoi(token);
    std::getline(ss, token, ','); level = std::stoi(token);
    std::getline(ss, token, ','); evLevel = std::stoi(token);
    std::getline(ss, evolutionName, ','); // Citim până la virgula de control

    int movesCount = 0;
    if (!(in >> movesCount)) return;
    in.ignore(1000, '\n');

    for (Move* m : moves) delete m;
    moves.clear();

    for (int i = 0; i < movesCount; i++) {
        std::string mLine;
        if (!std::getline(in, mLine)) break;
        std::stringstream sm(mLine);
        std::string tag, mName, mType, mAcc, mPP, extra1, extra2;

        std::getline(sm, tag, ',');
        std::getline(sm, mName, ',');
        std::getline(sm, mType, ',');
        std::getline(sm, mAcc, ',');
        std::getline(sm, mPP, ',');

        Move* newMove = nullptr;
        if (tag == "PHYSICAL" || tag == "SPECIAL") {
            std::getline(sm, extra1, ',');
            if (tag == "PHYSICAL") newMove = new AttackMove();
            else newMove = new SpAttackMove();
            auto* pm = dynamic_cast<PhysicalMove*>(newMove);
            if (pm) pm->setPower(std::stoi(extra1));
        } else if (tag == "STATUS") {
            std::getline(sm, extra1, ',');
            std::getline(sm, extra2, ',');
            StatusMove* smObj = new StatusMove();
            smObj->setEffect(static_cast<StatusType>(std::stoi(extra1)));
            smObj->setDuration(std::stoi(extra2));
            newMove = smObj;
        }

        if (newMove) {
            newMove->setName(mName);
            newMove->setType(static_cast<Type>(std::stoi(mType)));
            newMove->setAccuracy(std::stoi(mAcc));
            newMove->setMaxPP(std::stoi(mPP));
            moves.push_back(newMove);
        }
    }
}