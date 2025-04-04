#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor with int 
Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    _value = intValue << _fractionalBits; // Shift left to include fractional bits
}                                         // Multiply by 256 (shift left)

// Constructor with float
Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_value = other._value;  // Directly copy the value
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Get raw value
int Fixed::getRawBits(void) const {
    return this->_value;
}

// Set raw value
void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

// Convert to float 
// The 1 << _fractionalBits is equivalent to 2^_fractionalBits
//The static_cast<float>(_value) converts the integer value of _value to a float before 
//performing the division.
float Fixed::toFloat(void) const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

// Convert to int
//The right shift operator (>>) divides the value by 2^_fractionalBits, 
//discarding any fractional part that was stored.
int Fixed::toInt(void) const {
    return _value >> _fractionalBits; // Shift right to remove fractional bits
}

// Overload insertion operator to output its value to an output stream
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();        //This writes the Fixed object's floating-point representation (via fixed.toFloat()) to the output stream.
    return os;
}
