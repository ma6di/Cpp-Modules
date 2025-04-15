
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/*What is dynamic_cast?
dynamic_cast is used in C++ to safely convert pointers or references within an inheritance hierarchy, 
typically when you have a base class pointer/reference and want to know what the actual derived type is.
It checks the actual runtime type of the object and returns the appropriate result or throws an exception.


/*What is static_cast?
static_cast is a compile-time cast in C++. It’s used for conversions that are well-defined 
and don't require runtime type checking. Unlike dynamic_cast, it does not check the actual 
type at runtime, so it’s faster, but also riskier if used incorrectly.*/

Base *generate(void)
{
	std::srand(static_cast<unsigned>(std::time(NULL)));
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

//catch (...) catches any kind of exception
//istaed of using const std::bad_cast& e)
void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (...) {
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch (...) {
			try {
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch (...) {
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}

int main() {

    // Generate and test multiple times
    for (int i = 0; i < 5; ++i) {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        
        Base* ptr = generate();

        std::cout << "Using pointer: ";
        identify(ptr);

        std::cout << "Using reference: ";
        identify(*ptr);

        std::cout << "-------------------" << std::endl;

        delete ptr;
    }

	class D : public Base {};
	Base* obj = new D();
	std::cout << "Using pointer: ";
	identify(obj); // should not match A, B, or C

	std::cout << "Using reference: ";
	identify(*obj); // should reach the "Unknown type" catch block

	delete obj;

    return 0;
}
