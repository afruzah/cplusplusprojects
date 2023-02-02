#ifndef FILTER_NON_POSITIVE_H
#define FILTER_NON_POSITIVE_H
#include "FilterGeneric.h"

class FilterNonPositive: virtual public FilterGeneric {
private:
	bool g(int num);
};
#endif
