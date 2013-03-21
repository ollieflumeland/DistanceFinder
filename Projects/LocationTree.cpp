/*
 * A binary search tree for storing location nodes
 *
 *  Created on: 26 Feb 2013
 *      Author: Ollie
 */

#include <string>
#include "Location.h"
#include "Node.h"

using namespace std;

class LocationTree {
	Node* root;

public:
	Tree();
	~Tree();

	Node* getRoot() {
			return root;
	}

	void addNode (string key);
	Node* findNode(string key, Node* parent);
	void walk(Node* node);
	void deleteNode(string key);
	Node* min(Node* node);
	Node* max(Node* node);
	Node* successor(string key, Node* parent);
	Node* predecessor(string key, Node* parent);
private:
	void addNode(string key, Node* leaf);
	void freeNode(Node* leaf);
};

// Constructor
Tree::Tree() {
	root = NULL;
}

// Destructor
Tree::~Tree() {
	freeNode(root);
}

// Remove node
void Tree::freeNode(Node* leaf) {
	if (leaf != NULL) {
		freeNode(leaf->Left());
		freeNode(leaf->Right());
		delete leaf;
	}
}
