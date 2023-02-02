#include "EfficientTruckloads.h"
#include <limits.h>
#include <array>

static std::array<int, INT_MAX> Truck;
int EfficientTruckloads::numTrucks(int numCrates, int truckSize){
	
	if ((truckSize > 0 && numCrates > 0) && (truckSize < INT_MAX -1) && (numCrates < INT_MAX -1)) {
		if (truckSize >= numCrates) {
			return 1;
		}
		if (Truck.at(numCrates) != 0) {
			return Truck.at(numCrates);
		}
		else {
			Truck.at(numCrates) = numTrucks(numCrates/2 + numCrates%2, truckSize)
			+ numTrucks(numCrates/2, truckSize);
			
			return Truck.at(numCrates);
		}
	}
	if (numCrates==0) {
		return 0;
	}
	return -1;
}
