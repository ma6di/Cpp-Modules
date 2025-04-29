
#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <iostream>


RPN::RPN(const std::string& expression) : _expression(expression)
{
	evaluate();
}

RPN::~RPN(){};

RPN::RPN(const RPN& other)
	: _stack(other._stack), _expression(other._expression) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_stack = other._stack;
		_expression = other._expression;
	}
	return *this;
}

int RPN::evaluate()
{
	/*iss is like a "scanner" to read words from the string, one by one (3, 4, +, etc.).
	token is a small storage for each word.*/
    std::istringstream iss(_expression);
    std::string token;

    while (iss >> token)
	{
        if (token.length() == 1 && isdigit(token[0])) {
            _stack.push(token[0] - '0'); // Convert char to int
        }
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
            if (_stack.size() < 2)
			{
                throw std::runtime_error("Error: Oprator should be after two numbers");
            }
            int b = _stack.top();
			_stack.pop();
            int a = _stack.top();
			_stack.pop();
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
            _stack.push(result);
        }
		else
		{
            throw std::runtime_error("Error: Wrong input");
        }
    }

    if (_stack.size() != 1)
	{
        throw std::runtime_error("Error: Wrong input");
    }

    return _stack.top();
}

int RPN::getResult()
{
	return _stack.top();
}
