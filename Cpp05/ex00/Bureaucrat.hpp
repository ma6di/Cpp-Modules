
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat 
{
	private:
		const std::string	name;
		int	grade;

	public:
		Bureaucrat(const std::string name, int grade);

		Bureaucrat(const Bureaucrat& other); //Copy Constructor takes an existing 
		//Bureaucrat object and It creates a new object with the same values as other.
		//other is just a parameter name.
		//It represents the existing Bureaucrat object that we want to copy.
		//We need other because the copy constructor's job is to copy an existing object.
		//other contains the data we need to copy into the new object.
		//Instead of making up a new name like source, other is a common convention.

		Bureaucrat& operator = (const Bureaucrat& other);
		//Bureaucrat& / Return type: Returns a reference to *this (the current object).
		//operator=	/ Overloaded assignment operator.
		//(const Bureaucrat& other)	/ Takes a constant reference to another Bureaucrat object
		~Bureaucrat();

		//The const after the function signature means that this function does not 
		//modify the object. This is called a const member function.
		//const before the return type	No effect in this case (const std::string would mean the return value is constant).
		//const after the function signature	
		//Prevents modifying member variables inside the function.
		std::string getName() const;
		int	getGrade() const;

		void incrementGrade();
    	void decrementGrade();

		//it's just a standalone custom exception class
		//An exception class represents an error condition that can be thrown and caught.
		//It inherits from std::exception, which is the base class for all standard exceptions in C++.
		//what() is a virtual function from std::exception that returns an error message.
		//It returns a const char* (C-style string).
		//throw() means this function does not throw exceptions itself.


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
};

//This function overloads the insertion (<<) operator so that we can print 
//a Bureaucrat object directly using std::cout or any other output stream.
//std::ostream&	/// Return type: This function returns a reference to an output stream (std::ostream).
//operator<<	//// This overloads the << operator for Bureaucrat objects.
//(std::ostream& os, const Bureaucrat& b)	//// Arguments: an output stream (os, e.g., std::cout) and 
//a const reference to a Bureaucrat object (b).
std::ostream& operator<<(std::ostream& os, const Bureaucrat&b);

#endif  // BUREAUCRAT_HPP