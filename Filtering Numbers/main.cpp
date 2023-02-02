#include "MapGeneric.h"
#include "MapTriple.h"
#include "MapSquare.h"
#include "MapAbsoluteValue.h"
#include "FilterGeneric.h"
#include "FilterOdd.h"
#include "FilterNonPositive.h"
#include "FilterForTwoDigitPositive.h"
#include "ReduceGeneric.h"
#include "ReduceMinimum.h"
#include "ReduceGCD.h"
#include <vector>
#include <iostream>

int main() {
	std::vector<int> hello{ 6, -15, 53, -16, 73, 128, 105, 104, -71, -179, 102, 12, 25, -145, -99, 199, -156, -186, 43, -189 };
	
	MapTriple tri;
	hello = tri.map(hello);
	for (int i = 0; i < hello.size(); i++) {
		std::cout << hello.at(i) << " ";
	}
	std::cout << " " << std::endl;
	
	MapAbsoluteValue ava;
	hello = ava.map(hello);
	for (int i = 0; i < hello.size(); i++) {
		std::cout << hello.at(i) << " ";
	}
	std::cout << " " << std::endl;
	
	FilterForTwoDigitPositive fod;
	hello = fod.filter(hello);
	for (int i = 0; i < hello.size(); i++) {
		std::cout << hello.at(i) << " ";
	}
	std::cout << " " << std::endl;
	
	FilterOdd odd;
	hello = odd.filter(hello);
	for (int i = 0; i < hello.size(); i++) {
		std::cout << hello.at(i) << " ";
	}
	std::cout << " " << std::endl;
	
	ReduceMinimum min;
	ReduceGCD gcd;
	std::cout << min.reduce(hello) << " " << gcd.reduce(hello) << std::endl;
	
	return 0;
}
