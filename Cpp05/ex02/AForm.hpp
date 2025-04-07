#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

/*
You can use forward declarations when:
	You're only using pointers or references to the forward-declared type.
You cannot use forward declarations when:
	You need the size or members of the class (e.g., creating an object or calling its methods directly)
A forward declaration is when you tell the compiler:
	“Hey, trust me — this class or struct exists. I’ll show you the full definition later.”*/

class Bureaucrat; // Forward declaration

//Using an abstract base class (like AForm) lets you define a common interface for
// different forms while allowing each type of form to have its own specific behavior 
//(like writing to a file, making noise, or printing a pardon). This gives you polymorphism, code reuse, and flexibility
class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeRequiredToSign;
    const int gradeRequiredToExecute;

public:
    AForm(const std::string &name, int gradeSign, int gradeExec);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);

    virtual void execute(Bureaucrat const &executor) const = 0; // Pure virtual function

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
		virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
		virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
