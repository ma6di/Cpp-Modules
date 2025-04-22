/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:45:33 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/22 12:45:35 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept> // For std::out_of_range

template <typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;

public:
    Array();                             // Default constructor
    Array(unsigned int n);              // Constructor with size
    Array(const Array& other);          // Copy constructor
    Array& operator=(const Array& other); // Assignment operator
    ~Array();                           // Destructor

    T& operator[](unsigned int index);             // Subscript operator
    const T& operator[](unsigned int index) const; // Const version

    unsigned int size() const;          // Size getter
};

#include "Array.tpp"  // Include the implementation at the end
