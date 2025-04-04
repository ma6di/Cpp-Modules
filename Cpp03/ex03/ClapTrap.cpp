#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

// Attack method
void ClapTrap::attack(const std::string& target) {
    if (energyPoints <= 0 || hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot attack, not enough energy or HP!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

// Take damage method
void ClapTrap::takeDamage(unsigned int amount) {
    hitPoints -= amount;
    if (hitPoints < 0) hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage! HP now: " << hitPoints << std::endl;
}

// Repair method
void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints <= 0 || hitPoints <= 0) {
        std::cout << "ClapTrap " << name << " cannot repair, not enough energy or HP!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself by " << amount
              << " points! HP now: " << hitPoints << std::endl;
}
