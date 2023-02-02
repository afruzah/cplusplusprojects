#include "Reverse.h"
#include "Truckloads.h"
#include "EfficientTruckloads.h"
#include <iostream>
#include <limits.h>
#include <string>

int main() {
	Reverse ru;
	Truckloads tu;
	EfficientTruckloads eu;
	int i, numCrates, loadSize;
	std::string s;
	std::cin >> i >> s >> numCrates >> loadSize;
	std::cout << "Output: " << ru.reverseDigit(1234) << " " << ru.reverseString(s) << " " << tu.numTrucks(numCrates,loadSize) << " " << eu.numTrucks(numCrates, loadSize);
	return 0;
}
