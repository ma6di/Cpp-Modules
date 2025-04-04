#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Test ClapTrap
    ClapTrap clap("CL4P-TP");
    clap.attack("target1");
    clap.takeDamage(3);
    clap.beRepaired(5);

    // Test ScavTrap
    ScavTrap scav("SC4V-TP");
    scav.attack("target2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    return 0;
}
