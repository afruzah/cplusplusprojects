#include "BitFlip.h"
#include <math.h>

Individual BitFlip::mutate(Individual ind, int k) {
	int length = ind.getLength();
	while (k > length) {
		k = k - length;
	}
	
	k = abs(k);
	
	ind.flipBit(k);
	return ind;
}
