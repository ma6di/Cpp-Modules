
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
    		: name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), 
			gradeRequiredToExecute(gradeRequiredToExecute)
{
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
        throw GradeTooHighException();
    if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
        throw GradeTooLowException();
}

// Copy Constructor
AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), 
      gradeRequiredToSign(other.gradeRequiredToSign), 
      gradeRequiredToExecute(other.gradeRequiredToExecute) {}

// Copy Assignment Operator
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm(){}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeRequiredToSign() const
{
    return gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const
{
    return gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeRequiredToSign)
        isSigned = true;
	else
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "Form Name: " << f.getName() << "\n"
       << "Signed: " << (f.getIsSigned() ? "Yes" : "No") << "\n"
       << "Grade Required to Sign: " << f.getGradeRequiredToSign() << "\n"
       << "Grade Required to Execute: " << f.getGradeRequiredToExecute() << "\n";
    return os;
}