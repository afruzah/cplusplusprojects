#include "Referee.h"
#include "Player.h"
#include <vector>
#include <iostream>

char Referee::refGame(Player* p1, Player* p2) {
	p1->makeMove();
	p2->makeMove();
	char p1C = p1->choice;
	char p2C = p2->choice;
	
	switch(p1C){
		case 'R' :
			if (p2C=='S') {
				result_single = 'W';
			} else if (p2C=='R') {
				result_single = 'T';
			} else if (p2C=='P') {
				result_single = 'L';
			}
			break;
		case 'P' :
			if (p2C=='S') {
				result_single = 'L';
			} else if (p2C=='R') {
				result_single = 'W';
			} else if (p2C=='P') {
				result_single = 'T';
			}
			break;
		case 'S' :
			if (p2C=='S') {
				result_single = 'T';
			} else if (p2C=='R') {
				result_single = 'L';
			} else if (p2C=='P') {
				result_single = 'W';
			}
			break;
	}
	
	return result_single;
		
}


