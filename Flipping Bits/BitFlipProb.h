#ifndef BIT_FLIP_PROB_H
#define BIT_FLIP_PROB_H
#include "Mutator.h"

class BitFlipProb: public virtual Mutator {
public:
	Individual mutate(Individual ind, int k);
	BitFlipProb(float p);
private:
	int probability;
};
#endif
