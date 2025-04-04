#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructed!" << std::endl;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destructed!" << std::endl;
}

// High fives method
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}
