/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:45:39 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/23 13:40:22 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

class Person
{
	private:
		std::string _name;
	
	public:
		Person() : _name("Unnamed") {}
		Person(const std::string& name) : _name(name) {}
		Person(const Person& other) : _name(other._name) {}
	
		Person& operator=(const Person& other)
		{
			if (this != &other)
				_name = other._name;
			return *this;
		}
	
		std::string getName() const { return _name; }
};
	
int main()
{
	// Test with empty Array
	std::cout << "Empty Array: ";
	Array<int> emptyArray(3);
	for (unsigned int i = 0; i < emptyArray.size(); ++i)
		std::cout << emptyArray[i] << " ";
	std::cout << "\n";

	// Test with int (simple type)
	Array<int> intArray(3);
	intArray[0] = 10;
	intArray[1] = 20;
	intArray[2] = 30;

	std::cout << "Int Array: ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << intArray[i] << " ";
	std::cout << "\n";

	// Test with std::string
	Array<std::string> strArray(2);
	strArray[0] = "hello";
	strArray[1] = "world";

	std::cout << "String Array: ";
	for (unsigned int i = 0; i < strArray.size(); ++i)
		std::cout << strArray[i] << " ";
	std::cout << "\n";

	// Test with Person
	Array<Person> personArray(2);
	personArray[0] = Person("Alice");
	personArray[1] = Person("Bob");

	std::cout << "Class Person Array: ";
	for (unsigned int i = 0; i < personArray.size(); ++i)
		std::cout << personArray[i].getName() << " ";
	std::cout << "\n";
	
	return 0;
}
	