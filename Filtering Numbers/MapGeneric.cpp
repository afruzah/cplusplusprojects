#include "MapGeneric.h"
#include <vector>


std::vector<int> MapGeneric::map(std::vector<int> numbers){
	static std::vector<int> changed;
	if (numbers.size()==0) {
		std::vector<int> toReturn = changed;
		changed.clear();
		return toReturn;
	}
	changed.push_back(f(numbers.at(0)));
	numbers.erase(numbers.begin());
	return map(numbers);
}

