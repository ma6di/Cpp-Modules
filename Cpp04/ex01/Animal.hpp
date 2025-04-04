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

    // Virtual Methods
    virtual void makeSound() const = 0; // Pure virtual function

    // Getter
    std::string getType() const;
};

#endif // ANIMAL_HPP
