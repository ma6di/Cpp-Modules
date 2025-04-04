#include "Zombie.hpp"

// Declare the function
Zombie* zombieHorde(int N, std::string name);

int main() {
    int N = 5; // Number of zombies
    std::string name = "ZombieHorde";

    std::cout << "Creating a horde of " << N << " zombies..." << std::endl;

    // Create the horde
    Zombie* horde = zombieHorde(N, name);

    // Check if the horde was created successfully
    if (!horde) {
        std::cerr << "Failed to create the zombie horde." << std::endl;
        return 1;
    }

    // Make each zombie announce itself
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }

    std::cout << "Destroying the horde..." << std::endl;

    // Free the allocated memory
    delete[] horde;

    return 0;
}

/*delete: Used to deallocate memory for a single object.
delete[]: Used to deallocate memory for an array of objects.*/