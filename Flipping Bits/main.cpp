#include "Individual.h"
#include "Mutator.h"
#include "BitFlip.h"
#include "Rearrange.h"
#include "BitFlipProb.h"
#include <iostream>
#include <string>
#include <math.h>

Individual * execute(Individual * indPtr, Mutator * mPtr, int k) {
	*indPtr = mPtr->mutate((*indPtr), k);
	return indPtr;
}

int main() {
	std::string binary1;
	std::string binary2;
	int k1;
	int k2;
	
	std::cin >> binary1;
	std::cin >> k1;
	std::cin >> binary2;
	std::cin >> k2;
	
	
	Individual * one = new Individual(binary1);
	Individual * two = new Individual(binary2);
	BitFlip * a = new BitFlip;
	Rearrange * r = new Rearrange;
	
	std::cout << execute(one, a, k1)->getString();
	std::cout << " ";
	std::cout << execute(two, r, k2)->getString();
	std::cout << " ";
	std::cout << two->getMaxOnes();

	
	
	return 0;
}

