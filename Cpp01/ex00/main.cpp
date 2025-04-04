#include "Zombie.hpp"

// Declare the functions
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    std::cout << "Creating a zombie on the heap:" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    std::cout << "Destroying the heap zombie:" << std::endl;
    delete heapZombie;

    std::cout << "Creating a zombie on the stack:" << std::endl;
    randomChump("StackZombie");

    std::cout << "End of the program." << std::endl;

    return 0;
}
