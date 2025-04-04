#include "Point.hpp"

// Default constructor (initializes x and y to 0)
Point::Point() : _x(0), _y(0) {
    std::cout << "Point default constructor called" << std::endl;
}

// Constructor that initializes x and y from floating-point values
Point::Point(float x, float y) : _x(x), _y(y) {
    std::cout << "Point parameterized constructor called" << std::endl;
}

// Copy constructor
Point::Point(const Point &other) : _x(other._x), _y(other._y) {
    std::cout << "Point copy constructor called" << std::endl;
}

// Copy assignment operator
Point &Point::operator=(const Point &other) {
    std::cout << "Point copy assignment operator called" << std::endl;
    if (this != &other) {
        // The attributes are const, so we cannot change them.
        // No need to assign anything here, it's just an empty operator.
    }
    return *this;
}

// Destructor
Point::~Point() {
    std::cout << "Point destructor called" << std::endl;
}

// Getter for x
Fixed Point::getX() const {
    return _x;
}

// Getter for y
Fixed Point::getY() const {
    return _y;
}
