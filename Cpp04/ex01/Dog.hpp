#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain;

public:
    // Constructor and Destructor
    Dog();
    Dog(const Dog& other);
    ~Dog();

    // Assignment Operator
    Dog& operator=(const Dog& other);

    // Overridden Methods
    void makeSound() const override;

    // Brain Access
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif // DOG_HPP
