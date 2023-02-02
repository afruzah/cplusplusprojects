#include "Referee.h"
#include "Computer.h"
#include "Human.h"
#include <vector>
#include <iostream>

char Referee::refGame(Human p1, Computer p2) {
	p1.makeMove();
	p2.makeMove();
	char humanResult = p1.choice;
	
	switch(humanResult){
		case 'R':
			result_single = 'T';
			break;
		case 'S':
			result_single = 'L';
			break;
		case 'P':
			result_single = 'W';
			break;
	}
	
	results.push_back(result_single);
	return result_single;
		
}

void Referee::finalWinner(std::vector<char> a) {
	int countWins = 0;
	int countFails = 0;
	for (int i = 0; i < a.size()-1; i++) {
		if (a.at(i) == 'W') {
			countWins++;
		}
		else if (a.at(i) == 'F') {
			countFails++;
		}
	}
	
	if (countWins > countFails) {
		humanWins = true;
	}
	else {
		humanWins = false;
	}
	
	a.clear();
	
}
