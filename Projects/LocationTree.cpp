//============================================================================
// Name        : LocationTree.cpp
// Authors     : Bourgein, Oliver, Worth
// Date        : Created on: 26 Feb 2013
// Version     :
// Copyright   : copyright reserved
// Description : A Binary Tree Class to store Nodes
//============================================================================/*

#include <algorithm>
#include <string>
#include "LocationTree.h"
#include "Menu.h"

using namespace std;

// Constructor
LocationTree::LocationTree() {
	root = NULL;
}

// Destructor
LocationTree::~LocationTree() {
	freeNode(root);
}

// Function to find root
Node* LocationTree::getRoot() {
	return root;
	}

// Function to set root
Node* LocationTree::setRoot(Node* node) {
	root == node;
	}

/* Function that adds new city locations to the tree (Nodes).
*  This function checks if the location should be added as a new node or as
*  a duplicate location
*  Uses the 2 addNode methods specified below
*/
bool LocationTree::addToTree(LocationTree* tree, Location* loc, Node* node, string city) {
	balancePoint = NULL;
	Node* duptest = getCity(node, city);
	if (duptest != NULL ) {
		Location* newDup = duptest->getLocation();
		while (newDup->getDups() != NULL) {
			newDup = newDup->getDups();
			loc->plusNum();
		}
		newDup->setDups(loc);
		loc->plusNum();
		duptest->plusDups();
		cout << "Adding new duplicate, locNum: " << loc->getNum() << " noDups: " << duptest->getDupsNo() <<
		endl;
	} else {
		tree->addNode(loc);
	}
}

// Function that adds nodes to the tree, used on the new tree to install root
void LocationTree::addNode (Location *loc) {
   if ( root != NULL ) {
		addNode(loc, root);
	} else {
		Node* node = new Node(loc);
		node->setIdent(loc->getCityName());
		node->setLevel(1);
		root = node;
	}
}

// Function that adds nodes to the tree, finding the correct position
void LocationTree::addNode(Location *loc, Node* test) {
	string ident = loc->getCityName();
	if (ident < test->getIdent()) { // if left
		test->plusCL(); // balancing info
		if (test->getLeft() != NULL ) {
			addNode(loc, test->getLeft());
		} else {
			Node* node = new Node(loc);
			node->setIdent(ident);
			node->setParent(test);
			test->setLeft(node);
			node->setLevel(node->findLevel(node));
			LocationTree::balanceUpToRoot(node->getParent());
		}
	} else {
		test->plusCR(); // balancing info
		if ( test->getRight() != NULL ) {
			addNode(loc, test->getRight());
		} else {
			Node* node = new Node(loc);
			node->setIdent(ident);
			node->setParent(test);
			test->setRight(node);
			node->setLevel(node->findLevel(node));
			LocationTree::balanceUpToRoot(node->getParent());
		}
	}
}


// Function that RE-adds nodes to the tree, finding the correct position
void LocationTree::reAddNode(Location *loc, Node* test) {
	string ident = loc->getCityName();
	if (ident < test->getIdent()) { // if left
		test->plusCL(); // balancing info
		if (test->getBalance() < -1 || test->getBalance() > 1) {
			balancePoint = test;
			childOne = L;
		}
		if (test->getLeft() != NULL )
			reAddNode(loc, test->getLeft());
		else {
			Node* node = new Node(loc);
			node->setIdent(ident);
			node->setParent(test);
			test->setLeft(node);
			node->setLevel(node->findLevel(node));
		}
	} else {
		test->plusCR(); // balancing info
		if (test->getBalance() < -1 || test->getBalance() > 1) {
			balancePoint = test;
			childOne = R;
		}
		if ( test->getRight() != NULL )
			reAddNode(loc, test->getRight());
		else {
			Node* node = new Node(loc);
			node->setIdent(ident);
			node->setParent(test);
			test->setRight(node);
		}
	}
}

// Function to rebalance the tree up to the root
void LocationTree::balanceUpToRoot(Node* node) {
	Node* temp = node;
	while (temp->getParent()!= NULL) {
		temp = temp->getParent();
		if (LocationTree::getBalanceFactor(temp) <= -2 || LocationTree::getBalanceFactor(temp) >=2) {
				balancePoint = temp;
				int balancePointBF = LocationTree::getBalanceFactor(balancePoint);
				if (balancePointBF == -2 && (LocationTree::getBalanceFactor(balancePoint->getRight()) == -1 || LocationTree::getBalanceFactor(balancePoint->getRight()))) {
					rotateRR();
				} else if (balancePointBF == -2 && LocationTree::getBalanceFactor(balancePoint->getRight()) == 1) {
					rotateRL();
					rotateRR();
				} else if (balancePointBF == 2 && LocationTree::getBalanceFactor(balancePoint->getLeft()) == 1 || LocationTree::getBalanceFactor(balancePoint->getLeft()) == 0) {
					rotateLL();
				} else if (balancePointBF == 2 && LocationTree::getBalanceFactor(balancePoint->getLeft()) == -1) {
					rotateLR();
					rotateLL();
				} else {
					cout << "error " << endl;
				}
			}

		}

}


//Function to rebalance the tree up to the root
/*void LocationTree::balanceUpToRoot(Node* node) {
	Node* bottom = node;
	Node* middle = node->getParent();
	Node* top = middle->getParent();
	if (middle < top) {
		childOne = L;
	} else {
		childOne = R;
	}
	while (top->getParent() != NULL) {
		//cout << "T: " << top->getIdent() << ", BalFac: " << top->getBalance() << ", CL: " << top->getCL() <<  ", CR: " << top->getCR() << endl;
		if (top->getBalance() < -1 || top->getBalance() > 1) {
			balancePoint = top;
			//cout << "BalPt: " << balancePoint->getIdent() << ", BalFac: " << balancePoint->getBalance() << endl;
			midNode = middle;
			//cout << "Performing balancing at: " << balancePoint->getIdent() << endl;
			if (midNode->getCL() < -1 || midNode->getCL() > 1) {
				childTwo = L;
				insertedNode = midNode->getLeft();
				//cout << "rotateTwo" << endl;
				rotateTwo();
				//cout << "rotateOne" << endl;
				rotateOne();
			} else if (midNode->getCR() < -1 || midNode->getCR() > 1) {
				childTwo = R;
				insertedNode = midNode->getRight();
				//cout << "rotateTwo" << endl;
				rotateTwo();
				//cout << "rotateOne" << endl;
				rotateOne();
			} else {
				//cout << "rotateOne" << endl;
				rotateOne();
			}
		}
		//cout << "BalPt: " << balancePoint->getIdent() << ", BalFac: " << balancePoint->getBalance() << ", CL: " << top->getCL() <<  ", CR: " << top->getCR() << endl << endl;
		bottom = middle;
		middle = top;
		top = top->getParent();
    }
}*/

// Function that finds the furthest left entry
Node* LocationTree::getFirst(Node* node) {
	if (node == NULL) {
		return NULL;
	}
	if (node->getLeft()) {
		getFirst(node->getLeft());
	}
	else {
		return node;
	}
}

// Function that finds the furthest right entry
Node* LocationTree::getLast(Node* node) {
	if (node == NULL) {
		return NULL;
	}
	if (node->getRight()) {
		getLast(node->getRight());
	}
	else {
		return node;
	}
}

// Function that finds the furthest left entry (min) from a defined node
Node* LocationTree::getFarLeft(Node* node, string ident) {
	balancePoint = getCity(node, ident);
	if (balancePoint->getLeft() != NULL) {
		return getFirst(balancePoint->getLeft());
	} else {
		return balancePoint;
	}
}


// Function that finds the furthest right entry (max) from the current balancePoint node
Node* LocationTree::getFarRight(Node* node, string ident) {
	balancePoint = getCity(node, ident);
	if (balancePoint->getRight() != NULL) {
		return getLast(balancePoint->getRight());
	} else {
		return balancePoint;
	}

}

/**
*	Function that finds the closest smaller node to the defined node
*/
Node* LocationTree::getPrevious(Node* node, string ident) {
	balancePoint = getCity(node, ident);
	if (balancePoint != NULL) {
		return getLast(balancePoint->getLeft());
	} else {
		return balancePoint;
	}
}


// Function that finds the closest larger node to the balancePoint node
Node* LocationTree::getNext(Node* node, string ident) {
	balancePoint = getCity(node, ident);
	if (balancePoint != NULL) {
		return getFirst(balancePoint->getRight());
	} else {
		return balancePoint;
	}

}
/**
*   Function to delete a duplicate location
*	if location is last in list delete
*	if location is within list join before and after then delete
*/
bool LocationTree::deleteDupNode(Node* foundNode, int number) {
	Location* foundLoc = foundNode->getLocation();
	Location* toRemove;
	Location* preceding;
	if (number == 1) {
		toRemove = foundLoc;
		foundLoc = foundLoc->getDups();
		foundNode->setLocation(foundLoc);
		foundNode->minusDups();
		foundLoc->minusNum();
		while (foundLoc->getDups() != NULL) {
			foundLoc = foundLoc->getDups();
			foundLoc->minusNum();
		}
		delete toRemove;
		return true;
	} else {
		preceding = foundLoc;
		while (preceding->getNum() != number-1) { // find preceding loc
		preceding = preceding->getDups();
		}
		if (number == foundNode->getDupsNo()+1) {  // if last
			toRemove = preceding->getDups();
			foundLoc->setDups(NULL);
			delete toRemove;
			foundNode->minusDups();
			return true;
		} else {
			toRemove = preceding->getDups();
			preceding->setDups(toRemove->getDups()); // rejoin to following
			foundNode->minusDups();
			delete toRemove;
			while (preceding->getDups() != NULL) {
				preceding = preceding->getDups();
				preceding->minusNum();
			}
			return true;
		}
	}
	return false;
}



/**
*  Function to delete a node
*  Step 1: If node is a leaf delete
*  Step 2:If it has a single child, replace leaf with child
*  Step 3: If 2 children, find the closest replacement node
*  remove replacement node, remove target node and insert replacement
*/
bool LocationTree::deleteNode(string ident) {
	balancePoint = getCity(root, ident);
	// Step 1
	if (balancePoint->getLeft() == NULL && balancePoint->getRight() == NULL) {
		// Check if root node
		if (balancePoint->getParent() == NULL) {
			cout << "This is the only entry in the tree" << endl;
			cout << "It cannot be deleted" << endl;
		}
		// Delete node
		else if (balancePoint->getIdent() > balancePoint->getParent()->getIdent()) {
			balancePoint->getParent()->setRight(NULL);
		} else {
			balancePoint->getParent()->setLeft(NULL);
		}
		LocationTree::resetBalFactUpToRoot(balancePoint);
		delete balancePoint;
		return true;
	}
	// Step 2
	else if (balancePoint->getLeft() == NULL && balancePoint->getRight() != NULL) { //if leaf right
		// Check if root
		if (balancePoint->getParent() == NULL) {
			root = balancePoint->getRight();
			balancePoint->getRight()->setParent(NULL);
		}
		// Determine if node is on a right or left leaf
		else if (balancePoint->getIdent() > balancePoint->getParent()->getIdent()) { // if on right
			balancePoint->getParent()->setRight(balancePoint->getRight()); // Reset parents right
		} else {
			balancePoint->getParent()->setLeft(balancePoint->getRight()); // Reset parents left
		}
		LocationTree::resetBalFactUpToRoot(balancePoint);
		delete balancePoint;
		return true;
	}
	else if (balancePoint->getLeft() != NULL && balancePoint->getRight() == NULL) { //if leaf left
		 // Check if root
		if (balancePoint->getParent() == NULL) {
			root = balancePoint->getLeft();
			balancePoint->getLeft()->setParent(NULL);
			}
		// Determine if parent is on a right or left leaf
		else if (balancePoint->getIdent() > balancePoint->getParent()->getIdent()) {
			balancePoint->getParent()->setRight(balancePoint->getLeft()); // Reset parents right
		} else {
			balancePoint->getParent()->setLeft(balancePoint->getLeft()); // Reset parents left
		}
		return true;
	}
	// Step 3
	else if (balancePoint->getLeft() != NULL && balancePoint->getRight() != NULL) { //if two leaves
		// Find nearest previous node
		Node* previous = getPrevious(balancePoint, ident);
		// Find nearest next node
		Node* next = getNext(balancePoint, ident);
		// create char arrays for comparison
		char * cstrCurr = new char[balancePoint->getIdent().length()+1];
		strcpy (cstrCurr, balancePoint->getIdent().c_str());
		char * cstrPrev = new char[previous->getIdent().length()+1];
		strcpy (cstrPrev, previous->getIdent().c_str());
		char * cstrNext = new char[next->getIdent().length()+1];
		strcpy (cstrNext, next->getIdent().c_str());
		// find the nearest previous or next
		int prevDist, nextDist;
		int totPrev, totNext;
		int comLngth = ((balancePoint->getIdent().length() < previous->getIdent().length()) ? balancePoint->getIdent().length() : previous->getIdent().length());
		comLngth = ((comLngth < next->getIdent().length()) ? comLngth : next->getIdent().length());
		Node* selected = previous; // Pointer to the best replacement (default: previous)
		for (int i = 0; i < comLngth; i++) {
			totPrev = (cstrCurr[i]-cstrPrev[i]);
			totNext = (cstrNext[i]-cstrCurr[i]);
			if (totPrev < totNext || i == comLngth-1) {
				selected = previous;
				LocationTree::detachPrevious(previous);
				break;
			} else {
				selected = next;
				LocationTree::detachNext(next);
				break;
			}
		}
		// Replacement node is now 'selected'
		// Copy balancePoint's child & parent nodes to replacement
		LocationTree::swapInSelected(selected);
		return true;
		}
	else {
		cout << "can't delete currently" << endl;
		return false;
	}
}

// Function to swap selected with balancePoint
void LocationTree::swapInSelected(Node* selected) {
	if (balancePoint->getLeft() == selected || balancePoint->getLeft() == NULL) {
		selected->setLeft(NULL);
	} else {
		selected->setLeft(balancePoint->getLeft());
		selected->getLeft()->setParent(selected);
	}

	if (balancePoint->getRight() == selected || balancePoint->getRight() == NULL) {
		selected->setRight(NULL);
	} else {
		selected->setRight(balancePoint->getRight());
		selected->getRight()->setParent(selected);
	}

	// Check if root
	if (balancePoint->getParent() == NULL) {
		selected->setParent(NULL);
		// Set root to selected);
		root = selected;
		selected->setLevel(1);
	}
	// Determine if parent is on a right or left leaf
	else if (balancePoint->getIdent() > balancePoint->getParent()->getIdent()) { // if on right
		balancePoint->getParent()->setRight(selected); // Reset parents right
		selected->setParent(balancePoint->getParent());
	} else {
		balancePoint->getParent()->setLeft(selected); // Reset parents left
		selected->setParent(balancePoint->getParent());
	}
}

// Function to detach previous node
void LocationTree::detachPrevious(Node* previous) {
	LocationTree::resetBalFactUpToRoot(previous);
		if (previous->getIdent() > previous->getParent()->getIdent()) { // If parent left
			if (previous->getLeft() == NULL) { // previous = leaf
			previous->getParent()->setRight(NULL); // Reset parents right
		} else {
			previous->getParent()->setRight(previous->getLeft());
		}
	} else {  // Parent right
		if (previous->getLeft() == NULL) { // previous = leaf
			previous->getParent()->setLeft(NULL); // Reset parents right
		} else {
			previous->getParent()->setLeft(previous->getLeft());
		}
	}
}

void LocationTree::detachNext(Node* next) {
	LocationTree::resetBalFactUpToRoot(next);
	if (next->getIdent() > next->getParent()->getIdent()) { // If parent left
		if (next->getRight() == NULL) { // next = leaf
			next->getParent()->setRight(NULL); // Reset parent's right
		} else {
			next->getParent()->setRight(next->getRight());
		}
	} else {
		if (next->getRight() == NULL) {  // next = leaf
			next->getParent()->setLeft(NULL);
		} else {
			next->getParent()->setLeft(next->getRight());
		}
	}
}

 void LocationTree::resetBalFactUpToRoot(Node* node) {
	Node* reBalTest = node;
	Node* reBalPar = node->getParent();
	while (reBalPar->getParent() != NULL) {
		if (reBalTest->getIdent() < reBalPar->getIdent()) {  // if test on left of parent
			reBalPar->minusCL();
		} else {
			reBalPar->minusCR();
		}
		reBalTest = reBalTest->getParent();
		reBalPar = reBalPar->getParent();
	}
	if (reBalTest->getIdent() < reBalPar->getIdent()) {  // if test on left of parent
		reBalPar->minusCL();
	} else {
		reBalPar->minusCR();
	}
 }


// Remove node
void LocationTree::freeNode(Node* leaf) {
	if (leaf != NULL) {
		freeNode(leaf->getLeft());
		freeNode(leaf->getRight());
		delete leaf;
	}
}

Node* LocationTree::getCity(Node* node, string ident)  {
	if (node != NULL) {
		if (ident == node->getIdent()) {
		return node;
		}
		if (ident < node->getIdent()) {
		return getCity(node->getLeft(), ident);
		}
		else {
		return getCity(node->getRight(), ident);
		}
	}
	else {
		return NULL;
	}
}

// Function rotation for LL/RR rotation or pt2 of LR/RL rotation
void LocationTree::rotateLL() {
	Node* newParent;
	newParent = balancePoint->getLeft();
	newParent->setParent(balancePoint->getParent());
	// Check if root
	if (balancePoint->getParent() == NULL) {
		root = newParent;
	} else if (balancePoint->getIdent() < balancePoint->getParent()->getIdent()) {
		balancePoint->getParent()->setLeft(newParent);
	} else {
		balancePoint->getParent()->setRight(newParent);
	}
	balancePoint->setParent(newParent);
	balancePoint->setLeft(newParent->getRight());
	if (balancePoint->getLeft() != NULL ) {
		balancePoint->getLeft()->setParent(balancePoint);
	}
	newParent->setRight(balancePoint);

	balancePoint->minusCL();
	balancePoint->minusCL();
	newParent->plusCR();
}

void LocationTree::rotateRR() {
	Node* newParent;
	newParent = balancePoint->getRight();
	newParent->setParent(balancePoint->getParent());
	// Check if root
	if (newParent->getParent() == NULL) {
		root = newParent;
	} else if (balancePoint->getIdent() < balancePoint->getParent()->getIdent()) {
		balancePoint->getParent()->setLeft(newParent);
	} else {
		balancePoint->getParent()->setRight(newParent);
	}
	balancePoint->setParent(newParent);
	balancePoint->setRight(newParent->getLeft());
	if (balancePoint->getRight() != NULL ) {
		balancePoint->getRight()->setParent(balancePoint);
	}

	newParent->setLeft(balancePoint);
	balancePoint->minusCR();
	balancePoint->minusCR();
	newParent->plusCL();
}

void LocationTree::rotateRL() {
	// rotate clockwise, RL case pt1
		midNode = balancePoint->getRight();
		insertedNode = midNode->getLeft();
		insertedNode->setParent(balancePoint); // 1 (8 ->A)
		midNode->setLeft(insertedNode->getRight()); // 2 (7 ->12)
		insertedNode->setRight(midNode); // 3 (10 ->C)
		midNode->setParent(insertedNode);  // 4 (5 ->B)
		balancePoint->setRight(insertedNode); // 5 (2 ->B)
		if (midNode->getLeft() != NULL) {
			midNode->getLeft()->setParent(midNode); // 6 (12 ->C)
		}
		// adjust balance factors
		insertedNode->plusCR();
		insertedNode->setCR(insertedNode->getCR() + midNode->getCR());
		midNode->minusCL();
		}

void LocationTree::rotateLR() {
	// rotate anticlockwise, LR case pt1
		midNode = balancePoint->getLeft();
		insertedNode = midNode->getRight();
		insertedNode->setParent(balancePoint); // 1 (
		midNode->setRight(insertedNode->getLeft()); // 2
		insertedNode->setLeft(midNode); // 3
		midNode->setParent(insertedNode); // 4
		balancePoint->setLeft(insertedNode); // 5
		if (midNode->getRight() != NULL) {
			midNode->getRight()->setParent(midNode); // 6
		}
		// adjust balance factors
		//insertedNode->plusCL();
		//insertedNode->setCL(insertedNode->getCL() + midNode->getCR());
		//midNode->minusCR();
}

string LocationTree::serialise(Node* node){
stringstream ss;
ss << node->location->serialise() << "\n";
if (node->getLeft() != NULL) {
ss << serialise(node->getLeft());
}
if (node->getRight() != NULL) {
ss << serialise(node->getRight());
}
return ss.str();
}

string LocationTree::displayTrav(Node* node){
stringstream ss;
ss << node->displayLocs() << "\n";
if (node->getLeft() != NULL) {
	ss << displayTrav(node->getLeft());
}
if (node->getRight() != NULL) {
	ss << displayTrav(node->getRight());
}
return ss.str();
}

 // Finding the Smallest
int LocationTree::findMinDepth(Node* test) {
	int leftHeight = 1;
	int rightHeight = 1;
	if (test->getLeft() != NULL) {
		leftHeight += findMinDepth(test->getLeft());
	}
	if (test->getRight()  != NULL) {
		leftHeight += findMinDepth(test->getRight());
	}
	return min(leftHeight, rightHeight);
}

// Finding the Largest node
int LocationTree::findMaxDepth(Node* test) {
	if (test == NULL) {
		return 0;
	} else {
		return 1 + max(findMaxDepth(test->getLeft()), findMaxDepth(test->getRight()));
	}
}

// Finding the balance factor
int LocationTree::getBalanceFactor(Node* test) {
	int lbf, rbf;
	if (test->getLeft() == NULL) {
		lbf = 0;
	} else {
		lbf = findMaxDepth(test->getLeft());
	}
	if (test->getRight() == NULL) {
		rbf = 0;
	} else {
		rbf = findMaxDepth(test->getRight());
	}
	return (lbf - rbf);
}



