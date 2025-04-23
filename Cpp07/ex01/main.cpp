/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:45:59 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/23 13:33:21 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    // Test case 1: Array of integers
    int arrInt[] = {1, 2, 3, 4, 5};
	int lenInt = sizeof(arrInt) / sizeof(arrInt[0]);
	std::cout << "Integer array before: ";
	iter(arrInt, lenInt, printElement); 
	std::cout << std::endl;
    std::cout << "Integer array (doubled): ";
    iter(arrInt, lenInt, doubleElement);  // Pass array, length, and double function
	iter(arrInt, lenInt, printElement); 
	std::cout << std::endl << std::endl;;

    // Test case 2: Array of doubles
    double arrDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int lenDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);
	std::cout << "Double array before: ";
	iter(arrDouble, lenDouble, printElement);
	std::cout << std::endl;
    std::cout << "Double array (doubled): ";
    iter(arrDouble, lenDouble, doubleElement);  // Pass array, length, and double function
	iter(arrDouble, lenDouble, printElement);
    std::cout << std::endl << std::endl;

    // Test case 3: Array of strings (const char*)
    std::string arrStr[] = {"Hello", "World", "Test"};
    int lenStr = sizeof(arrStr) / sizeof(arrStr[0]);
    std::cout << "String array (printed): ";
    iter(arrStr, lenStr, printElement);  // Pass array, length, and print function
    std::cout << std::endl;
	std::cout << "Double array (doubled): ";
	iter(arrStr, lenStr, doubleStrElement);
	iter(arrStr, lenStr, printElement);
	
    return 0;
}
