#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif

/*The Weapon reference in HumanA implies that HumanA does not own the Weapon object; instead, it relies on an external Weapon object managed elsewhere.
This design ensures that changes to the external Weapon object are immediately reflected in the HumanA class.*/