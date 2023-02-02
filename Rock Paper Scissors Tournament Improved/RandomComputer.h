#ifndef RANDOMCOMPUTER_H
#define RANDOMCOMPUTER_H
#include "Computer.h"

class RandomComputer: public virtual Computer {
public:
	virtual void makeMove();
	RandomComputer();
};
#endif

