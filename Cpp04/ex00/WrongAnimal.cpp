#include "WrongAnimal.hpp"

// Constructor
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal created." << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed." << std::endl;
}

// Function
void WrongAnimal::makeSound() const {
    std::cout << "Wrong animal sound." << std::endl;
}

// Getter
std::string WrongAnimal::getType() const {
    return type;
}
