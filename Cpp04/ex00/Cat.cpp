#include "Cat.hpp"

// Constructor
Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created." << std::endl;
}

// Destructor
Cat::~Cat() {
    std::cout << "Cat destroyed." << std::endl;
}

// Overridden function
void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
