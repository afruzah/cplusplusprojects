#include "BubbleSort.h"
#include <algorithm>

std::vector<int> BubbleSort::sort(std::vector<int> list) {
	int len = list.size();
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (list.at(j) > list.at(j+1)) {
				std::swap(list.at(j), list.at(j+1));
			} else {
				break;
			}
		}
	}
	
	return list;
}

	
	
		
