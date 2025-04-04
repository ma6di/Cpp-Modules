#include <iostream>
#include "Fixed.hpp"

int main(void) {
    // Create some Fixed objects for testing
    Fixed a;  // Default constructor
    Fixed const b(5.05f);  // Fixed with float constructor
    Fixed const c(2);      // Fixed with int constructor
    Fixed const d(3.14f);  // Fixed with float constructor

    // Display initial values
    std::cout << "Initial values:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    // Comparison operators
    std::cout << "\nComparison operators:" << std::endl;
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b >= c: " << (b >= c) << std::endl;
    std::cout << "b <= c: " << (b <= c) << std::endl;
    std::cout << "b == c: " << (b == c) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    // Arithmetic operators
    std::cout << "\nArithmetic operators:" << std::endl;
    std::cout << "b + c: " << b + c << std::endl; //equivalent to b.operator+(c);
    std::cout << "b - c: " << b - c << std::endl;
    std::cout << "b * c: " << b * c << std::endl;
    std::cout << "b / c: " << b / c << std::endl;

    // Increment and Decrement operators
    std::cout << "\nIncrement/Decrement operators:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;  // Pre-increment
    std::cout << "a after pre-increment: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;  // Post-increment
    std::cout << "a after post-increment: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;  // Pre-decrement
    std::cout << "a after pre-decrement: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;  // Post-decrement
    std::cout << "a after post-decrement: " << a << std::endl;

    // Static min/max functions
    std::cout << "\nStatic min/max functions:" << std::endl;
    std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

    std::cout << "min(a, d): " << Fixed::min(a, d) << std::endl;
    std::cout << "max(a, d): " << Fixed::max(a, d) << std::endl;

    return 0;
}
