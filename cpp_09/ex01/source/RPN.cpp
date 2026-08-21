#include "RPN.hpp"

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
    if (end == std::string::npos) {
      expression.clear();
    }
    else {
      expression.erase(0, expression.find_first_not_of(" \t\n\r\f\v", end));
      // erase token + any run of trailing delimiters in one go
    }
    std::cout <<temp << "\n";
  }
}