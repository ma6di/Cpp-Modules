#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _value;                 // Raw fixed-point value
    static const int _fractionalBits = 8; // Number of fractional bits 
                                          //Static: Shared by all instances of the class
                                          //Keeps all Fixed-point numbers consistent.

public:
    Fixed();                              // Default constructor
    Fixed(const Fixed& other);            // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed();                             // Destructor

    // Member functions
    int getRawBits(void) const;           // Get raw value
    void setRawBits(int const raw);       // Set raw value
};

#endif
