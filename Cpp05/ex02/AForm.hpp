#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration

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
