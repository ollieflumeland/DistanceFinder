//============================================================================
// Name        : Node.h
// Author      : Ollie
// Date        : Created on: 26 Feb 2013
// Version     :
// Copyright   : copyright reserved
// Description : A Node Class for insertion into binary tree
//============================================================================/*


#ifndef NODE_H_
#define NODE_H_

#include "Location.h"

using namespace std;

class Node {
public:
	string key;
	int counter;
	Location location;
	Node* dups;
	Node* left;
	Node* right;
	Node* parent;
	Node(Location location);
	virtual ~Node();
	void setLeft(Node* left);
	void setRight(Node* right);
	void setParent(Node* parent);
	void setDuplicate(Node* dups);
	string getKey();
	Node* getLeft();
	Node* getRight();
	Node* getParent();

};

#endif /* NODE_H_ */

