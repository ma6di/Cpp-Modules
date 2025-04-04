#include "Zombie.hpp"

// Function to create a horde of zombies
Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        std::cerr << "Error: Number of zombies must be greater than 0." << std::endl;
        return NULL;
    }

    // Allocate memory for N zombies in a single allocation
    Zombie* horde = new Zombie[N];

    // Initialize each zombie with the given name
    for (int i = 0; i < N; ++i) {
        horde[i].setName(name);
    }
	
    return horde;
}
