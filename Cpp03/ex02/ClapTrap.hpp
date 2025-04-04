#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    // Constructors and Destructor
    ClapTrap(const std::string& name);
    virtual ~ClapTrap(); // Use virtual to allow proper destruction of derived objects

    // Member functions
    virtual void attack(const std::string& target); // Virtual for polymorphism
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
