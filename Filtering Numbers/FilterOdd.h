#ifndef FILTER_ODD_H
#define FILTER_ODD_H
#include "FilterGeneric.h"

class FilterOdd: virtual public FilterGeneric {
private:
	bool g(int num);
};
#endif
