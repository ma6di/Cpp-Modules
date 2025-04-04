#include "WrongCat.hpp"

// Constructor
WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat created." << std::endl;
}

// Destructor
WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed." << std::endl;
}

// Function
void WrongCat::makeSound() const {
    std::cout << "Wrong cat sound." << std::endl;
}
