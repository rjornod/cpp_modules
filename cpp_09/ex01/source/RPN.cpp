#include "RPN.hpp"
#include <string>
#include <limits>

Rpn::Rpn(const std::string& expression) : m_intAmount(0) {
	startRPN(expression);
}

Rpn::~Rpn() {}

Rpn::Rpn(const Rpn& other) : m_stack(other.m_stack), m_intAmount(m_intAmount) {}

Rpn Rpn::operator=(const Rpn& other) {
  if (this != &other) {
    m_stack = other.m_stack;
		m_intAmount = other.m_intAmount;
  }
  return *this;
}

void Rpn::startRPN(std::string expression) {
  if (expression.empty())
		return;
  size_t end = 0;
  std::string temp;
  while (!expression.empty()) {
    end = expression.find_first_of(" \t\n\r\f\v");
    temp = expression.substr(0, end);
		expression.erase(0, expression.find_first_not_of(" \t\n\r\f\v", end));
		if (isTokenDigit(temp)) {
			m_intAmount++;
			int token = std::stoll(temp);
			m_stack.push(token);
		}
		else if (isTokenValid(temp) && m_intAmount >= 2) {
			if (!applyOperation(temp)) {
				std::cerr << "Error\n";
				return;
			}
		}
		else {
			std::cerr << "Error\n";
			return;
		}
		if (expression.empty() && m_intAmount != 1) {
			std::cerr << "Error\n";
			return;
		}
		if (end == std::string::npos)
      expression.clear();
  }
	std::cout << m_stack.top() << std::endl;
}

bool Rpn::isTokenValid(const std::string& token) {
 return token == "+"  || 
 				token == "-" || 
				token == "*" ||
				token == "/"; 
}

bool Rpn::isTokenDigit(const std::string& token) {
	size_t i = 0;
	while (i < token.size()) {
		if (!std::isdigit(token[i])) {
			return false;
		}
		i++;
	}
	try {
		std::string tempString = token;
		unsigned long temp = std::stoul(tempString.c_str());
		if ( std::numeric_limits<int>::max() < temp ) {
			
			throw std::out_of_range("Error too big");
    }
	}
	catch (const std::out_of_range &e) {
		return false;
	}
	return true;
}

bool Rpn::applyOperation(const std::string& operand) {
	long long num1 = m_stack.top();
	m_stack.pop();
	long long num2 = m_stack.top();
	m_stack.pop();
	if (!getResult(num1, num2, operand)) 
		return false;
	return true;
}

bool Rpn::getResult(long long num1, long long num2, const std::string& operand) {
	long long result;
	switch (operandFromString(operand)) {
		case OperandType::ADDITION:
			result = num2 + num1;
			break;
		case OperandType::SUBTRACTION:
			result = num2 - num1;
			break;
		case OperandType::DIVISION:
			if (num1 == 0)
				return false;
			result = num2 / num1;
			break;
		case OperandType::MULTIPLICATION:
			result = num2 * num1;
			break;
		case UNKNOWN:
			return false;

	}	
	if (result > 2147483647)
		return false;
	m_stack.emplace(result);
	m_intAmount--;
	return true;
}

OperandType Rpn::operandFromString(const std::string& operand) {
	if (operand == "+") return OperandType::ADDITION;
	if (operand == "-") return OperandType::SUBTRACTION;
	if (operand == "*") return OperandType::MULTIPLICATION;
	if (operand == "/")	return OperandType::DIVISION;
	else 								return OperandType::UNKNOWN;
}
