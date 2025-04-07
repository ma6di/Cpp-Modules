
#include "Bureaucrat.hpp"
#include "Form.hpp"

//// Constructor with grade validation
//Bureaucrat:: → This specifies that we are defining the constructor outside the class.
//Bureaucrat(...) → This is the constructor, which initializes a Bureaucrat object.
//: name(name) --> This initializes the name attribute using a member initialization list.
//The member variable name (on the left) is initialized with the constructor argument name (on the right).
//name is const, so it must be initialized immediately.

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



void Bureaucrat::signForm(Form &form)
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
//This function is an overloaded version of the << (insertion) operator that 
//allows us to output a Bureaucrat object using std::cout or other output streams like file streams.
//std::ostream& os: This is the output stream (like std::cout) where the data will be written.
//const Bureaucrat& b: This is the const reference to the Bureaucrat object whose details will be printed.
//b.getName(): This is a getter function for the name attribute of the Bureaucrat object.
//os <<: The << operator is used to send the name to the output stream os (which could be std::cout).
//os << ", bureaucrat grade "; -> This is just a literal string that is printed along with the name.
//return os; The output stream os is returned, which allows chaining of output statements. 
//For example: -> std::cout << bureaucrat1 << bureaucrat2;
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}