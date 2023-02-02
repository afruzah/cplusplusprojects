#ifndef HUMAN_PLAYER
#define HUMAN_PLAYER
#include "Player.h"
#include <iostream>

class Human: public virtual Player {
public:
	void makeMove();//player can choose a move
};
#endif
