#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player {
public:
	virtual void makeMove();
	std::string getName();
protected:
	char choice;
	friend class Referee;
	std::string name;
};
#endif
