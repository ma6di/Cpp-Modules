#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    // Constructors and Destructor
    FragTrap(const std::string& name);
    ~FragTrap();

    // Special functionality
    void highFivesGuys(void);
};

#endif // FRAGTRAP_HPP
