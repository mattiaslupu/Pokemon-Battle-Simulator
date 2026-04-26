#include "Menu.h"
#include <iostream>

int main() {
    try {
        Menu menu;
        menu.run();
    } catch (std::invalid_argument& e) {
        std::cerr << "Input error: " << e.what() << "\n";
        return 1;
    } catch (std::out_of_range& e) {
        std::cerr << "Range error: " << e.what() << "\n";
        return 1;
    } catch (std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << "\n";
        return 1;
    } catch (std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}