#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    // Test FragTrap
    FragTrap frag("FR4G-TP");
    frag.attack("target3");
    frag.takeDamage(50);
    frag.beRepaired(30);
    frag.highFivesGuys();

    return 0;
}
