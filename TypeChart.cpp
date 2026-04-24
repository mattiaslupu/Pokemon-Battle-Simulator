#include "TypeChart.h"

TypeChart::TypeChart() {
    for (int i = 0; i < NUM_TYPES; i++) {
        for (int j = 0; j < NUM_TYPES; j++) {
            chart[i][j] = 1.0;
        }
    }
}


TypeChart::TypeChart(const TypeChart& obj) {
    for (int i = 0; i < NUM_TYPES; i++) {
        for (int j = 0; j < NUM_TYPES; j++) {
            chart[i][j] = obj.chart[i][j];
        }
    }
}

TypeChart& TypeChart::operator=(const TypeChart& obj) {
    if (this != &obj) {
        for (int i = 0; i < NUM_TYPES; i++) {
            for (int j = 0; j < NUM_TYPES; j++) {
                chart[i][j] = obj.chart[i][j];
            }
        }
    }
    return *this;
}

void TypeChart::loadFromFile(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;
    //error handle
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string attackerStr, defenderStr, multiplierStr;

        std::getline(ss, attackerStr, ',');
        std::getline(ss, defenderStr, ',');
        std::getline(ss, multiplierStr, ',');

        Type attacker = stringToType(attackerStr);
        Type defender = stringToType(defenderStr);
        double multiplier = std::stod(multiplierStr);

        chart[attacker][defender] = multiplier;
    }
}

double TypeChart::getMultiplier(Type attacker, Type defender) const {
    if (defender==FIRE_FLYING) {
        return chart[attacker][FIRE]* chart[attacker][FLYING];
    }
    else if (attacker==FIRE_FLYING) {
        //error handle
    }
    return chart[attacker][defender];

}


TypeChart::~TypeChart() {}


std::ostream& operator<<(std::ostream& os, const TypeChart& obj) {
    os << "--- TYPE CHART (Special Rules) ---\n";
    for (int i = 0; i < NUM_TYPES; i++) {
        for (int j = 0; j < NUM_TYPES; j++) {

            if (obj.chart[i][j] != 1.0) {
                os << typeToString(static_cast<Type>(i)) << " attacks "
                   << typeToString(static_cast<Type>(j)) << " -> X "
                   << obj.chart[i][j] << "\n";
            }
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, TypeChart& obj) {
    std::string attackerStr, defenderStr;
    double multiplier;

    std::cout << "Attacker (ex: FIRE): ";
    is >> attackerStr;

    std::cout << "Defender (ex: WATER): ";
    is >> defenderStr;

    std::cout << "Multiplier: ";
    is >> multiplier;

    Type attacker = stringToType(attackerStr);
    Type defender = stringToType(defenderStr);

    obj.chart[attacker][defender] = multiplier;
    return is;
}