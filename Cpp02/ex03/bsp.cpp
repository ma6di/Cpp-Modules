#include "bsp.hpp"
#include <cmath>  // For abs() and other necessary functions

// Function to calculate the area of a triangle
float area(Point const &a, Point const &b, Point const &c) {
    return 0.5f * std::abs((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
                           (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
                           (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())));
}

// Function to check if the point is inside the triangle
bool bsp(Point const &a, Point const &b, Point const &c, Point const &point) {
    // Calculate the area of the triangle ABC
    float areaABC = area(a, b, c);

    // Calculate the area of the three triangles PAB, PBC, and PCA
    float areaPAB = area(point, a, b);
    float areaPBC = area(point, b, c);
    float areaPCA = area(point, c, a);

    // The point is inside the triangle if the sum of areas of PAB, PBC, and PCA
    // is equal to the area of the triangle ABC
    return (areaPAB + areaPBC + areaPCA == areaABC);
}
