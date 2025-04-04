#include "DiamondTrap.hpp"
#include <iostream>

// Constructor
DiamondTrap::DiamondTrap(const std::string& newName)
    : ClapTrap(newName + "_clap_name"), ScavTrap(newName), FragTrap(newName), name(newName) {
    hitPoints = FragTrap::hitPoints;  // Get HP from FragTrap
    energyPoints = ScavTrap::energyPoints;  // Get EP from ScavTrap
    attackDamage = FragTrap::attackDamage;  // Get AD from FragTrap

    std::cout << "DiamondTrap " << name << " created!" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}

// Resolving attack ambiguity: Use ScavTrap's attack function
void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);  // Explicitly call ScavTrap's attack
}

// New method: whoAmI()
void DiamondTrap::whoAmI() {
    std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << "!" << std::endl;
}
