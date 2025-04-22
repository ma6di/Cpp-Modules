/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:07:59 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/22 15:19:04 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
