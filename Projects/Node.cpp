//============================================================================
// Name        : Node.cpp
// Author      : Ollie
// Date        : Created on: 26 Feb 2013
// Version     :
// Copyright   : copyright reserved
// Description : A Node Class for insertion into binary tree
//============================================================================/*

#include <string>
//#include "Location.h"
#include "Node.h"

using namespace std;

	// Constructor creates an instance
	Node::Node(Location location) {
		counter = 0;
		key=location.getCityName();
		left=NULL;
		right=NULL;
		parent=NULL;
		dups=NULL;
		counter++;
		};

	// Function to set left node
	void Node::setLeft(Node* left) {
		this->left = left;
	}
	// Function to set right node
	void Node::setRight(Node* right) {
		this->right = right;
	}

	// Function to set parent node
	void Node::setParent(Node* parent) {
		this->parent = parent;
	}
	void Node::setDuplicate(Node* dups) {
		this->parent = parent;
	}

	// Function to return key
	string Node::getKey() {
		return this->key;
	}
	// Function to return left node
	Node* Node::getLeft() {
		return this->left;
	}
	// Function to return right node
	Node* Node::getRight() {
		return this->right;
	}
	// Function to return parent node
	Node* Node::getParent() {
		return this->parent;
	}


