#include "Human.h"
#include "Referee.h"
#include "Computer.h"
#include <vector>
#include <iostream>

int main(){
	Human hu;
	Computer cu;
	Referee ru;
	
	int number_of_games = 3;
	for (int i = 0; i < number_of_games; i++) {
		std::cout << ru.refGame(hu,cu) << std::endl;
	}
	
	
	
	return 0;
}
