
#include "Trainer.h"

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

std::istream &operator>>(std::istream &is, Trainer &obj) {
    ///To do
    return is;
}

std::ostream &operator<<(std::ostream &os, const Trainer &obj) {
    os<<"Id: "<<obj.id;
    os<<"Name"<<obj.name;
    if (obj.team.size()>0)
    {
        os<<"Team: "<<"/n";
        for (int i=0; i<obj.team.size(); i++)
            os<<"Pokemon "<<i+1<<" "<<obj.team[i]->getName()<<"/n";
    }
    else {
        os<<"You do not have any Pokemon in your team/n";
    }
    os<<"Active Pokemon"<<obj.team[obj.activePokemonIndex];
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

void Trainer::replacePokemon(int index, Pokemon * newPokemon) {
    if (index >= 0 && index < team.size()) {
        team[index] = newPokemon;
    } else {
        std::cerr << "Error: Invalid index for replacing Pokemon!\n";
    }
}

Pokemon *Trainer::getPokemon(int index) {
    //Error handle
    return team[index];
}

std::string Trainer::getName() {
    return name;
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
    if (index<1 || index>team.size()) {

    }
        //To do
    else {
        team[index-1]->heal();
        std::cout<<"You healed "<<team[index-1]->getName()<<"/n";
        std::cout<<team[index-1]->getName()<<" is ready to battle again";
    }
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

Pokemon *Trainer::getActivePokemon() {
    return team[activePokemonIndex];
}
