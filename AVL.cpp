#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

//initialise class Node to create elements of AVL tree with a num value, a left node, a right node and a height set at 0
class Node {
public:
	int num;
	Node *left;
	Node *right;
	int height;
};

//creates a new Node+
Node *newNode(int value) {
	Node *t = new Node;
	t->num = value;
	t->right = NULL;
	t->left = NULL;
	t->height = 1;
	
	return t;
}

//function that returns height of node, if the node is null it will return 0
int heightNode(Node *node) {
	if (node == NULL) {
		return 0;
	}
	return node->height;
}

//function that returns the balance factor of a node
int balanceFactor(Node *node) {
	if(node == NULL) {
		return 0;
	} else {
		int heightL, heightR;
		if (node->left == NULL) {
			heightL = 0;
		} else {
			heightL = (node->left)->height;
		}
		if (node->right == NULL) {
			heightR = 0;
		} else {
			heightR = (node->right)->height;
		}
		int balance = heightL - heightR;
		return balance;
	}
}

//function that finds the biggest node
Node *biggestNode(Node *node){
	Node *temp = node;
	while(temp->right!=NULL){
		temp = temp->right;
	}
	return temp;
}

//function that finds the smallest node
Node *smallestNode(Node *node){
	Node *temp = node;
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

//updates height of node by considering whether left or right subtree is larger
void updateHeight(Node *node) {
	int left, right;
	if (node->left == NULL) {
		left = 0;
	} else {
		left = heightNode(node->left);
	}
	
	if (node->right == NULL) {
		right = 0;
	} else {
		right = heightNode(node->right);
	}
	
	int maxHeight = max(left, right);
	node->height = 1 + maxHeight;
}
//function performs left rotation and returns new root node
Node *leftRotate(Node *node){
	Node *temp = node->right;
	node->right = temp->left;
	temp->left = node;
	
	updateHeight(node);
	updateHeight(temp);
	
	return temp;
}

//function performs right rotation and returns new root node
Node *rightRotate(Node *node){
	Node *temp = node->left;
	node->left = temp->right;
	temp->right =  node;
	
	updateHeight(node);
	updateHeight(temp);
	
	return temp;
}

//function checks height of node and decides whether to rotate left or right to rebalance node
Node *rebalance(Node *node){
	int balance = balanceFactor(node);
	
	if (balance > 1) {
		if (balanceFactor(node->left) > -1) {
			node = rightRotate(node);
		}
		else {
			node->left = leftRotate(node->left);
			node = rightRotate(node);
		}
	}
	
	if (balance < -1) {
		if (balanceFactor(node->right) < 1) {
			node = leftRotate(node);
		}
		else {
			node->right = rightRotate(node->right);
			node = leftRotate(node);
		}
	}
	
	return node;
}


//function inserts node into AVL tree
Node *insertNode(Node *node, int val){
	if (node == NULL) {
		node = newNode(val);
	}
	else if (val < node->num) {
		node->left = insertNode(node->left, val);
	}
	else if (val > node->num) {
		node->right = insertNode(node->right, val);
	}
	
	updateHeight(node);
	
	int balance = balanceFactor(node);
	
	//LL
	if (balance > 1 && val < (node->left)->num) {
		return rightRotate(node);
	}
	//RR
	if (balance < -1 && val > (node->right)->num) {
		return leftRotate(node);
	}
	  
	//LR
	if (balance > 1 && val > (node->left)->num) {
		node->left = leftRotate(node->left) ;
		return rightRotate(node);
	}
	
	//RL
	if (balance < -1 && val < (node->right)->num) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

//function that removes node from AVl tree
Node *deleteNode(Node *node, int val){
	if (node == NULL) {
		return node;
	}
	if (val < node->num) {
		node->left = deleteNode(node->left, val);
	}
	else if (val > node->num) {
		node->right = deleteNode(node->right, val);
	}
	else if (node->right == NULL && node->left == NULL) {
		node = NULL;
	}
	else if (node->right == NULL && node->left != NULL) {
		node = node->left;
	}
	else if (node->left == NULL && node->right != NULL) {
		node = node->right;
	} else {
		Node *temp = biggestNode(node->left);
		node->num = temp->num;
		node->left = deleteNode(node->left, temp->num);
		free(temp);
	}
	
	if (node == NULL) {
		return node;
	}
	
	updateHeight(node);

	return rebalance(node);
}

//preorder traversal
void preorder(Node *node)
{
     if (node == NULL){
         return;
       } else {
		  cout << node->num << " ";
          preorder(node->left);
          preorder(node->right);
       }
}

//postorder traversal
void postorder(Node *node)
{
    if (node == NULL){
        return;
    } else{
        postorder(node->left);
        postorder(node->right);
        cout << node->num << " ";
    }
}
  
//inorder traversal
void inorder(Node *node)
{
     if (node == NULL){
         return;
       } else {
           inorder(node->left);
           cout << node->num << " ";
           inorder(node->right);
       }
}

int main(){
    Node *node = NULL;
    vector<string> AVL;
    string AVLnode;
    getline(cin, AVLnode);
    string nodes;
    stringstream input(AVLnode);
    
    while(input >> nodes) {
        AVL.push_back(nodes);
    }
    
    for(int i=0; i < AVL.size(); i++) {
        int k;
        
        if(AVL[i][0] == 'A') {
            AVL[i].erase(0,1);
            k = stoi(AVL[i]);
            node = insertNode(node, k);
        }
        if(AVL[i][0] == 'D') {
            AVL[i].erase(0,1);
            k = stoi(AVL[i]);
            node = deleteNode(node,k);
        }
        
        if(AVL[i] == "PRE")
        {
            if(node == NULL) {
                cout << "EMPTY" << endl;
            } else {
                preorder(node);
            }
        }
        if(AVL[i] =="IN") {
            if(node == NULL) {
                cout << "EMPTY" << endl;
            } else {
                inorder(node);
            }
        }
        if(AVL[i] == "POST") {
            if(node == NULL) {
                cout<<"EMPTY"<<endl;
            } else {
                postorder(node);
            }
        }
    }
    return 0;
}
