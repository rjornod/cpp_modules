#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Only one argument allowed. EX:  \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return -1;
	}
	Rpn rpn(argv[1]);
}