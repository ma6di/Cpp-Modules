#include "Zombie.hpp"

// Default Constructor
Zombie::Zombie() : name("Unnamed") {}

// Constructor with a name parameter
Zombie::Zombie(std::string name) : name(name) {}

// Destructor
Zombie::~Zombie() {
    std::cout << "Zombie " << name << " is destroyed." << std::endl;
}

// Announce method
void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
