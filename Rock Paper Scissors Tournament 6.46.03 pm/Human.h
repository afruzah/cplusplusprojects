#ifndef HUMAN_PLAYER
#define HUMAN_PLAYER
#include <iostream>

class Human {
public:
	void makeMove();//player can choose a move
private:
	friend class Referee;
	char choice;//stores move from human player
};
#endif
