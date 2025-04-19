
#pragma once

#include <iostream>

template <typename T>
void iter(T *array, int len, void (*f)(T&))
{
    for (int i = 0; i < len; i++)
    {
        f(array[i]);  // Apply the function 'f' to each element in the array by reference
    }
}

// Function to print the element
template <typename T>
void printElement(T elem)
{
    std::cout << elem << " ";
}

// Function to double the element
template <typename T>
void doubleElement(T &elem)
{
    elem = elem * 2;  // Modify the element by reference (double it)
}

// Overload to handle the doubling function on non-reference types.
template <typename T>
void doubleElementConst(T elem)
{
    std::cout << elem * 2 << " ";
}