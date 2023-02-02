#include "LinkedList.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() {
	head = NULL;
}
LinkedList::LinkedList(int array[], int arraySize) {
	Node * listNode = new Node(array[0],NULL);
	head = listNode;
	
	for (int i = 1; i < arraySize; i++) {
		Node * newNode = new Node(array[i], NULL);
		listNode->setNext(newNode);
		listNode = newNode;
	}
	listNode->setNext(NULL);
}
void LinkedList::addFront(int newItem) {
	Node * newNode = new Node(newItem, head);
	head = newNode;
}
void LinkedList::addEnd(int newItem) {
	Node * newNode = new Node(newItem, NULL);
	
	if (head == NULL) {
		head = newNode;
	}
	
	Node * addingToEnd = head;
	
	while(addingToEnd->getNext()) {
		addingToEnd = addingToEnd->getNext();
	}
	
	addingToEnd->setNext(newNode);
}

void LinkedList::addAtPosition(int position, int newItem) {
	if (head == NULL) {
		head = new Node(newItem, NULL);
		return;
	}
	
	Node * size = head;
	int length = 0;
	
	while (size!=NULL) {
		length++;
		size = size->getNext();
	}
	if (position > length) {
		addEnd(newItem);
	}
	else if (position == 1) {
		addFront(newItem);
	} else {
		int count = 0;
		
		Node * searchPtr = head;
		
		while(searchPtr!=NULL && count < position) {
			count++;
			if (count == position-1) {
				break;
			}
			searchPtr = searchPtr->getNext();
		}
		
		
		if (searchPtr == NULL) {
			addEnd(newItem);
		} else {
			Node * temp = new Node(newItem, searchPtr->getNext());
			searchPtr->setNext(temp);
		}
	}
	
}

int LinkedList::search(int item) {
	int count = 0;
	int foundIt = 0;
	 
	Node * searching = head;
	
	while(searching!=NULL) {
		count++;
		if(searching->getData()==item) {
			
			foundIt = count;
			std::cout << foundIt << " ";
			return foundIt;
		}
		searching = searching->getNext();
	}
	std::cout << 0 << " ";
	return 0;
}
void LinkedList::deleteFront() {
	if (head == NULL) {
		return;
	}
	
	Node * newNode = head;
	head = head->getNext();
	
	delete newNode;
}
void LinkedList::deleteEnd() {
	if (head == NULL) {
		return;
	}
	
	Node * newNode = NULL;
	Node * end = head;
	
	while(end->getNext()!=NULL) {
		newNode = end;
		end = end->getNext();
	}
	
	newNode->setNext(NULL);
	delete end;
}
void LinkedList::deletePosition(int position) {
	if (head == NULL) {
		return;
	}
	
	Node * size = head;
	int length = 0;
	
	while (size!=NULL) {
		length++;
		size = size->getNext();
	}
	if (position < 1 || position > length-1) {
		std::cout << "outside range";
		return;
	}
	
	if (position == 1) {
		deleteFront();
	}
	
	int count = 0;
	Node * toDelete = NULL;
	Node * newNode = head;
	
	while(newNode!=NULL && count < position) {
		count++;
		if (count == position-1) {
			toDelete = newNode;
		}
		newNode = newNode->getNext();
	}
	
	if (toDelete == NULL || toDelete->getNext() == NULL) {
		return;
	}
	
	Node * temp = toDelete->getNext();
	toDelete->setNext(temp->getNext());
	delete(temp);
}
void LinkedList::printItems() {
	if (head == NULL) {
		return;
	}
	
	Node * newNode = head;
	while(newNode!=NULL) {
		std::cout << newNode->getData() << " ";
		newNode = newNode->getNext();
		if (newNode->getNext()==NULL) {
			std::cout << std::endl;
			break;
		}
	}
	
}

int LinkedList::getItem(int position) {
	Node * newNode = head;
	int count = 0;
	
	Node * size = head;
	int length = 0;
	
	while (size!=NULL) {
		length++;
		size = size->getNext();
	}
	
	if ( position < 1 || position > length ) {
		std::cout << std::numeric_limits < int >::max() << " ";
		return std::numeric_limits < int >::max();
	}
	
	while(newNode!=NULL && count < position) {
		if (count == position-1) {
			break;
		}
		newNode = newNode->getNext();
		count++;
	}
	
	if (newNode == NULL) {
		std::cout << std::numeric_limits < int >::max() << " ";
		return std::numeric_limits < int >::max();
	}
	
	int retVal = newNode->getData();
	
	std::cout << retVal << " ";
	return retVal;
}
LinkedList::~LinkedList() {
	Node * newNode = head;
	Node * deletion;
	
	while(newNode!=NULL) {
		deletion = newNode;
		newNode = newNode->getNext();
		delete(deletion);
	}
}
