#include "Zombie.hpp"

// Default constructor
Zombie::Zombie() : name("Unnamed") {}

// Constructor with a name parameter
Zombie::Zombie(std::string name) : name(name) {}

// Destructor
Zombie::~Zombie() {
    std::cout << "Zombie " << name << " is destroyed." << std::endl;
}

// Set the zombie's name
void Zombie::setName(std::string name) {
    this->name = name;
}

// Announce method
void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


/*this Pointer
this is a special pointer available in non-static member functions of a class.
It points to the current object on which the member function is being called.
Using this-> helps specify that you're referring to the member variable of the class, not a local variable or parameter.*/