#include "Zombie.hpp"

// Dynamically creates a zombie, sets its name, and returns it
Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name);
    return zombie;
}
