#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"




int main() {
    srand(time(NULL));

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

