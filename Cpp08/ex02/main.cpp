/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:10:19 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/22 15:28:34 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main()
{
    // Creating the MutantStack
    MutantStack<int> mstack;

    // Push a variety of elements to the stack
    for (int i = 1; i <= 10; ++i)
        mstack.push(i * 10); // Pushing 10, 20, ..., 100

    // Output the top and size of the stack
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;

    // Forward iteration using the iterator
    std::cout << "\nForward iteration:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Reverse iteration using the reverse iterator
    std::cout << "\nReverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    // Using const reverse iterator on a const MutantStack
    const MutantStack<int> constStack = mstack;

    std::cout << "\nConst Reverse iteration:" << std::endl;
    for (MutantStack<int>::const_reverse_iterator crit = constStack.rbegin(); crit != constStack.rend(); ++crit)
        std::cout << *crit << " ";
    std::cout << std::endl;

    // Push a few more elements to demonstrate dynamic behavior
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nAfter pushing additional elements:" << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;

    // Iterating forward after pushing new elements
    std::cout << "\nForward iteration after pushing new elements:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Pop a few elements from the stack
    mstack.pop();
    mstack.pop();

    std::cout << "\nAfter popping two elements:" << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;

    // Demonstrating copying MutantStack to a standard stack and iterating
    std::stack<int> s(mstack);
    std::cout << "\nElements in copied std::stack:" << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    return 0;
}
