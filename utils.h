#pragma once
#include <string>


enum Type { NORMAL, FIRE, WATER, GRASS, ELECTRIC, ICE, ROCK, FLYING, FIRE_FLYING, NUM_TYPES };
enum MoveCategory { PHYSICAL, SPECIAL, STATUS };
enum StatusType { NONE, BURN, SLEEP, PARALYSIS, POISON };

Type stringToType(const std::string& str);
std::string typeToString(Type t);
MoveCategory stringToCategory(const std::string& str);
StatusType stringToStatus(const std::string& str);