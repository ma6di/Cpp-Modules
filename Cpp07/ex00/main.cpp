
#include "whatever.hpp"

int main()
{
    // INT
	std::cout << "int" << std::endl;
    int a = 10, b = 20;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
    std::cout << "min(a, b) = " << myMin(a, b) << std::endl;
    std::cout << "max(a, b) = " << myMax(a, b) << std::endl;
    swap(a, b);
    std::cout << "swapped: a=" << a << ", b=" << b << std::endl << std::endl;

    // FLOAT
	std::cout << "float" << std::endl;
    float x = 5.5f, y = 2.3f;
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
    std::cout << "min(x, y) = " << myMin(x, y) << std::endl;
    std::cout << "max(x, y) = " << myMax(x, y) << std::endl;
    swap(x, y);
    std::cout << "swapped: x=" << x << ", y=" << y << std::endl << std::endl;

    // CHAR
	std::cout << "char" << std::endl;
    char c1 = 'z', c2 = 'a';
	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl;
    std::cout << "min(c1, c2) = " << myMin(c1, c2) << std::endl;
    std::cout << "max(c1, c2) = " << myMax(c1, c2) << std::endl;
    swap(c1, c2);
    std::cout << "swapped: c1=" << c1 << ", c2=" << c2 << std::endl << std::endl;

    // STRING
	std::cout << "string" << std::endl;
    std::string s1 = "apple", s2 = "banana";
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
    std::cout << "min(s1, s2) = " << myMin(s1, s2) << std::endl;
    std::cout << "max(s1, s2) = " << myMax(s1, s2) << std::endl;
    swap(s1, s2);
    std::cout << "swapped: s1=" << s1 << ", s2=" << s2 << std::endl << std::endl;

    return 0;
}
