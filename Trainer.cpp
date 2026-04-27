#include "Trainer.h"
#include <sstream>
#include <stdexcept>
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
        p->save(file);
    }

    file.close();
    std::cout << "Progress saved for trainer: " << name << "\n";
}

void Trainer::loadFromFile(const std::string& filename, Pokedex& pokedex) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Save file not found");

    if (!std::getline(file, name) || name.empty()) {
        throw std::runtime_error("Save file is empty or invalid");
    }
    int teamSize;
    if (!(file >> teamSize)) {
        throw std::runtime_error("Corrupted team size in save file");
    }
    file.ignore(1000, '\n');
    for (Pokemon* p : team) delete p;
    team.clear();
    activePokemonIndex = 0;
    for (int i = 0; i < teamSize; i++) {
        std::string line;
        if (!std::getline(file, line) || line.empty()) break;

        std::stringstream ss(line);
        std::string pName;
        if (!std::getline(ss, pName, ',')) continue;

        try {
            Pokemon* p = pokedex.createByName(pName);
            if (p) {
                p->load(file, line);
                team.push_back(p);
            }
        } catch (const std::exception& e) {
            std::cerr << "Warning: Could not load Pokemon " << pName << ": " << e.what() << "\n";
        }
    }

    file.close();

    if (team.empty()) {
        throw std::runtime_error("No Pokemon could be loaded from file");
    }

    std::cout << "Loaded: " << name << " (" << team.size() << " Pokemon)\n";
}


void Trainer::removePokemon(int index) {
    if (team.empty()) {
        throw std::runtime_error("Cannot remove Pokemon: Team is empty!");
    }

    if (index < 0 || index >= team.size()) {
        throw std::out_of_range("Invalid Pokemon index: " + std::to_string(index + 1));
    }
    delete team[index];
    team.erase(team.begin() + index);
}

