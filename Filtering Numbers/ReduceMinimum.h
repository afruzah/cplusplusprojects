#ifndef REDUCE_MINIMUM_H
#define REDUCE_MINIMUM_H
#include "ReduceGeneric.h"

class ReduceMinimum: virtual public ReduceGeneric {
private:
	int binaryOperator(int x, int y);
};
#endif
