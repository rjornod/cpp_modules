#include "RPN.hpp"
#include <string>
#include <limits>

Rpn::Rpn() {

}

Rpn::Rpn(const std::string& expression) {
  startRPN(expression);
}

Rpn::~Rpn() {

}

Rpn::Rpn(const Rpn& other) : m_stack(other.m_stack) {

}

Rpn Rpn::operator=(const Rpn& other) {
  if (this != &other) {
    m_stack = other.m_stack;
  }
  return *this;
}

void Rpn::startRPN(std::string expression) {
  // size_t i = 0;
  // size_t start = 0;
  size_t end = 0;
  std::string temp;
  while (!expression.empty()) {
    end = expression.find_first_of(" \t\n\r\f\v");
    temp = expression.substr(0, end);
		expression.erase(0, expression.find_first_not_of(" \t\n\r\f\v", end));
		// erase token + any run of trailing delimiters in one go
		if (!temp.empty() && isTokenValid(temp)) {
			m_stack.emplace(temp);
			std::cout << "stack: " << m_stack.top() << "\n";
			
		}
		else {
			std::cerr << "Error\n";
			return ;
		}
		std::cout << "'" << temp << "'\n";
		if (end == std::string::npos) {
			std::cout << "clearing\n";
      expression.clear();
    }
  }
}

bool Rpn::isTokenValid(const std::string& token) {
 return token == "+"  || 
 				token == "-" || 
				token == "*" ||
				token == "/" || 
				isTokenDigit(token);
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