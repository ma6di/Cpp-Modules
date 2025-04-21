#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    // Push a variety of elements
    for (int i = 1; i <= 10; ++i)
        mstack.push(i * 10); // Push 10, 20, ..., 100

    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;

    std::cout << "\nForward iteration:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "\nReverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    // Copy to const MutantStack to demonstrate const_reverse_iterator
    const MutantStack<int> constStack = mstack;

    std::cout << "\nConst Reverse iteration:" << std::endl;
    for (MutantStack<int>::const_reverse_iterator crit = constStack.rbegin(); crit != constStack.rend(); ++crit)
        std::cout << *crit << " ";
    std::cout << std::endl;

    // Pop a few elements
    mstack.pop();
    mstack.pop();

    std::cout << "\nAfter popping two elements:" << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;

    return 0;
}
