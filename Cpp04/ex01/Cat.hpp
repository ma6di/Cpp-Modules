#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* brain;

public:
    // Constructor and Destructor
    Cat();
    Cat(const Cat& other);
    ~Cat();

    // Assignment Operator
    Cat& operator=(const Cat& other);

    // Overridden Methods
    void makeSound() const override;

    // Brain Access
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif // CAT_HPP
