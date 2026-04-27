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
    if (accuracy < 0 || accuracy > 100)
        throw std::invalid_argument("Accuracy must be between 0 and 100");
    if (pp < 0)
        throw std::invalid_argument("PP cannot be negative");
    if (maxPp < pp)
        throw std::invalid_argument("maxPp cannot be less than pp");
    this->name = name;
    this->accuracy = accuracy;
    this->type = type;
    this->pp = pp;
    this->maxPp = maxPp;
    this->category = category;
}

Move::Move(const Move &obj): id(noMoves++){
    this->name=obj.name;
    this->accuracy=obj.accuracy;
    this->type=obj.type;
    this->pp=obj.pp;
    this->maxPp=obj.maxPp;
    this->category=obj.category;
}

int Move::getPP() const {
    return pp;
}

int Move::getMaxPP() const {
    return maxPp;
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
Type Move::getType() const {
    return type;
}

std::ostream& operator<<(std::ostream& os, const Move& obj) {
    os << "Name: " << obj.name << "\n";
    os << "Accuracy: " << obj.accuracy << "\n";
    os << "Type: " << typeToString(obj.type) << "\n";
    os << "PP: " << obj.pp << "/" << obj.maxPp << "\n";
    os << "Category: " << obj.category << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Move& obj) {
    std::string typeStr, categoryStr;

    std::cout << "Name: ";
    std::getline(is, obj.name);
    if (obj.name.empty())
        throw std::invalid_argument("Move name cannot be empty");

    std::cout << "Accuracy (0-100): ";
    is >> obj.accuracy;
    if (is.fail() || obj.accuracy < 0 || obj.accuracy > 100)
        throw std::invalid_argument("Accuracy must be between 0 and 100");

    std::cout << "Type: ";
    is >> typeStr;
    obj.type = stringToType(typeStr);

    std::cout << "PP: ";
    is >> obj.pp;
    if (is.fail() || obj.pp < 0)
        throw std::invalid_argument("PP cannot be negative");
    obj.maxPp = obj.pp;
    is.ignore();
    return is;
}

MoveCategory Move::getCategory() const { return category; }
void Move::useMove() {
    if (pp <= 0)
        throw std::runtime_error("No PP left for move: " + name);
    pp--;
}

void Move::restorePP() {
    if (maxPp < 0)
        throw std::runtime_error("Invalid maxPp for move: " + name);
    pp = maxPp;
}

std::string Move::getName() const {
    return name;
}
