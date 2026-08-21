#pragma once
#include <stack>
#include <iostream>

class Rpn {
	private:
		std::stack<std::string> m_stack;
	public:
		Rpn();
		Rpn(const std::string& expression);
		~Rpn();
		Rpn(const Rpn& other);
		Rpn operator=(const Rpn& other);
		void startRPN(std::string expression);
};