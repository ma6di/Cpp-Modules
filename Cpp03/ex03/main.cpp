#include "DiamondTrap.hpp"

int main() {
    // Create DiamondTrap
    DiamondTrap diamond("Diamonious");

    // Test functionality
    diamond.attack("Enemy");  // Uses ScavTrap's attack
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.whoAmI();  // Displays both names

    return 0;
}
