#include "Fixed.hpp"

int main() {
    Fixed a; // default constructor
    Fixed b(a); //copy constructor
    Fixed c; //default constructor
    c = b; //copy assignment operator

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
