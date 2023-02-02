#ifndef REDUCE_GCD_H
#define REDUCE_GCD_H
#include "ReduceGeneric.h"

class ReduceGCD: virtual public ReduceGeneric {
private:
	int binaryOperator(int x, int y);
};
#endif

