#ifndef MAP_GENERIC_H
#define MAP_GENERIC_H
#include <vector>

class MapGeneric {
public:
	std::vector<int> map(std::vector<int> numbers);
private:
	virtual int f(int num) = 0;
};
#endif
