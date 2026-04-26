#include "Trainer.h"
int Trainer::noTrainers = 0;

Trainer::Trainer() :id(noTrainers++), name("N/A"), activePokemonIndex(0){

}

Trainer::Trainer(std::string name):id(noTrainers++), activePokemonIndex(0) {
    this->name=name;
}

Trainer::Trainer(std::string name, int active): id(noTrainers++){
    this->name=name;
    this->activePokemonIndex=active;
}

Trainer::Trainer(const Trainer &obj): id(noTrainers++) {
    this->name=obj.name;
    this->team=obj.team;
    this->activePokemonIndex=obj.activePokemonIndex;
}

Trainer &Trainer::operator=(const Trainer &obj) {
    if (this==&obj) return *this;
    this->name=obj.name;
    this->team=obj.team;
    this->activePokemonIndex=obj.activePokemonIndex;
    return *this;
}

std::istream& operator>>(std::istream& is, Trainer& obj) {
    std::cout << "Trainer name: ";
    std::getline(is, obj.name);
    if (obj.name.empty())
        throw std::invalid_argument("Trainer name cannot be empty");
    return is;
}

std::ostream& operator<<(std::ostream& os, const Trainer& obj) {
    os << "Id: " << obj.id << "\n";
    os << "Name: " << obj.name << "\n";
    if (!obj.team.empty()) {
        os << "Team:\n";
        for (int i = 0; i < (int)obj.team.size(); i++)
            os << "Pokemon " << i + 1 << ": " << obj.team[i]->getName() << "\n";
        if (obj.activePokemonIndex >= 0 &&
            obj.activePokemonIndex < (int)obj.team.size())
            os << "Active: " << obj.team[obj.activePokemonIndex]->getName() << "\n";
    } else {
        os << "No Pokemon in team\n";
    }
    return os;
}

Trainer::~Trainer() {
    for(size_t i = 0; i < team.size(); i++) {
        delete team[i];
    }
    team.clear();
}

void Trainer::addPokemon(Pokemon * obj) {
    if (team.size()<6) {
        team.push_back(obj);
        if (team.size()==1) activePokemonIndex=0;
    }
    else {
        throw std::out_of_range("Error: THE TEAM IS FULL! You can't have more than 6 Pokemon in you active team.");
    }

}
void Trainer::replacePokemon(int index, Pokemon* newPokemon) {
    if (index < 0 || index >= (int)team.size())
        throw std::out_of_range("Invalid replace index: " + std::to_string(index));
    if (newPokemon == nullptr)
        throw std::invalid_argument("Cannot replace with null Pokemon");
    team[index] = newPokemon;
}

Pokemon *Trainer::getPokemon(int index) {
    if (index < 0 || index >= (int)team.size())
        throw std::out_of_range("Invalid Pokemon index: " + std::to_string(index));
    return team[index];
}

std::string Trainer::getName() {
    return name;
}

void Trainer::setName(std::string newName) {
    this->name=newName;
}

bool Trainer::switchPokemon(int index) {
    if (index < 1 || index > team.size()) {
        std::cout << "Invalid Pokemon index!\n";
        return false;
    }

    int realIndex = index - 1;

    if (realIndex == activePokemonIndex) {
        std::cout << team[realIndex]->getName() << " is already in battle!\n";
        return false;
    }

    if (team[realIndex]->isFainted()) {
        std::cout << team[realIndex]->getName() << " has fainted and cannot fight!\n";
        return false;
    }
    activePokemonIndex = realIndex;
    std::cout << "Go, " << team[activePokemonIndex]->getName() << "!\n";

    return true;
}

bool Trainer::hasAlivePokemon() {
    for (int i=0; i<team.size(); i++) {
        if (team[i]->getHp()!=0)
            return true;
    }
    return false;
}

void Trainer::healPokemon(int index) {
    if (index < 1 || index > (int)team.size()) throw std::out_of_range("Invalid Pokemon index: " + std::to_string(index));
    team[index - 1]->heal();
    std::cout << "You healed " << team[index - 1]->getName() << "\n";
}

void Trainer::healTeam() {
    for (int i=0; i<team.size(); i++) {
        team[i]->heal();
    }
    std::cout<<"You healed you team! They are ready to battle again.";

}

int Trainer::getTeamSize() {
    return team.size();
}

Pokemon* Trainer::getActivePokemon() {
    if (team.empty())
        throw std::runtime_error(name + " has no Pokemon in team");
    if (activePokemonIndex < 0 || activePokemonIndex >= (int)team.size())
        throw std::out_of_range("Active Pokemon index out of range");
    return team[activePokemonIndex];
}

void Trainer::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Cannot open save file: " + filename);

    file << name << "\n";
    file << team.size() << "\n";

    for (Pokemon* p : team) {
        if (p == nullptr) continue;
        file << typeToString(p->getType()) << ","
             << p->getName() << ","
             << p->getHp() << ","
             << p->getMaxHp() << ","
             << p->getAttack() << ","
             << p->getDefense() << ","
             << p->getSpAttack() << ","
             << p->getSpDefense() << ","
             << p->getSpeed() << ","
             << p->getLevel() << ","
             << p->getEvLevel() << ","
             << p->getEvolutionName() << "\n";
    }

    file.close();
    std::cout << "Progress saved for trainer: " << name << "\n";
}


void Trainer::loadFromFile(const std::string& filename, Pokedex& pokedex) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Save file not found: " + filename);

    std::getline(file, name);
    if (name.empty())
        throw std::runtime_error("Invalid save file — empty trainer name");

    int teamSize;
    file >> teamSize;
    file.ignore();

    if (teamSize < 0 || teamSize > 6)
        throw std::runtime_error("Invalid save file — team size out of range: "
                                 + std::to_string(teamSize));
    for (Pokemon* p : team) delete p;
    team.clear();
    activePokemonIndex = 0;

    for (int i = 0; i < teamSize; i++) {
        std::string line;
        std::getline(file, line);

        if (line.empty())
            throw std::runtime_error("Invalid save file — missing data at Pokemon "
                                     + std::to_string(i + 1));

        try {
            std::stringstream ss(line);
            std::string token, typeStr, pName, evName;
            int hpCur, hpMax, atk, def, spAtk, spDef, spd, lvl, evLvl;

            std::getline(ss, typeStr, ',');
            std::getline(ss, pName, ',');
            std::getline(ss, token, ','); hpCur  = std::stoi(token);
            std::getline(ss, token, ','); hpMax  = std::stoi(token);
            std::getline(ss, token, ','); atk    = std::stoi(token);
            std::getline(ss, token, ','); def    = std::stoi(token);
            std::getline(ss, token, ','); spAtk  = std::stoi(token);
            std::getline(ss, token, ','); spDef  = std::stoi(token);
            std::getline(ss, token, ','); spd    = std::stoi(token);
            std::getline(ss, token, ','); lvl    = std::stoi(token);
            std::getline(ss, token, ','); evLvl  = std::stoi(token);
            std::getline(ss, evName);

            if (hpCur < 0 || hpMax < 0 || lvl < 1)
                throw std::invalid_argument("Invalid stats for Pokemon: " + pName);
            Pokemon* p = pokedex.createByName(pName);
            p->setHp(hpCur);
            p->setLevel(lvl);

            team.push_back(p);

        } catch (std::invalid_argument& e) {
            std::cerr << "Warning: Could not load Pokemon " << i + 1
                      << " — " << e.what() << "\n";
        } catch (std::out_of_range& e) {
            std::cerr << "Warning: Number out of range for Pokemon "
                      << i + 1 << "\n";
        }
    }

    file.close();

    if (team.empty())
        throw std::runtime_error("No Pokemon loaded from save file");

    std::cout << "Progress loaded for trainer: " << name
              << " (" << team.size() << " Pokemon)\n";
}