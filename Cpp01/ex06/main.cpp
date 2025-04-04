#include "Harl.hpp"

#include "Harl.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log_level>" << std::endl;
        return 1;
    }

    Harl harl;
    harl.filter(argv[1]); // Call filter directly
    return 0;
}

