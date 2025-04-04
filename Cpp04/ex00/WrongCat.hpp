#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    // Constructor and Destructor
    WrongCat();
    ~WrongCat();

    // Function
    void makeSound() const;
};

#endif // WRONGCAT_HPP
