/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:08:12 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/22 14:15:44 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
	try {
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);

		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);

		std::deque<int> deq;
		deq.push_back(100);
		deq.push_back(200);
		deq.push_back(300);

		std::cout << "Vector: 2 Found at index " << easyfind(vec, 2) << std::endl;
		std::cout << "List: 30 Found at index " << easyfind(lst, 30) << std::endl;
		std::cout << "Deque: 100 Found at index " << easyfind(deq, 100) << std::endl;

		easyfind(vec, 99);  // Will throw
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
