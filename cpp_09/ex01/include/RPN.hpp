#pragma once
#include <stack>
#include <iostream>

enum OperandType {
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION,
	UNKNOWN
};

class Rpn {
	private:
		std::stack<int> m_stack;
		unsigned int		m_intAmount;
	public:
		Rpn() = delete;
		Rpn(const std::string& expression);
		~Rpn(); 
		Rpn(const Rpn& other);
		Rpn operator=(const Rpn& other);
		void startRPN(std::string expression);
		bool isTokenValid(const std::string& token);
		bool isTokenDigit(const std::string& token);
		bool applyOperation(const std::string& operand);
		bool getResult(long long num1, long long num2, const std::string& operand);
		OperandType operandFromString(const std::string& operand);
	};