
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
    		: name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), 
			gradeRequiredToExecute(gradeRequiredToExecute)
{
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
        throw GradeTooHighException();
    if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
        throw GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), 
      gradeRequiredToSign(other.gradeRequiredToSign), 
      gradeRequiredToExecute(other.gradeRequiredToExecute) {}

// Copy Assignment Operator
Form &Form::operator=(const Form &other)
{
    if (this != &other) {
        this->isSigned = other.isSigned;
        // name, gradeRequiredToSign, and gradeRequiredToExecute are const, so they cannot be changed
    }
    return *this;
}

Form::~Form(){}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeRequiredToSign() const
{
    return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const
{
    return gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeRequiredToSign)
        isSigned = true;
	else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form Name: " << f.getName() << "\n"
       << "Signed: " << (f.getIsSigned() ? "Yes" : "No") << "\n"
       << "Grade Required to Sign: " << f.getGradeRequiredToSign() << "\n"
       << "Grade Required to Execute: " << f.getGradeRequiredToExecute() << "\n";
    return os;
}