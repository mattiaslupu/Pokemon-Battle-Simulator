#include "Move.h"
int Move::noMoves = 0;
Move::Move() : id(noMoves++), name("N/A"), accuracy(0), type(NORMAL), pp(0), maxPp(0), category(PHYSICAL) {
}

Move::Move(std::string name): id(noMoves++), accuracy(0), type(NORMAL), pp(0), maxPp(0), category(PHYSICAL) {
    this->name=name;
}

Move::Move(std::string name, int accuracy): id(noMoves++), type(NORMAL), pp(0), maxPp(0), category(PHYSICAL){
    this->name=name;
    this->accuracy=accuracy;
}

Move::Move(std::string name, int accuracy, Type type): id(noMoves++), pp(0), maxPp(0), category(PHYSICAL){
    this->name=name;
    this->accuracy=accuracy;
    this->type=type;
}

Move::Move(std::string name, int accuracy, Type type, int pp): id(noMoves++), maxPp(0), category(PHYSICAL){
    this->name=name;
    this->accuracy=accuracy;
    this->type=type;
    this->pp=pp;
}

Move::Move(std::string name, int accuracy, Type type, int pp, int maxPp): id(noMoves++), category(PHYSICAL) {
    this->name=name;
    this->accuracy=accuracy;
    this->type=type;
    this->pp=pp;
    this->maxPp=maxPp;
}

Move::Move(std::string name, int accuracy, Type type, int pp, int maxPp, MoveCategory category): id(noMoves++) {
    this->name=name;
    this->accuracy=accuracy;
    this->type=type;
    this->pp=pp;
    this->maxPp=maxPp;
    this->category=category;
}

Move::Move(const Move &obj): id(noMoves++){
    this->name=obj.name;
    this->accuracy=obj.accuracy;
    this->type=obj.type;
    this->pp=obj.pp;
    this->maxPp=obj.maxPp;
    this->category=obj.category;
}

Move::~Move() {}

Move &Move::operator=(const Move &obj) {
    if (this!=&obj) {
        this->name=obj.name;
        this->accuracy=obj.accuracy;
        this->type=obj.type;
        this->pp=obj.pp;
        this->maxPp=obj.maxPp;
        this->category=obj.category;
    }
    return *this;
}

Type Move::getType() {
    return type;
}

std::istream &operator<<(std::istream &is, Move &obj) {
    std::string typeStr, categoryStr;
    std::cout<<"Name: ";
    getline(is, obj.name);

    std::cout<<"Accuracy: ";
    getline(is, obj.name);

    std::cout << "Type: ";
    is >> typeStr;

    std::cout << "PP: ";
    is >> obj.pp;

    obj.maxPp = obj.pp;

    std::cout << "Category (PHYSICAL/STATUS): ";
    is >> categoryStr;
    return is;
}

std::ostream &operator>>(std::ostream &os, const Move &obj) {
    os<<"Name: "<<obj.getName()<<"\n";
    os<<"Accuracy: "<<obj.accuracy<<"\n";
    os<<"Type: "<<"\n";
    os<<"PP: "<< obj.pp<<" ";
    os<<"Max PP: "<<obj.maxPp<<" ";
    os<<"Category"<<obj.category<<" ";
    return os;
}

MoveCategory Move::getCategory() const { return category; }
void Move::useMove() {
    if (pp > 0) {
        pp--;
    } else {
        std::cout << "No more PP left for this move!\n";
    }
}

void Move::restorePP() {
    pp=maxPp;
}

std::string Move::getName() const {
    return name;
}
