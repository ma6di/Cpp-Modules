#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // Constructors and Destructor
    ScavTrap(const std::string& name);
    ~ScavTrap();

    // Overridden attack method
    void attack(const std::string& target) override;

    // New functionality
    void guardGate();
};

#endif // SCAVTRAP_HPP
