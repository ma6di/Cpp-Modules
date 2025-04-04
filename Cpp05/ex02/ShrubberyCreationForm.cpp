#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {}


//This executes the form’s action, which is to
//create a file and write an ASCII tree in it.
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw GradeTooLowException();

	std::ofstream file((target + "_shrubbery").c_str()); // ✅ Fix applied
	if (file.is_open()) {
		file << "🌲🌳🌲 Shrubbery 🌳🌲🌳\n";
		file.close();
		std::cout << "Shrubbery created at " << target << "_shrubbery\n";
	} else {
		std::cerr << "Error: Could not create " << target << "_shrubbery file.\n";
	}
}
	
