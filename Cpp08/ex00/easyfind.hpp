
#pragma once

#include <algorithm>
#include <exception>
#include <iterator>

class ParameterNotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found in container.";
    }
};

template <typename T>
int easyfind(T& container, int p);  // Declaration

#include "easyfind.tpp"
