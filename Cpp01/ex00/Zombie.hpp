#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie();                     // Default constructor
    explicit Zombie(std::string name); // Constructor with a name parameter
    ~Zombie();                    // Destructor

    void announce() const;        // Announce the zombie
};

#endif
