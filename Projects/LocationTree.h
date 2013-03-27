//============================================================================
// Name        : LocationTree.h
// Author      : Ollie
// Date        : Created on: 26 Feb 2013
// Version     :
// Copyright   : copyright reserved
// Description : A Node Class for insertion into binary tree
//============================================================================/*


#ifndef LocationTree_H_
#define LocationTree_H_

#include "Location.h"
#include "Node.h"

using namespace std;

class LocationTree {
private:
	Node* root;
	Node* nullNode;
public:
	Node* getRoot();
	Node* getCity(Node* node, string ident);
	void addNode (Location *loc); // To add first node
	void addNode(Location *loc, Node* leaf);
	void deleteNode (string ident);
	void freeNode(Node* leaf);

	// Default Constructor
	LocationTree();

	// Destructor
	~LocationTree();
};

#endif /* NODE_H_ */

