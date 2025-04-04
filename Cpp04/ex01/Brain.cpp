#include "Brain.hpp"

// Constructor
Brain::Brain() {
    std::cout << "Brain created." << std::endl;
}

// Copy Constructor
Brain::Brain(const Brain& other) {
    std::cout << "Brain copied." << std::endl;
    *this = other;
}

// Destructor
Brain::~Brain() {
    std::cout << "Brain destroyed." << std::endl;
}

// Assignment Operator
Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

// Set an idea
void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

// Get an idea
std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}
