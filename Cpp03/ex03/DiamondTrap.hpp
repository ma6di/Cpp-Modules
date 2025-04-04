#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string name;  // DiamondTrap's own name

public:
    DiamondTrap(const std::string& name);
    ~DiamondTrap();

    using ClapTrap::takeDamage;   // Resolve ambiguity
    using ClapTrap::beRepaired;   // Resolve ambiguity

    void attack(const std::string& target);
    void whoAmI();
};


#endif
