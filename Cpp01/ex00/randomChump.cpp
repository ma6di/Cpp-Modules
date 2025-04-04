#include "Zombie.hpp"

// Creates a zombie on the stack, sets its name, and announces itself
void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}
