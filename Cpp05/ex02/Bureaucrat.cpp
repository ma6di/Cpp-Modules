
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}
Bureaucrat::~Bureaucrat() {}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

// Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.grade;  // Name is constant, can't be changed
    return *this;
}

std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade()
{
	if(grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if(grade >= 150)
		throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException:: what() const throw()
{
	return "Grade too high! (Max: 1)";
}

const char* Bureaucrat::GradeTooLowException:: what() const throw()
{
	return "Grade too low! (Min: 150)";
}

void Bureaucrat::signForm(AForm &form)
{
    try
	{
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } 
	catch (std::exception &e)
	{
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << getName() << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
