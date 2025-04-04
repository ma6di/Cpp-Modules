#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    // Constructor and Destructor
    Cat();
    ~Cat();

    // Overridden function
    void makeSound() const override;
};

#endif // CAT_HPP
