#include "Truckloads.h"
#include <iostream>
#include <limits.h>

int Truckloads::numTrucks(int numCrates, int truckSize){
	if (truckSize > 0 && numCrates > 0) {
		if (truckSize >= numCrates) {
			return 1;
		}
		if ((numCrates > INT_MAX) || (truckSize > INT_MAX)) {
			return -1;
		}
		return numTrucks(numCrates/2 + numCrates%2, truckSize) + numTrucks(numCrates/2, truckSize);
	}
	if (numCrates == 0) {
		return 0;
	}
	return -1;
	
}
