#include "Animal.hpp"

// Constructor
Animal::Animal() : type("Animal") {
    std::cout << "Animal created." << std::endl;
}

// Destructor
Animal::~Animal() {
    std::cout << "Animal destroyed." << std::endl;
}

// Getter
std::string Animal::getType() const {
    return type;
}
