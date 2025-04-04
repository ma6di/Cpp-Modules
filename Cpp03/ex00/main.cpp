#include "ClapTrap.hpp"

int main() {
    // Create a ClapTrap instance
    ClapTrap clap("CL4P-TP");

    // Demonstrate functionality
    clap.attack("target1");
    clap.takeDamage(3);
    clap.beRepaired(5);
    clap.takeDamage(20); // Excessive damage to set HP to 0
    clap.beRepaired(3);  // Should fail due to 0 HP

    return 0;
}
