#include "RandomComputer.h"
#include <cstdlib>

void RandomComputer::makeMove() {
	char array[3]={'R','S','P'};
	int move = rand() % 3;
	choice = array[move];
}

RandomComputer::RandomComputer() {
	name = "Random";
}



