#include "PolishPrefix.h"
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <iostream>

bool PolishPrefix::isOp(char thing) {
	if (thing == '*' || thing == '/' || thing == '+' || thing == '-') {
		return true;
	} else {
		return false;
	}
}

bool PolishPrefix::isOk(std::string string) {
	int len = string.size();
	int countO = 0;
	int countN = 0;
	if (isOp(string[0])==false) {
		return false;
	}
	for (int i = 0; i < len; i++) {
		if ((isOp(string[i])==false) && (isNum(string[i])==false) && (string[i]!=' ')) {
			return false;
		}
		if (isOp(string[i])==true) {
			countO++;
		}
		if (isNum(string[i])==true) {
			if (((int)string[i] < 1 ) || ((int)string[i] > 99)) {
				return false;
			}
			countN++;
		}
	}
	
	if (countN - countO == 1) {
		return true;
	} else {
		return false;
	}
	
}

bool PolishPrefix::isNum(char potentialNum) {
	if (isdigit(potentialNum)) {
		return true;
	} else {
		return false;
	}
}

std::string PolishPrefix::toInfix(std::string string) {
	std::stack<std::string> infix;
	int len = string.size();
	int previous = -1;
	std::string number = "";

	for (int i = len-1; i > -1; i--) {
        if (isOp(string[i])) {
            std::string x = infix.top();
            infix.pop();
            std::string y = infix.top();
            infix.pop();

            std::string temp = "(" + x + " " + string[i] + " " + y + ")";
			if (i == 0 || string[i] == '*' || string[i] == '/') {
				temp =  x + " " + string[i] + " " + y;
			}

            infix.push(temp);

        } else if (string[i] == ' ' && previous > -1) {
            infix.push(number);
            number = "";
            previous = -1;

        } else if (isdigit(string[i])) {
            number = string[i] + number;
            previous = 1;
        }
    }
	
	return infix.top();
}

int PolishPrefix::operations(int a, int b, char op) {
	switch (op) {
		case '*':
			return a*b;
			break;
			
		case '-':
			return a-b;
			break;
		
		case '+':
			return a+b;
			break;
		case '/':
			return a/b;
			break;
	}
	return 0;
}


int PolishPrefix::calculate(std::string string) {
    std::stack<int> calculating;

	int len = string.size();
    std::string number = "";
	int temp;
    int previous = -1;
    for (int i = len-1; i >-1; i--) {
        if (isOp(string[i])) {
            int x = calculating.top();
            calculating.pop();
            int y = calculating.top();
            calculating.pop();
			
			temp = operations(x, y, string[i]);
            calculating.push(temp);

        } else if (string[i] == ' ' && previous > -1){
            calculating.push(stoi(number));
            number = "";
            previous = -1;

        } else if (isdigit(string[i])) {
            number = string[i] + number;
            previous = 1;
        }
    }

    return calculating.top();
}
