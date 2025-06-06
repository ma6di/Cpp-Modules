/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:00:45 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/23 13:30:30 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>


template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

//const 
/*Allows passing:
	-Temporaries: min(3, 4)
	-Const values
	-Regular variables
	-Avoids copying large objects unnecessarily
	-Communicates clearly: “These inputs won’t be changed.”*/
template <typename T>
const T& min(const T& data1, const T& data2)
{
	if (data2 > data1)
		return data1;
	return data2;
}

template <typename T>
const T& max(const T& data1, const T& data2)
{
	if (data2 < data1)
		return data1;
	return data2;
}
