#include <iostream>
#include "Point.hpp"
#include "bsp.hpp"  // Include the header where functions are declared

int main() {
    // Create the points of the triangle
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    // Create a point to test
    Point p(3.0f, 3.0f);

    // Check if the point is inside the triangle
    if (bsp(a, b, c, p)) {
        std::cout << "The point is inside the triangle." << std::endl;
    } else {
        std::cout << "The point is outside the triangle." << std::endl;
    }

    return 0;
}
