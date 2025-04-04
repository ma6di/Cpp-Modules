#include "Intern.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "Garden");
    AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Alice");
    AForm* form4 = someRandomIntern.makeForm("unknown form", "Target"); // Should print an error

    // Clean up allocated memory
    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}
