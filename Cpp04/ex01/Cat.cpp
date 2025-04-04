#include "Cat.hpp"

// Constructor
Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat created." << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copied." << std::endl;
}

// Destructor
Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed." << std::endl;
}

// Assignment Operator
Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

// Overridden Methods
void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

// Brain Access
void Cat::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}
