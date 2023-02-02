#include "BitFlipProb.h"
#include <string>

Individual BitFlipProb::mutate(Individual ind, int k) {
	for (int i = 0; i < ind.getLength(); i++) {
		int selector = rand() % 10 + 1;
		if (selector > probability*10) {
			ind.getString()[i]='1';
		} else {
			ind.getString()[i]='0';
		}
	}
	return ind;
}

BitFlipProb::BitFlipProb(float p) {
	probability = p;
}
