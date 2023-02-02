#ifndef FILTER_GENERIC_H
#define FILTER_GENERIC_H
#include <vector>

class FilterGeneric {
public:
	std::vector<int> filter(std::vector<int> vector);
private:
	virtual bool g(int num) = 0;
};
#endif
