#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    // Constructor and Destructor
    WrongAnimal();
    virtual ~WrongAnimal();

    // Function
    void makeSound() const;

    // Getter
    std::string getType() const;
};

#endif // WRONGANIMAL_HPP
