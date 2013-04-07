//============================================================================
// Name        : Menu.h
// Authors     : Bourgein, Oliver, Worth
// Date        :
// Version     :
// Copyright   : copyright reserved
// Description : A Menu Class to handle command line interface
//============================================================================/*

#ifndef MENU_H_
#define MENU_H_

#include "Location.h"
#include "Node.h"
#include "LocationTree.h"
#include "ReaderWriter.h"
#include "Calculator.h"

using namespace std;

class Menu {
private:
	Node* rootNode;
	Node* foundNode;
	Location* foundLoc;

public:
	//Constructor
	Menu();

	LocationTree* locT;

	//Function Prototypes
    void menuOptions(int &choice);
    void addRecord();
	void administerRecord();
	void findDistance();
	void saveFile();
	void displayLocations();
	Location* getExactLocation(Node* node, string city);

};

#endif
