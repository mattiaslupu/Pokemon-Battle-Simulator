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

    if (!file.is_open()) {
        throw std::runtime_error("Critical error: Cannot open file " + filename + "!");
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line == "\r") continue;

        std::stringstream ss(line);
        std::string attackerStr, defenderStr, multiplierStr;

        std::getline(ss, attackerStr, ',');
        std::getline(ss, defenderStr, ',');
        std::getline(ss, multiplierStr, ',');

        try {
            Type attacker = stringToType(attackerStr);
            Type defender = stringToType(defenderStr);
            double multiplier = std::stod(multiplierStr);

            chart[attacker][defender] = multiplier;
        } catch (const std::exception& e) {
            std::cout << "Warning: Invalid rule ignored in TypeChart.txt - " << e.what() << "\n";
        }
    }
    file.close();
}

double TypeChart::getMultiplier(Type attacker, Type defender) const {
    if (attacker == FIRE_FLYING) {
        throw std::invalid_argument("Error: An attack cannot be FIRE_FLYING! Attacks have a single type.");
    }

    if (defender == FIRE_FLYING) {
        return chart[attacker][FIRE] * chart[attacker][FLYING];
    }

    return chart[attacker][defender];
}

TypeChart::~TypeChart() {}

std::ostream& operator<<(std::ostream& os, const TypeChart& obj) {
    os << "--- TYPE CHART (Special Rules) ---\n";
    bool hasRules = false;

    for (int i = 0; i < NUM_TYPES; i++) {
        for (int j = 0; j < NUM_TYPES; j++) {
            if (obj.chart[i][j] != 1.0) {
                hasRules = true;
                os << typeToString(static_cast<Type>(i)) << " attacks "
                   << typeToString(static_cast<Type>(j)) << " -> X "
                   << obj.chart[i][j] << "\n";
            }
        }
    }

    if (!hasRules) {
        os << "No special rules found. All attacks do 1.0x damage.\n";
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

    std::cout << "Multiplier (ex: 2.0 or 0.5): ";
    if (!(is >> multiplier)) {
        is.clear();
        is.ignore(1000, '\n');
        throw std::invalid_argument("Multiplier must be a decimal number!");
    }

    Type attacker = stringToType(attackerStr);
    Type defender = stringToType(defenderStr);

    obj.chart[attacker][defender] = multiplier;
    std::cout << "Rule added successfully!\n";

    return is;
}