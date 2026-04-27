
#include "utils.h"
#include <stdexcept>

Type stringToType(const std::string &str) {
    if (str == "NORMAL") return NORMAL;
    if (str == "FIRE") return FIRE;
    if (str == "WATER") return WATER;
    if (str == "GRASS") return GRASS;
    if (str == "ELECTRIC") return ELECTRIC;
    if (str == "ICE") return ICE;
    if (str == "ROCK") return ROCK;
    if (str == "FLYING") return FLYING;
    if (str == "FIRE_FLYING") return FIRE_FLYING;
    throw std::invalid_argument("Invalid type: " + str);
}

std::string typeToString(Type t) {
    switch (t) {
        case NORMAL: return "Normal";
        case FIRE: return "Fire";
        case WATER: return "Water";
        case GRASS: return "Grass";
        case ELECTRIC: return "Electric";
        case ICE: return "Ice";
        case ROCK: return "Rock";
        case FLYING: return "Flying";
        case FIRE_FLYING: return "Fire/Flying";
        default: return "Unknown";
    }
}
MoveCategory stringToCategory(const std::string& str) {
    if (str == "PHYSICAL") return PHYSICAL;
    if (str == "SPECIAL") return SPECIAL;
    if (str == "STATUS") return STATUS;
    throw std::invalid_argument("Invalid category: " + str);
}
StatusType stringToStatus(const std::string& str)
{
    if (str == "NONE") return NONE;
    if (str == "BURN") return BURN;
    if (str == "SLEEP") return SLEEP;
    if (str == "PARALYSIS") return PARALYSIS;
    if (str == "POISON") return POISON;
    throw std::invalid_argument("Invalid status: " + str);
}

std::string typeToStringUpper(Type t) {
    switch (t) {
        case FIRE:       return "FIRE";
        case WATER:      return "WATER";
        case GRASS:      return "GRASS";
        case ELECTRIC:   return "ELECTRIC";
        case ICE:        return "ICE";
        case ROCK:       return "ROCK";
        case FLYING:     return "FLYING";
        case FIRE_FLYING:return "FIRE_FLYING";
        default:         return "NORMAL";
    }
}
