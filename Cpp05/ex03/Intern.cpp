#include "Intern.hpp"
#include <iostream>

// Constructor & Destructor
Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

// Functions to create forms (C++98 doesn't allow lambdas)
static AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
static AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
static AForm* createPresidential(const std::string& target) { return new PresidentialPardonForm(target); }

// Function to create a form
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    // Struct to store form names and corresponding creation functions
    struct FormEntry {
        const char* name;
        AForm* (*create)(const std::string&);
    };

    // Array of known forms
    FormEntry forms[3] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPresidential}
    };

    // Search for the requested form
    for (int i = 0; i < 3; i++) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    // If form is not found
    std::cerr << "Error: Intern could not find the form \"" << formName << "\"." << std::endl;
    return NULL;
}
