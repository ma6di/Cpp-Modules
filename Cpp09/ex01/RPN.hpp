#pragma once

#include <stack>
#include <string>

class RPN {
	private:
		std::stack<int> _stack;
		std::string _expression;
		int evaluate();
	public:
		RPN(const std::string& expression);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		int getResult();
};

