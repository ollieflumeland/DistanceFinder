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
public:
	Node* getRoot();
	Node* getCity(string ident, Node* node);
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

