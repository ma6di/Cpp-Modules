#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string ideas[100]; // Array of ideas

public:
    // Constructor and Destructor
    Brain();
    Brain(const Brain& other);
    ~Brain();

    // Assignment Operator
    Brain& operator=(const Brain& other);

    // Methods
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif // BRAIN_HPP
