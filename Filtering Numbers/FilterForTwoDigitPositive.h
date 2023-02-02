#ifndef FILTER_FOR_TWO_DIGIT_POSITIVE_H
#define FILTER_FOR_TWO_DIGIT_POSITIVE_H
#include "FilterGeneric.h"

class FilterForTwoDigitPositive: virtual public FilterGeneric {
private:
	bool g(int num);
};
#endif
