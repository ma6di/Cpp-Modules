#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0) {}

// Constructor with int
Fixed::Fixed(const int intValue) {
    _value = intValue << _fractionalBits;
}

// Constructor with float
Fixed::Fixed(const float floatValue) {
    _value = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    *this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_value != other._value;
}

// Arithmetic operators// return the result as a new Fixed object.
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._value = this->_value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._value = this->_value - other._value;
    return result;
}

//The product of two fixed-point values needs to account for the fractional part,
// which is why you shift the result by _fractionalBits to preserve the fixed-point 
//format.
Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result._value = (this->_value * other._value) >> _fractionalBits;
    return result;
}

//In division, to prevent loss of precision, you multiply the numerator
// by (1 << _fractionalBits) before dividing by the denominator.
Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result._value = (this->_value << _fractionalBits) / other._value;
    return result;
}

// Increment/Decrement operators

// ++a Pre-increment
//increases the raw value (_value) and returns a reference to the updated object.
Fixed& Fixed::operator++() { 
    ++_value;
    return *this;
}
//a++  Post-increment
//method saves a copy of the current object, increments it, and returns the original object.
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() { // Pre-decrement
    --_value;
    return *this;
}

Fixed Fixed::operator--(int) { // Post-decrement
    Fixed temp = *this;
    --(*this);
    return temp;
}

// Member functions
int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

// Static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Overload insertion operator
//In C++, operator overloading allows you to define custom behaviors 
//for standard operators (like +, -, *, ==, etc.) when they are used 
//with user-defined types (such as your Fixed class).
//When you define a custom operator for your class, you're essentially 
//telling the C++ compiler: "When the operator is used on instances of my class, 
//call this specific function.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
