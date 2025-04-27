
#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

int RPN::evaluate(const std::string& expression)
{
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
                throw std::runtime_error("Error");
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
                    throw std::runtime_error("Error");
                result = a / b;
            }
            numbers.push(result);
        }
		else
		{
            throw std::runtime_error("Error");
        }
    }

    if (numbers.size() != 1)
	{
        throw std::runtime_error("Error");
    }

    return numbers.top();
}
