#include "ReduceGeneric.h"
#include <vector>

int ReduceGeneric::reduce(std::vector<int> vector) {
	if (vector.size()==1) {
		return vector.at(0);
	}
	int x = vector.at(0);
	int y = vector.at(1);
	int result = binaryOperator(x,y);
	vector.erase(vector.begin()+1);
	vector.at(0) = result;
	
	return reduce(vector);
}

 
