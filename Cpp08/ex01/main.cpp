/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:09:59 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/22 14:10:01 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

int main() {
    try {
        std::cout << "=== Basic Functionality Test ===" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected: 2
        std::cout << "Longest Span : " << sp.longestSpan() << std::endl << std::endl; ;  // Expected: 14

        std::cout << "\n=== Exception Test (Add More Than Capacity) ===" << std::endl;
        try {
            sp.addNumber(42); // Should throw
        } catch (const std::exception &e) {
            std::cerr << "Caught exception: " << e.what() << std::endl << std::endl; ;
        }

        std::cout << "\n=== Exception Test (Span with < 2 elements) ===" << std::endl;
        Span sp2(1);
        sp2.addNumber(1);
        try {
            std::cout << sp2.shortestSpan() << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Caught exception: " << e.what() << std::endl << std::endl; ;
        }

		std::cout << "\n=== Add Range with Iterators ===" << std::endl;
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
		Span sp3(5);
		sp3.addNumbers(vec.begin(), vec.end());
		std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl; // Expected: 10
		std::cout << "Longest Span : " << sp3.longestSpan() << std::endl << std::endl;  // Expected: 40
		
		std::cout << "\n=== Add Range with Two Integer ===" << std::endl;
		Span sp4(5);
		sp4.addNumbersRange(1001,1005);
		std::cout << "Shortest Span: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp4.longestSpan() << std::endl << std::endl; ;

        std::cout << "\n=== Performance Test with 10,000 Numbers ===" << std::endl;
        Span bigSpan(10000);
        for (int i = 0; i < 10000; ++i) {
            bigSpan.addNumber(i * 2);
        }
        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl; // Expected: 2
        std::cout << "Longest Span : " << bigSpan.longestSpan() << std::endl;  // Expected: 19998

    } catch (const std::exception &e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
