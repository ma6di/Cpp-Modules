#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        Form form1("Tax Form", 3, 5);

        std::cout << form1 << std::endl;
        b1.signForm(form1);
        std::cout << form1 << std::endl;  // Should now be signed

        Bureaucrat b2("Bob", 50);
        Form form2("Confidential Form", 10, 20);

        std::cout << form2 << std::endl;
        b2.signForm(form2);  // Should fail due to low grade
        std::cout << form2 << std::endl;  // Should still be unsigned
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
