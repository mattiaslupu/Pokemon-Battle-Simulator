#pragma once
#include <string>
#include "Pokemon.h"


Type stringToType(const std::string& str);
std::string typeToString(Type t);
MoveCategory stringToCategory(const std::string& str);
StatusType stringToStatus(const std::string& str);