#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node(int input, Node * nextInput);
	void setData(int input);
	int getData();
	Node * getNext();
	void setNext(Node * nextInput);
private:
	Node * next;
	int data;
};
#endif
