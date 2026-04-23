#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Move.h"
class Move;
enum Type { NORMAL, FIRE, WATER, GRASS, ELECTRIC, ICE, ROCK, FLYING, FIRE_FLYING };

class Pokemon {
protected:
    const int id;
    static int noPokemons;
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
    std::string evolutionName;
    std::vector<Move*> moves;
    StatusType status;
    int statusDuration;
public:
    Pokemon();
    Pokemon(std::string);
    Pokemon(std::string, int);
    Pokemon(std::string, int, int);
    Pokemon(std::string, int, int, int);
    Pokemon(std::string, int, int, int, int);
    Pokemon(std::string, int, int, int, int, int);
    Pokemon(std::string, int, int, int, int, int, int);
    Pokemon(std::string, int, int, int, int, int, int, int);
    Pokemon(std::string, int, int, int, int, int, int, int, int);
    Pokemon(std::string, int, int, int, int, int, int, int, int, int);
    Pokemon(std::string, int, int, int, int, int, int, int, int, int, std::string);
    Pokemon(std::string, int, int, int, int, int, int, int, int, int, std::string, StatusType);
    Pokemon(std::string, int, int, int, int, int, int, int, int, int, std::string, StatusType, int);
    Pokemon(const Pokemon &obj);
    Pokemon& operator=(const Pokemon &obj);
    virtual ~Pokemon();
    friend std::istream& operator>>(std::istream& is, Pokemon &obj);
    friend std::ostream& operator<<(std::ostream& os, const Pokemon &obj);
    void takeDamage(int);
    void levelUp();
    bool isFainted() const;
    void learnMove(Move *);
    void forgetMove(int);
    int getId() const;
    std::string getName() const;
    void setName(std:: string newName);
    int getHp() const;
    void setHp(int);
    int getMaxHp() const;
    int getAttack() const;
    int getDefense() const;
    int getSpAttack() const;
    int getSpDefense() const;
    int getSpeed() const;
    int getLevel() const;
    void setLevel(int);
    int getEvLevel() const;
    void applyStatus(StatusType type, int duration);
    void heal();
    virtual Type getType() const =0;
    virtual Pokemon* evolve() =0;
};


