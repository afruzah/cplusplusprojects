#include "Individual.h"
#include <string>
#include <cstdlib>

Individual::Individual(int length) {
	for (int i = 0; i < length; i++) {
		binaryString+="0";
	}
}
Individual::Individual(std::string string) {
	binaryString = string;
}
int Individual::getLength() {
	return binaryString.length();
}
int Individual::getMaxOnes() {
	int counter = 1;
	int maxCount = 0;
	int ones = 0;
	for (int i = 0; i < binaryString.length() - 1; i++) {
		if (binaryString[i] == '1' || binaryString[i+1] == '1') {
			ones++;
		}
		if ((binaryString[i] == '1') && (binaryString[i+1] == '1')) {
			counter++;
		}
		if ((binaryString[i] == '1') && (binaryString[i+1] == '0'))  {
			maxCount = counter;
			counter = 1;
		}
	}
	if (ones == 0) {
		return 0;
	}
	if (maxCount > counter) {
		return maxCount;
	}
	return counter;
}
void Individual::flipBit(int pos) {
	if ((pos < 1) || (pos >binaryString.length())) {
		binaryString[pos-1] = binaryString[pos-1];
	}
	if (binaryString[pos-1] == '1') {
		binaryString[pos-1] = '0';
	} else {
		binaryString[pos-1] = '1';
	}
}
int Individual::getBit(int pos) {
	if ( (pos < 0) || (pos > binaryString.length()-1) ) {
		return -1;
	}
	if (binaryString[pos] == '0') {
		return 0;
	}
	if (binaryString[pos] == '1') {
		return 1;
	}
	return 0;
}
std::string Individual::getString() {
	return binaryString;
}
