
#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cerrno>  // For errno


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

void convertInt(const std::string& str)
{
    char* end;
    errno = 0;
    long l = std::strtol(str.c_str(), &end, 10);
	
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
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(l) << std::endl;


    // FLOAT & DOUBLE
    std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
}


void	convertFloat(const std::string& str)
{
	float	f = std::atof(str.c_str());
	/*This line checks whether the float f is "very close" to an integer — 
	within a very tiny margin (tolerance) due to floating-point imprecision.

	1. static_cast<int>(f)
	This converts the float f to an integer, effectively removing the decimal part (truncates toward zero).
	For example:
	f = 42.0000001  →  static_cast<int>(f) = 42
	f = 7.9999999   →  static_cast<int>(f) = 7

	2. f - static_cast<int>(f)
	This gives you the decimal (fractional) part of the float.
	For example:
	f = 42.3       →  f - 42  = 0.3
	f = 7.0000001  →  f - 7   = ~0.0000001

	3. std::fabs(...)
	This gives the absolute value, so that you're always comparing a positive number.
	For example:
	f = -42.0000001 → static_cast<int>(f) = -42
	fabs(-42.0000001 - (-42)) = fabs(-0.0000001) = 0.0000001
	4. < 0.0000000000001
	This is the tolerance threshold, saying:

	“If the fractional part is less than this, we’ll consider the float to be effectively an integer.”

	This helps avoid situations where due to floating-point precision limits, a value like 42.0 might 
	internally be 41.999999999999996.
*/
	bool	tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;

	// CHAR
	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(f))
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		else 
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (static_cast<long>(f) < MIN_INT || static_cast<long>(f) > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
    //  FLOAT
	std::cout << "float: ";
	if (f < MIN_FLOAT || f > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << (tolerance ? ".0f" : "f") << std::endl;
    // DOUBLE
	std::cout << "double: " << static_cast<double>(f) << (tolerance ? ".0" : "") << std::endl;
}

void	convertDouble(const std::string& str)
{
	double		d = std::atof(str.c_str());
	bool		tolerance = std::fabs(d - static_cast<int>(d)) < 0.0000000000001;

	// CHAR
	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(d))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else 
			std::cout << "Non displayable" << std::endl;
	}
    // INT
	std::cout << "int: ";
	if (d < MIN_INT || d > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
    //  FLOAT
	std::cout << "float: ";
	if (d < MIN_FLOAT || d > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << (tolerance ? ".0f" : "f") << std::endl;
    //  DOUBLE
	std::cout << "double: ";
	if (d < MIN_DOUBLE || d > MAX_DOUBLE)
		std::cout << "impossible" << std::endl;
	else
		std::cout << d << std::endl;
}
