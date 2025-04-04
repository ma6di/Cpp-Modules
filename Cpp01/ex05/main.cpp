#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "=== DEBUG Level ===" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\n=== INFO Level ===" << std::endl;
    harl.complain("INFO");

    std::cout << "\n=== WARNING Level ===" << std::endl;
    harl.complain("WARNING");

    std::cout << "\n=== ERROR Level ===" << std::endl;
    harl.complain("ERROR");

    std::cout << "\n=== Unknown Level ===" << std::endl;
    harl.complain("CRITICAL");

    return 0;
}
