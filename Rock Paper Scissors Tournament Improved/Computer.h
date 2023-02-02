#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"

class Computer: public virtual Player {
public:
	virtual void makeMove();//computer makes move
protected:
//	char choice;
};

#endif
