
#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

int RPN::evaluate(const std::string& expression)
{
	/*iss is like a "scanner" to read words from the string, one by one (3, 4, +, etc.).
	token is a small storage for each word.*/
    std::stack<int> numbers;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
	{
        if (token.length() == 1 && isdigit(token[0])) {
            numbers.push(token[0] - '0'); // Convert char to int
        }
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
            if (numbers.size() < 2)
			{
                throw std::runtime_error("Error: Oprator should be after two numbers");
            }
            int b = numbers.top();
			numbers.pop();
            int a = numbers.top();
			numbers.pop();
            int result = 0;
            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else if (token == "/")
			{
                if (b == 0)
                    throw std::runtime_error("Error: Devision by zero is not possible");
                result = a / b;
            }
            numbers.push(result);
        }
		else
		{
            throw std::runtime_error("Error: Wrong input");
        }
    }

    if (numbers.size() != 1)
	{
        throw std::runtime_error("Error: Wrong input");
    }

    return numbers.top();
}
