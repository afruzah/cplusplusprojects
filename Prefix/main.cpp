#include "PolishPrefix.h"
#include <iostream>
#include <string>


int main() {
    PolishPrefix * polish = new PolishPrefix();
    std::string expression;
    getline(std::cin, expression);

    if (polish->isOk(expression)) {
        std::cout << polish->toInfix(expression) << " = " << polish->calculate(expression) << std::endl;
    } else {
        std::cout << "Error" << std::endl;
    }
}
