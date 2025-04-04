#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed!" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destructed!" << std::endl;
}

// Overridden attack method
void ScavTrap::attack(const std::string& target) {
    if (energyPoints <= 0 || hitPoints <= 0) {
        std::cout << "ScavTrap " << name << " cannot attack, not enough energy or HP!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " fiercely attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

// Guard gate method
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!" << std::endl;
}
