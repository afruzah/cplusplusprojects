#include "Tournament.h"
#include "Referee.h"
#include <array>
#include <vector>
#include <iostream>


Player* Tournament::run(std::array<Player*, 8> competitors) {
	Referee* ru = new Referee;
	std::vector<Player*> round2;
	std::vector<Player*> finalRound;

	
	for ( int i=0; i < 8; i=i+2 ) {
		int wins = 0;
		int losses = 0;
		for ( int j=0; j < 5; j++) {

			switch (ru->refGame(competitors[i],competitors[i+1])) {
				case 'L':
					losses++;
					break;
					
				case 'T':
					break;

				case 'W':
					wins++;
					break;
			}
			
		}
		if ( (wins > losses) ||  (wins == losses) ) {
			round2.push_back(competitors[i]);
		} else {
			round2.push_back(competitors[i+1]);
		}
	}
	
	for ( int i=0; i < 4; i=i+2 ) {
		int wins = 0;
		int losses = 0;
		for ( int j=0; j < 5; j++) {

			switch (ru->refGame(round2[i],round2[i+1])) {
				case 'L':
					losses++;
					break;
					
				case 'T':
					break;

				case 'W':
					wins++;
					break;
			}
		}
		
		if ( (wins > losses) || (wins == losses) ) {
			finalRound.push_back(round2[i]);
		} else {
			finalRound.push_back(round2[i+1]);
		}
	}
	
	int wins = 0;
	int losses = 0;
	for (int i = 0; i < 5; i++) {
		
		switch (ru->refGame(finalRound[0],finalRound[1])) {
			case 'L':
				losses++;
				break;
				
			case 'T':
				wins++;
				break;

			case 'W':
				wins++;
				break;
		}
		
	}
	
	if ( (wins > losses) || (wins==losses) ) {
		return finalRound[0];
	} else {
		return finalRound[1];
	}
	
	

	
}
