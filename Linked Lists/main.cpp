#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>


int main() {

	std::string list;
	std::getline(std::cin, list);
	std::stringstream ss(list);
	std::vector<int> nums;
	std::vector<std::string> stuff;
	std::string token;

	int count = 0;
    while(std::getline(ss, token, ' ') && count < 101) {
		stuff.push_back(token);
		if (std::isdigit(token[0]) || token[0]=='-') {
			count++;
		}
	}
		
	int array[count-2];
	
	for (int i = 0; i < count-2; i++) {
		array[i] = std::stoi(stuff[i]);
	}
	
	std::string function = stuff[count-2];
	
	int parameter1 = std::stoi(stuff[count-1]);
	int parameter2 = std::stoi(stuff[count]);
	

    LinkedList * linked = new LinkedList(array, count-1);
	
	if (function == "AF") {
        linked->addFront(parameter1);
        linked->printItems();
    }
    else if(function == "AE") {
        linked->addEnd(parameter1);
        linked->printItems();
    } else if (function == "S") {
        linked->search(parameter1);
        linked->printItems();
    } else if (function == "AP") {
		linked->addAtPosition(parameter1, parameter2);
        linked->printItems();
    } else if (function == "DE") {
        linked->deleteEnd();
        linked->printItems();
        
    } else if (function == "DF") {
		linked->deleteFront();
        linked->printItems();

    } else if (function == "DP") {
        linked->deletePosition(parameter1);
        linked->printItems();

    } else if (function == "GI") {
        linked->getItem(parameter1);
        linked->printItems();
    }


    return 0;
}

