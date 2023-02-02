#ifndef REFEREE_H
#define REFEREE_H
#include "Human.h"
#include "Computer.h"
#include <vector>
#include <iostream>

class Referee {
public:
	char refGame(Human p1, Computer p2);//referees game to find results of game
	void finalWinner(std::vector<char> a);
private:
	std::vector<char> results; //stores results of games depending on number of rounds
	bool humanWins;//stores if human has won
	char result_single;//stores result for individual games
	
};
#endif
