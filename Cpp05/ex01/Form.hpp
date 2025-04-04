
#ifndef FROM_HPP
#define FROM_HPP

#include <iostream>
#include <stdbool.h>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeRequiredToSign;
    	const int gradeRequiredToExecute;
	
	public:
		//In C++, passing large objects like std::string by value involves copying the entire 
		//object, which can be inefficient (especially if it's done frequently).
		Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);		
		Form(const Form &other);
		Form& operator= (const Form &other);
		~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeRequiredToSign() const;
		int getGradeRequiredToExecute() const;

    	void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream&, const Form& f);

#endif //FROM_HPP