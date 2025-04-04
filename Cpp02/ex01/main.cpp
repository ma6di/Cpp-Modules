#include "Fixed.hpp"

int main() {
    Fixed a; //Default constructor
    Fixed const b(10); //Integer constructor
    Fixed const c(42.42f); //Float constructor

    
    Fixed const d(b); //Copy constructor 

    //A temporary Fixed object is created with the float 1234.4321f, using the float constructor.
    //After the temporary object is created, the copy assignment operator is called to assign this value to a.
    //After the assignment is made, the temporary object (Fixed(1234.4321f)) goes out of scope, which triggers its destruction
    a = Fixed(1234.4321f); 

    //a is the floating-point number 1234.4321f but when printed with toFloat(), 
    //it gets rounded to two decimal places, showing 1234.43.
    std::cout << "a is " << a << std::endl; 
    //b is an integer (10), so when printed, it shows 10.
    std::cout << "b is " << b << std::endl;
    //c is 42.42f, but when converted to a fixed-point representation and printed,
    //it appears as 42.4219f (slightly different due to rounding).
    std::cout << "c is " << c << std::endl;
    //d is a copy of b, so it prints 10.
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
