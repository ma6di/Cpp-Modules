
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{ }

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter(void)
{ }

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

void    ScalarConverter::convert(const std::string& str)
{
    size_t  len = str.length();
    e_type  type = whichType(str, len);
    switch(type)
    {
        case INVALID:
            std::cout << "Invalid input" << std::endl;
            break;
        case SPECIAL:
            printSpecial(str);
            break;
        case CHAR:
            convertChar(str, len);
            break;
        case INT:
            convertInt(str);
            break;
        case FLOAT:
            convertFloat(str);
            break;
        case DOUBLE:
            convertDouble(str);
            break;
    }
}
