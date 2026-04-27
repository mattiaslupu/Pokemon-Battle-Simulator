#include "Pokedex.h"
#include "utils.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"
#include "GrassPokemon.h"
#include "ElectricPokemon.h"
#include "IcePokemon.h"
#include "RockPokemon.h"
#include "FlyingPokemon.h"
#include "FireFlyingPokemon.h"


Pokedex::Pokedex() {
}

Pokedex::Pokedex(std::vector<Pokemon *> data) {
    if (data.empty()) {
        return;
    }
    for (size_t i = 0; i < data.size(); i++) {
        if (data[i] != nullptr)
            entries.push_back(data[i]);
    }
}

Pokedex::Pokedex(const Pokedex &obj) {
    for (Pokemon* p : obj.entries) {
        if (p == nullptr) continue;

        switch (p->getType()) {
            case FIRE:
                entries.push_back(new FirePokemon(*dynamic_cast<FirePokemon*>(p)));
                break;

            case WATER:
                entries.push_back(new WaterPokemon(*dynamic_cast<WaterPokemon*>(p)));
                break;

            case GRASS:
                entries.push_back(new GrassPokemon(*dynamic_cast<GrassPokemon*>(p)));
                break;

            case ELECTRIC:
                entries.push_back(new ElectricPokemon(*dynamic_cast<ElectricPokemon*>(p)));
                break;

            case ICE:
                entries.push_back(new IcePokemon(*dynamic_cast<IcePokemon*>(p)));
                break;

            case ROCK:
                entries.push_back(new RockPokemon(*dynamic_cast<RockPokemon*>(p)));
                break;

            case FLYING:
                entries.push_back(new FlyingPokemon(*dynamic_cast<FlyingPokemon*>(p)));
                break;

            case FIRE_FLYING:
                entries.push_back(new FireFlyingPokemon(*dynamic_cast<FireFlyingPokemon*>(p)));
                break;

            default:
                std::cerr << "Eroare: Tip de Pokemon necunoscut la copiere!\n";
                break;
        }
    }
}


Pokedex::~Pokedex() {
    for (int i =0; i<entries.size(); i++) {
        delete entries[i];
    }
    entries.clear();
}

Pokemon *Pokedex::createByName(const std::string &name) const {
    if (entries.empty())
        throw std::runtime_error("Pokedex database is empty!");
    for (int i = 0; i < entries.size(); i ++) {
        if (entries[i]->getName() == name) {
            if (entries[i] -> getType() == FIRE) {
                return new FirePokemon(*dynamic_cast<FirePokemon*>(entries[i]));
            }
            else if (entries[i] -> getType() == WATER) {
                return new WaterPokemon(*dynamic_cast<WaterPokemon*>(entries[i]));
            }
            else if (entries[i] -> getType() == GRASS) {
                return new GrassPokemon(*dynamic_cast<GrassPokemon*>(entries[i]));
            }
            else if (entries[i] -> getType() == ELECTRIC) {
                return new ElectricPokemon(*dynamic_cast<ElectricPokemon*>(entries[i]));
            }
            else if (entries[i] -> getType() == ICE) {
                return new IcePokemon(*dynamic_cast<IcePokemon*>(entries[i]));
            }
            else if (entries[i] -> getType() == ROCK) {
                return new RockPokemon(*dynamic_cast<RockPokemon*>(entries[i]));
            }
            else if (entries[i] -> getType() == FLYING) {
                return new FlyingPokemon(*dynamic_cast<FlyingPokemon*>(entries[i]));
            }

            else if (entries[i] -> getType() == FIRE_FLYING) {
                return new FireFlyingPokemon(*dynamic_cast<FireFlyingPokemon*>(entries[i]));
            }

        }
    }
    throw std::invalid_argument("Pokemon " + name + " does not exist in Pokedex!");
}

Pokemon* Pokedex::getRandomPokemon() const {
    if (entries.empty())
        throw std::runtime_error("Cannot get random Pokemon — Pokedex is empty");
    int randomIndex = rand() % entries.size();
    return createByName(entries[randomIndex]->getName());
}


Pokedex &Pokedex::operator=(const Pokedex &obj) {
    if (this != &obj) {

        for (Pokemon* p : entries) {
            delete p;
        }
        entries.clear();
        for (Pokemon* p : obj.entries) {
            if (p == nullptr) continue;

            switch (p->getType()) {
                case FIRE:
                    entries.push_back(new FirePokemon(*dynamic_cast<FirePokemon*>(p)));
                    break;
                case WATER:
                    entries.push_back(new WaterPokemon(*dynamic_cast<WaterPokemon*>(p)));
                    break;
                case GRASS:
                    entries.push_back(new GrassPokemon(*dynamic_cast<GrassPokemon*>(p)));
                    break;
                case ELECTRIC:
                    entries.push_back(new ElectricPokemon(*dynamic_cast<ElectricPokemon*>(p)));
                    break;
                case ICE:
                    entries.push_back(new IcePokemon(*dynamic_cast<IcePokemon*>(p)));
                    break;
                case ROCK:
                    entries.push_back(new RockPokemon(*dynamic_cast<RockPokemon*>(p)));
                    break;
                case FLYING:
                    entries.push_back(new FlyingPokemon(*dynamic_cast<FlyingPokemon*>(p)));
                    break;
                case FIRE_FLYING:
                    entries.push_back(new FireFlyingPokemon(*dynamic_cast<FireFlyingPokemon*>(p)));
                    break;
                default:
                    throw std::runtime_error("Unknown Pokemon type during assignment");

            }
        }
    }
    return *this;
}

void Pokedex::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Critical error: Cannot open file " + filename);
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string name, typeStr, evolutionName;
        std::string tempStr;
        int hpCur, hpMax, attack, defense, spAtk, spDef, speed, evoLevel;

        std::getline(ss, name, ',');
        std::getline(ss, typeStr, ',');

        try {
            std::getline(ss, tempStr, ','); hpCur = std::stoi(tempStr);
            std::getline(ss, tempStr, ','); hpMax = std::stoi(tempStr);
            std::getline(ss, tempStr, ','); attack = std::stoi(tempStr);
            std::getline(ss, tempStr, ','); defense = std::stoi(tempStr);
            std::getline(ss, tempStr, ','); spAtk = std::stoi(tempStr);
            std::getline(ss, tempStr, ','); spDef = std::stoi(tempStr);
            std::getline(ss, tempStr, ','); speed = std::stoi(tempStr);
            std::getline(ss, tempStr, ','); evoLevel = std::stoi(tempStr);
            std::getline(ss, evolutionName);
        } catch (const std::exception&) {
            throw std::runtime_error("Error: Invalid numeric data in file for Pokemon " + name);
        }

        int currentLevel = 1;

        if (typeStr == "FIRE") {
            entries.push_back(new FirePokemon(name, hpCur, hpMax, attack, defense, spAtk, spDef, speed, currentLevel, evoLevel, evolutionName));
        }
        else if (typeStr == "WATER") {
            entries.push_back(new WaterPokemon(name, hpCur, hpMax, attack, defense, spAtk, spDef, speed, currentLevel, evoLevel, evolutionName));
        }
        else if (typeStr == "GRASS") {
            entries.push_back(new GrassPokemon(name, hpCur, hpMax, attack, defense, spAtk, spDef, speed, currentLevel, evoLevel, evolutionName));
        }
        else if (typeStr == "ELECTRIC") {
            entries.push_back(new ElectricPokemon(name, hpCur, hpMax, attack, defense, spAtk, spDef, speed, currentLevel, evoLevel, evolutionName));
        }
        else if (typeStr == "ICE") {
            entries.push_back(new IcePokemon(name, hpCur, hpMax, attack, defense, spAtk, spDef, speed, currentLevel, evoLevel, evolutionName));
        }
        else if (typeStr == "ROCK") {
            entries.push_back(new RockPokemon(name, hpCur, hpMax, attack, defense, spAtk, spDef, speed, currentLevel, evoLevel, evolutionName));
        }
        else if (typeStr == "FLYING") {
            entries.push_back(new FlyingPokemon(name, hpCur, hpMax, attack, defense, spAtk, spDef, speed, currentLevel, evoLevel, evolutionName));
        }
        else if (typeStr == "FIRE_FLYING") {
            entries.push_back(new FireFlyingPokemon(name, hpCur, hpMax, attack, defense, spAtk, spDef, speed, currentLevel, evoLevel, evolutionName));
        }
        else {
            throw std::runtime_error("Error: Unknown type '" + typeStr + "' for Pokemon '" + name + "' in file!");
        }
    }

    file.close();
}


std::ostream& operator<<(std::ostream& os, const Pokedex& obj) {
    os << "\n=== POKEDEX CATALOGUE (" << obj.entries.size() << " Registered Pokemon) ===\n";

    for (Pokemon* p : obj.entries) {
        if (p != nullptr) {
            os << *p << "\n--------------------\n";
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, Pokedex& obj) {
    std::string name, type;
    int hp, attack;

    std::cout << "\n=== SECRET LAB: Create your custom Pokemon ===\n";

    std::cout << "Enter name: ";
    is >> name;

    std::cout << "Enter type (FIRE, WATER, GRASS, ELECTRIC, ICE, ROCK, FLYING, FIRE_FLYING): ";
    is >> type;

    std::cout << "Max HP: ";
    if (!(is >> hp)) {
        is.clear();
        is.ignore(1000, '\n');
        throw std::invalid_argument("Error: HP must be a number!");
    }

    std::cout << "Attack: ";
    if (!(is >> attack)) {
        is.clear();
        is.ignore(1000, '\n');
        throw std::invalid_argument("Error: Attack must be a number!");
    }

    if (type == "FIRE") {
        obj.entries.push_back(new FirePokemon(name, hp, hp, attack, 50, 50, 50, 50, 100, 0, "NONE"));
        std::cout << "Success! " << name << " (FIRE) was added to the Pokedex!\n";
    }
    else if (type == "WATER") {
        obj.entries.push_back(new WaterPokemon(name, hp, hp, attack, 50, 50, 50, 50, 100, 0, "NONE"));
        std::cout << "Success! " << name << " (WATER) was added to the Pokedex!\n";
    }
    else if (type == "GRASS") {
        obj.entries.push_back(new GrassPokemon(name, hp, hp, attack, 50, 50, 50, 50, 100, 0, "NONE"));
        std::cout << "Success! " << name << " (GRASS) was added to the Pokedex!\n";
    }
    else if (type == "ELECTRIC") {
        obj.entries.push_back(new ElectricPokemon(name, hp, hp, attack, 50, 50, 50, 50, 100, 0, "NONE"));
        std::cout << "Success! " << name << " (ELECTRIC) was added to the Pokedex!\n";
    }
    else if (type == "ICE") {
        obj.entries.push_back(new IcePokemon(name, hp, hp, attack, 50, 50, 50, 50, 100, 0, "NONE"));
        std::cout << "Success! " << name << " (ICE) was added to the Pokedex!\n";
    }
    else if (type == "ROCK") {
        obj.entries.push_back(new RockPokemon(name, hp, hp, attack, 50, 50, 50, 50, 100, 0, "NONE"));
        std::cout << "Success! " << name << " (ROCK) was added to the Pokedex!\n";
    }
    else if (type == "FLYING") {
        obj.entries.push_back(new FlyingPokemon(name, hp, hp, attack, 50, 50, 50, 50, 100, 0, "NONE"));
        std::cout << "Success! " << name << " (FLYING) was added to the Pokedex!\n";
    }
    else if (type == "FIRE_FLYING") {
        obj.entries.push_back(new FireFlyingPokemon(name, hp, hp, attack, 50, 50, 50, 50, 100, 0, "NONE"));
        std::cout << "Success! " << name << " (FIRE/FLYING) was added to the Pokedex!\n";
    }
    else {
        throw std::invalid_argument("Error: Invalid type! Custom Pokemon could not be created.");
    }

    return is;
}


void Pokedex::saveToFile(const std::string& filename) const {
    if (entries.empty())
        throw std::runtime_error("Cannot save empty Pokedex");

    std::ofstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file for saving: " + filename);

    for (Pokemon* p : entries) {
        if (p == nullptr) continue;
        file << p->getName() << ","
             << typeToStringUpper(p->getType()) << ","
             << p->getHp() << ","
             << p->getMaxHp() << ","
             << p->getAttack() << ","
             << p->getDefense() << ","
             << p->getSpAttack() << ","
             << p->getSpDefense() << ","
             << p->getSpeed() << ","
             << p->getEvLevel() << ","
             << p->getEvolutionName() << "\n";
    }

    file.close();
}