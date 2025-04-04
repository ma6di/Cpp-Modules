#include "Dog.hpp"

// Constructor
Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created." << std::endl;
}

// Destructor
Dog::~Dog() {
    std::cout << "Dog destroyed." << std::endl;
}

// Overridden function
void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
