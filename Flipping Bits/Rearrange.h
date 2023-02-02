#ifndef REARRANGE_H
#define REARRANGE_H
#include "Mutator.h"

class Rearrange: public virtual Mutator {
public:
	Individual mutate(Individual ind, int k);
};
#endif
