#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    // Constructor and Destructor
    Dog();
    ~Dog();

    // Overridden function
    void makeSound() const override;
};

#endif // DOG_HPP
