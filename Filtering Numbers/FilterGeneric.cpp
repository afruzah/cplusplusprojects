#include "FilterGeneric.h"
#include <vector>


std::vector<int> FilterGeneric::filter(std::vector<int> vector) {
	static std::vector<int> filtered;
	if (vector.size()==0) {
		std::vector<int> toReturn = filtered;
		filtered.clear();
		return toReturn;
	}
	if (g(vector.at(0))==true) {
		filtered.push_back(vector.at(0));
	}
	
	vector.erase(vector.begin());
	return filter(vector);
}
