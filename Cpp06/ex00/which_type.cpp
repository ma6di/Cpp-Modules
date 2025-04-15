/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_type.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:18:09 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/15 14:19:10 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*It checks:
isSpecial(str) → nan, +inf, -inf, etc.
isChar(str, len) → 'a' or single non-digit char.
isInt(str, len) → decimal digits only, +/- allowed.
isFloat(str, len, dot) → has . and ends in f
Else → must be DOUBLE.*/

static int	isSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return 1;
	return 0;
}

static int	isChar(const std::string& str, size_t& len)
{
	if (len == 1 && !isdigit(str[0]))
		return 1;
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return 1;
	return 0;
}

static int	isInt(const std::string& str, size_t& len)
{
	int		i = 0;
	bool	flag = false;

	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		flag = 1;
	}
	while ((str[i] && len > 0 && len < 12) || (str[i] && !flag && len > 0 && len < 11))
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

//dot: the index of the . character already found in whichType().
/*
This walks backwards from the character before the dot (.) to the beginning of the string.
For all characters before the dot except the first character, it expects digits only.
For the first character str[0], it allows a digit OR a sign (+ or -).

Second loop walks forward from the character after the dot to the end of the string.
It expects only digits, except one trailing 'f' at the end.
If 'f' is present, it must be the last character (i == len - 1), or else it's invalid.*/
static int	isFloat(const std::string& str, size_t& len, size_t& dot)
{
	for (int j = dot - 1; j >= 0; j--)
	{
		if (!isdigit(str[j]) && j != 0)
			return 0;
		if (!isdigit(str[j]) && j == 0 && str[j] != '+' && str[j] != '-')
			return 0;
	}
	for (size_t i = dot + 1; i < len; i++)
	{
		if (!isdigit(str[i]) && str[i] != 'f')
			return 0;
		if (str[i] == 'f' && i != len - 1)
			return 0;
	}
	return 1;
}

/*static const size_t npos = -1;
	It's a constant of type std::string::size_type (which is usually size_t).
	It is the largest possible value for size_t, which means it’s guaranteed to be greater
		than the length of any string.
	It is used to indicate “not found” in string search operations.*/
//If "." "f" is not in the string, .find() returns npos (== std::string::npos)
e_type  whichType(const std::string& str, size_t& len)
{
    size_t  dot = str.find('.');
    size_t  f = str.find('f');
	
    if (dot == std::string::npos)
    {
        if (isSpecial(str))
            return SPECIAL;
        if (isChar(str, len))
            return CHAR;
        if (isInt(str, len))
            return INT;
    }
    if (f != std::string::npos && dot != std::string::npos)
    {
        if (isFloat(str, len, dot))
        	return FLOAT;
    }
    else if (f == std::string::npos && dot != std::string::npos)
        return DOUBLE;
    return INVALID;
}
