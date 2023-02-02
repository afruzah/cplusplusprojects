#ifndef BITFLIP_H
#define BITFLIP_H
#include "Mutator.h"

class BitFlip: public virtual Mutator {
public:
	Individual mutate(Individual ind, int k);
};
#endif
