#pragma once
#include "Pokemon.h"
#include "utils.h"
#include <fstream>
#include <sstream>

class TypeChart {
private:
    double chart[NUM_TYPES][NUM_TYPES];

public:
    TypeChart();
    TypeChart(const TypeChart& obj);
    TypeChart& operator=(const TypeChart& obj);
    ~TypeChart();
    void loadFromFile(std::string filename);
    double getMultiplier(Type attacker, Type defender) const;
    friend std::ostream& operator<<(std::ostream& os, const TypeChart& obj);
    friend std::istream& operator>>(std::istream& is, TypeChart& obj);
};
