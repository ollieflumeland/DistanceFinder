//============================================================================
// Name        : LocationTree.h
// Authors     : Bourgein, Oliver, Worth
// Date        : Created on: 26 Feb 2013
// Version     :
// Copyright   : copyright reserved
// Description : A Binary Tree Class to store Nodes
//============================================================================/*

#ifndef LocationTree_H_
#define LocationTree_H_

#include "Location.h"
#include "Node.h"
#include <string>

using namespace std;

class LocationTree {
private:
	Node* root;

public:

	// Default Constructor
	LocationTree();

	// Destructor
	~LocationTree();

	//Function Prototypes
	Node* getRoot();
	Node* setRoot(Node* node);
	Node* getCity(Node* node, string ident);
	bool addToTree(LocationTree* tree, Location* loc, Node* node, string city); // Adds loc to tree
	void addNode (Location *loc); // To add first node
	void addNode(Location *loc, Node* leaf);
	bool deleteNode (string ident);
	bool deleteDupNode(Node* foundNode, int number);
	void freeNode(Node* leaf);
	Node* getPrevious(Node* node, string ident);
	Node* getNext(Node* node, string ident);
	Node* getFirst(Node* node);
	Node* getLast(Node* node);
	Node* getFarLeft(Node* node, string ident);
	Node* getFarRight(Node* node, string ident);
	string serialise(Node* node);

};

#endif /* NODE_H_ */

