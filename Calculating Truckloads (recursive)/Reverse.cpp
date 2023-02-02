#include "Reverse.h"
#include <string>
#include <limits.h>
#include <cctype>


int Reverse::reverseDigit(int num) {
	static int total = 0;
	if ((num < 0) || (num > INT_MAX - 1)){
	return-1;
	}
	if (num) {
		total = total * 10+ num % 10;
		num = num/10;
		reverseDigit(num);
	}
	return total;
}


std::string Reverse::reverseString(std::string str) {
	static std::string newStr="";
	if (!str.empty()) {
		newStr+=str.back();
		str.pop_back();
		reverseString(str);
	}
	return newStr;
	
	
}
