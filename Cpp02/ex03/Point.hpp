#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    // Constructors
    Point();
    Point(float x, float y);
    Point(const Point &other);

    // Copy assignment operator
    Point &operator=(const Point &other);

    // Destructor
    ~Point();

    // Getters for x and y coordinates
    Fixed getX() const;
    Fixed getY() const;
};

#endif
