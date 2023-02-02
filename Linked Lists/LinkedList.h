#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <array>

class LinkedList {
public:
	LinkedList();
	LinkedList(int array[], int arraySize);
	void addFront(int newItem);
	void addEnd(int newItem);
	void addAtPosition(int position, int newItem);
	int search(int item);
	void deleteFront();
	void deleteEnd();
	int getItem(int position);
	void deletePosition(int position);
	void printItems();
	~LinkedList();
private:
	Node * head;
};
#endif
