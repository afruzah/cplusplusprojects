#ifndef MUTATOR_H
#define MUTATOR_H
#include "Individual.h"
#include <string>

class Mutator {
public:
	virtual Individual mutate(Individual ind, int k) = 0;
};
#endif
