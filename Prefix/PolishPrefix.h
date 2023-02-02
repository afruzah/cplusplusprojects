#ifndef POLISH_PREFIX_H
#define POLISH_PREFIX_H
#include <string>

class PolishPrefix {
public:
	bool isOp(char thing);
	bool isNum(char potentialNum);
	bool isOk(std::string string);
	std::string toInfix(std::string string);
	int calculate(std::string string);
	int operations(int a, int b, char op);
};
#endif
