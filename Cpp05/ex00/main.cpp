#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;

		b1.incrementGrade();  // Should work
		std::cout << b1 << std::endl;

		b1.incrementGrade();  // Should throw GradeTooHighException
		std::cout << b1 << std::endl; // This line will NOT execute because the exception was thrown earlier.

		std::cout << "Before Copy Constructor" << std::endl;
		Bureaucrat b2(b1);  // Copy Constructor
		std::cout << "After Copy Constructor" << std::endl;

		b2.incrementGrade();
		std::cout << b2 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

    try {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;

        b2.decrementGrade();  // Should throw GradeTooLowException
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 200);  // Should throw GradeTooLowException in constructor
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught while creating bureaucrat: " << e.what() << std::endl;
    }

    return 0;
}
