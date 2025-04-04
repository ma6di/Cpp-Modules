#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value; // Raw fixed-point value
    static const int _fractionalBits = 8; // Number of fractional bits

public:
    // Constructors and Destructor
    Fixed();                              // Default constructor
    Fixed(const int intValue);            // Constructor with int
    Fixed(const float floatValue);        // Constructor with float
    Fixed(const Fixed& other);            // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed();                             // Destructor

    // Member functions
    int getRawBits(void) const;           // Get raw value
    void setRawBits(int const raw);       // Set raw value
    float toFloat(void) const;            // Convert to float
    int toInt(void) const;                // Convert to int

    // Overload insertion operator //Allows printing the Fixed object 
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif
