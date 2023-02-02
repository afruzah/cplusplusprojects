#include "Node.h"

Node::Node(int input, Node * nextInput) {
	data = input;
	next = nextInput;
}
void Node::setData(int input) {
	data = input;
}
int Node::getData() {
	return data;
}
Node * Node::getNext() {
	return next;
}
void Node::setNext(Node * nextInput) {
	next = nextInput;
}

