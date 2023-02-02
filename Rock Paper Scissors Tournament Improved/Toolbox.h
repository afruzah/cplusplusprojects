#ifndef TOOLBOX_H
#define TOOLBOX_H
#include "Computer.h"

class Toolbox: public virtual Computer {
public:
	void makeMove();//computer makes move
	Toolbox();
};

#endif
