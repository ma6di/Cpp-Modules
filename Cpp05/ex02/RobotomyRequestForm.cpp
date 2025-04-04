#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", 72, 45), target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeRequiredToExecute())
        throw GradeTooLowException();

    std::cout << "Drilling noises... ";
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed!\n";
}
