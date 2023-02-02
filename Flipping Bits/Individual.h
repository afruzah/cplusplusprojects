#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <string>

class Individual {
public:
	Individual(int length);
	Individual(std::string string);
	int getLength();
	int getMaxOnes();
	void flipBit(int pos);
	int getBit(int pos);
	std::string getString();
private:
	std::string binaryString;
	friend class Rearrange;
};
#endif
