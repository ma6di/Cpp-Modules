#include "Dog.hpp"

// Constructor
Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog created." << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copied." << std::endl;
}

// Destructor
Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed." << std::endl;
}

// Assignment Operator
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

// Overridden Methods
void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

// Brain Access
void Dog::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}
