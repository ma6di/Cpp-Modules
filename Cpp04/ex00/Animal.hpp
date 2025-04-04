#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    // Constructor and Destructor
    Animal();
    virtual ~Animal();

    // Virtual function
    virtual void makeSound() const;

    // Getter
    std::string getType() const;
};

#endif // ANIMAL_HPP
