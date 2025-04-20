
#include <iostream>
#include "Array.hpp"

int main()
{
    try {
        Array<int> a(3);
        a[0] = 10;
        a[1] = 20;
        a[2] = 30;

        std::cout << "Array size: " << a.size() << "\n";

        for (unsigned int i = 0; i < a.size(); ++i)
            std::cout << "a[" << i << "] = " << a[i] << "\n";

        // Trigger exception
        std::cout << "Trying to access a[3]:\n";
        std::cout << a[3] << "\n"; // This will throw
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
