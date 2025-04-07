#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"



/*Why use srand(time(0))?
It seeds the randomness using the current time, which changes every 
second — giving a new pattern every time you run the program. That’s much more realistic 
randomness for something like "robotomy success or fail".*/
int main() {
    srand(time(0));

    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    ShrubberyCreationForm shrub("Home");
    RobotomyRequestForm robot("Target1");
    PresidentialPardonForm pardon("Alice");

    boss.signForm(shrub);
    boss.signForm(robot);
    boss.signForm(pardon);

    boss.executeForm(shrub);
    boss.executeForm(robot);
    boss.executeForm(pardon);

    return 0;
}

