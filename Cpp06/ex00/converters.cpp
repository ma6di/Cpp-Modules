/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:02:10 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/16 15:17:20 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

//static_cast is a compile-time cast in C++.
void	convertChar(const std::string& str, size_t& len)
{
	char	c = 0;

	if (len == 1)
		c = str[0];
	else
		c = str[1];
	std::cout << "char: ";
	if (isprint(c))
	{
		std::cout << "'" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
		std::cout << "Non displayable" << std::endl;
}

	//.c_str() gives you a C-style null-terminated string (const char*) — which is required by strtol.
	//end is a pointer to char*. 
	//After conversion, strtol updates end to point to the first invalid character in the string.
	// 10 is the numerical base to use for conversion.
void convertInt(const std::string& str)
{
	int		impossible = 0;
    char* 	end;
    errno = 0;
    long	l = std::strtol(str.c_str(), &end, 10);
	
	// CHAR
	std::cout << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else if (isprint(static_cast<char>(l)))
		std::cout << "'" << static_cast<char>(l) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
		
    // INT
    std::cout << "int: ";
    if (*end != '\0' || errno == ERANGE || l < MIN_INT || l > MAX_INT)
	{
		std::cout << "impossible" << std::endl;
		impossible = 1;
	}
    else
		std::cout << static_cast<int>(l) << std::endl;

	//  FLOAT
	std::cout << "float: ";
	if (impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(l) << ".0f" << std::endl;

	//  DOUBLE
	std::cout << "double: ";
	if (impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<double>(l) << ".0" << std::endl;
}

void convertFloat(const std::string& str)
{
    errno = 0;
    int impossible = 0;
    float f = std::atof(str.c_str());
    bool tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;

    // CHAR
    std::cout << "char: ";
    if (f < 0 || f > 127)
        std::cout << "impossible" << std::endl;
    else if (isprint(static_cast<char>(f)))
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    // INT
    std::cout << "int: ";
    if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;

    // FLOAT
    if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max() || errno == ERANGE)
    {
        std::cout << "float: impossible" << std::endl;
        impossible = 1;
    }
    else
        std::cout << "float: " << f << (tolerance ? ".0f" : "f") << std::endl;

    // DOUBLE
    if (f > std::numeric_limits<double>::max() || f < -std::numeric_limits<double>::max() || impossible)
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(f) << (tolerance ? ".0" : "") << std::endl;
}

void convertDouble(const std::string& str)
{
    errno = 0;
    double d = std::atof(str.c_str());
    bool tolerance = std::fabs(d - static_cast<int>(d)) < 0.0000000000001;

    // CHAR
    std::cout << "char: ";
    if (d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (isprint(static_cast<char>(d)))
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    // INT
    std::cout << "int: ";
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    // FLOAT
    std::cout << "float: ";
    if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max() || errno == ERANGE)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<float>(d) << (tolerance ? ".0f" : "f") << std::endl;

    // DOUBLE
    if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max() || errno == ERANGE)
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << d << (tolerance ? ".0" : "") << std::endl;
}


