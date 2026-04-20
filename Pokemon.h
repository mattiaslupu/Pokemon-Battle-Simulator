#pragma once
#include <iostream>
#include <string>
#include <vector>

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
    Pokemon(std::string, int, int, int, int, int, int, int, int, int, std::string, std::vector<Move*>);
    Pokemon(Pokemon &obj);
    Pokemon& operator=(const Pokemon &obj);
    ~Pokemon();
    friend std::istream& operator>>(std::istream& is, Pokemon &obj);
    friend std::ostream& operator<<(std::ostream& os, Pokemon &obj);
    void takeDamage(int);
    void levelUp();
    bool isFainted() const;
    void learnMove(Move *);
    void forgetMove(int);
    int getId();
    std::string getName();
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
    virtual std::string getType() const =0;
    virtual Pokemon& evolve() =0;
};


