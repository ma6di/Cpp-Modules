
#pragma once

#include <iostream>
#include <string>

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
const T& myMin(const T& data1, const T& data2)
{
	if (data2 < data1 || data1 == data2)
		return data2;
	return data1;
}
	
template <typename T>
const T& myMax(const T& data1, const T& data2)
{
	if (data2 > data1 || data1 == data2)
		return data2;
	return data1;
}
