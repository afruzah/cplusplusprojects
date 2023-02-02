#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include "Sort.h"
#include <vector>

class BubbleSort: public virtual Sort {
public:
	std::vector<int> sort(std::vector<int> list);
};
#endif
