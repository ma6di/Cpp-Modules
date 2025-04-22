/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:45:53 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/22 14:35:11 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// For const arrays — calls a function that takes a const reference
template <typename T>
void iter(const T* array, int len, void (*f)(const T&))
{
    for (int i = 0; i < len; i++)
    {
        f(array[i]);
    }
}

// For non-const arrays — calls a function that takes a non-const reference
template <typename T>
void iter(T* array, int len, void (*f)(T&))
{
    for (int i = 0; i < len; i++)
    {
        f(array[i]);
    }
}

// Function to print the element
template <typename T>
void printElement(const T &elem)
{
    std::cout << elem << " ";
}

// Function to double the element
template <typename T>
void doubleElement(T &elem)
{
    elem = elem * 2;  // Modify the element by reference (double it)
}

template <typename T>
void doubleStrElement(T &elem)
{
	elem = elem + elem;
}


