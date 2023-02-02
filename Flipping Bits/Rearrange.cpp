#include "Rearrange.h"
#include <string>
#include <math.h>

Individual Rearrange::mutate(Individual ind, int k) {
	int length = ind.getLength();
	while (k > length) {
		k = k - length - 1;
	}
	
	k = abs(k);
	std::string newInd;

	for (int i = k - 1; i < length; i++) {
		newInd += ind.binaryString[i];
	}
	
	for (int i = 0; i < k - 1; i++) {
		newInd += ind.binaryString[i];
	}
	ind.binaryString = newInd;
	
	return ind;
}
