//============================================================================
// Name        : Menu.cpp
// Authors     : Bourgein, Oliver, Worth
// Date        :
// Version     :
// Copyright   : copyright reserved
// Description : A Menu Class to handle command line interface
//============================================================================/*

#include <string>
#include <iostream>
#include <algorithm>
#include <limits>
#include "Menu.h"

using namespace std;

//Constructor
Menu::Menu() {
	ReaderWriter rw;
	string filename = "locations.txt";
	locT = rw.createTreeFromFile(filename);
}

void Menu::menuOptions(int &choice) {
	int defChoice = -1;
    do {
    cout << endl << endl << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t- World Distance Calculator -" << endl;
    cout << "\t\t\t-----------------------------" << endl;

    cout << endl << "Main Menu - Choose an Option below:" << endl << endl;

	cout << "1. Find Distance" << endl;
	cout << "2. Add Record" << endl;
	cout << "3. Administer Record" << endl;
	cout << "4. Save Changes" << endl;
	cout << "5. Display Locations" << endl;
	cout << "6. Save & Quit" << endl << endl;

	cout << "Choose an Option: ";
	cin >> choice;

		switch(choice){
			case 1:
				findDistance();
				break;
			case 2:
				addRecord();
				break;
			case 3:
				administerRecord();
				break;
			case 4:
				saveFile();
				break;
			case 5:
				cout << endl;
				displayLocations();
				break;
			case 6:
				saveFile();
                exit(EXIT_SUCCESS);
			default:
				cout << endl << "Invalid Choice" <<endl << endl;
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				Menu:menuOptions(defChoice);
				break;
		}
		cin.ignore();
	} while (choice != 6);
}

void Menu::addRecord() {

	Location *newLoc;
	string city;
	string country;
	string region;
	int latDeg;
	int latMin;
	string latDir;
	int lonDeg;
	int lonMin;
	string lonDir;
	int cinFailed = 1;

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t- World Distance Calculator -" << endl;
    cout << "\t\t\t-----------------------------" << endl << endl;

	cout << "Add Record" << endl << endl;
	cin.ignore();
	cout << "Enter City: "; getline(cin,city);
	cout << "Enter Country: "; getline(cin,country);
	cout << "Enter Region: "; getline(cin,region);

	do {
		cout << "Enter Latitude Degrees: ";
		cin >> latDeg;
		cinFailed = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX,'\n');
	}
	while (cinFailed);

	do {
		cout << "Enter Latitude Minutes: ";
		cin >> latMin;
		cinFailed = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX,'\n');
	}
	while (cinFailed);

	while ((latDir != "N") && (latDir != "n") && (latDir != "S") && (latDir != "s")){
		cout << "Enter Latitude Direction (N or S): "; cin >> latDir;
	}

	do {
	   cout << "Enter Longitude Degrees: ";
	   cin >> lonDeg;
		cinFailed = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX,'\n');
	}
	while (cinFailed);

	do {
	   cout << "Enter Longitude Minutes: ";
	   cin >> lonMin;
	   cinFailed = cin.fail();
	   cin.clear();
	   cin.ignore(INT_MAX,'\n');
	}
	while (cinFailed);

	while ((lonDir != "W") && (lonDir != "w") && (lonDir != "E") && (lonDir != "e")){
	cout << "Enter Longitude Direction (W or E): "; cin >> lonDir; cin.ignore();
	}

	newLoc = new Location(city, country, region, latDeg, latMin, latDir,
				lonDeg, lonMin, lonDir);

	locT->addToTree(locT, newLoc, locT->getRoot(), city);
	cout << endl;
}

void Menu::administerRecord() {

	int choice2;
	int fieldChoice;
	string city;
	string strTemp;
	int intTemp;

    cout << endl << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t- World Distance Calculator -" << endl;
    cout << "\t\t\t-----------------------------" << endl << endl;

	cout << "Administer Record:" << endl << endl;

   cout << "Enter City Name: "; cin.ignore(); getline(cin,city);
   rootNode = locT->getRoot();
   foundLoc = Menu::getExactLocation(rootNode, city);

   cout << endl;
   cout << endl << "Do you want to Modify or Delete the record?";
   cout << endl << endl << "1. Modify" << endl;
   cout << "2. Delete" << endl << endl;
   cout << "3. Quit to Main Menu" << endl << endl;

   cout << "Modify/Delete a Record - Choose an option: ";
   cin >> choice2; cin.ignore();

   switch(choice2){
	case 1:
		cout << endl << "Editing " << foundLoc->getCityName() << ", in " << foundLoc->getCountryName();
		do {
		cout << endl << endl << "What part of the record do you want to modify?" << endl;
		cout << endl << "1. Country";
		cout << endl << "2. Region";
		cout << endl << "3. Latitude Degrees";
		cout << endl << "4. Latitude Minutes";
		cout << endl << "5. Latitude Direction";
		cout << endl << "6. Longitude Degrees";
		cout << endl << "7. Longitude Minutes";
		cout << endl << "8. Longitude Direction";
		cout << endl << "9. Quit to Main Menu" << endl << endl;

		cout << "Choose an option: ";
		cin >> fieldChoice; cin.ignore();

			switch(fieldChoice){
				case 1:
					cout << endl << "Edit Country (currently " << foundLoc->getCountryName() << "): ";
					getline(cin,strTemp); foundLoc->setCountryName(strTemp);
					break;
				case 2:
					cout << "Edit Region (currently " << foundLoc->getRegion() << "): ";
					getline(cin,strTemp); foundLoc->setRegion(strTemp);
					break;
				case 3:
					cout << "Edit Latitude Degrees (currently " << foundLoc->getLatDeg() << "): ";
					cin >> intTemp; foundLoc->setLatDeg(intTemp); cin.ignore();
					break;
				case 4:
					cout << "Edit Latitude Minutes (currently " << foundLoc->getLatMin() << "): ";
					cin >> intTemp; foundLoc->setLatMin(intTemp); cin.ignore();
					break;
				case 5:
					cout << "Edit Latitude Direction (currently " << foundLoc->getLatDirection() << "): ";
					cin >> strTemp; foundLoc->setLatDirection(strTemp); cin.ignore();
					break;
				case 6:
					cout << "Edit Longitude Degrees (currently " << foundLoc->getLonDeg() << "): ";
					cin >> intTemp; foundLoc->setLonDeg(intTemp); cin.ignore();
					break;
				case 7:
					cout << "Edit Longitude Minutes (currently " << foundLoc->getLonMin() << "): ";
					cin >> intTemp; foundLoc->setLonMin(intTemp); cin.ignore();
					break;
				case 8:
					cout << "Edit Longitude Direction (currently " << foundLoc->getLonDirection() << "): ";
					cin >> strTemp; foundLoc->setLonDirection(strTemp); cin.ignore();
					break;
				case 9:
					Menu::menuOptions(choice2);
					break;
				default:
					cout << endl << "Invalid Choice";
					break;
			}

		cout << endl << endl << "Modified Record:" << endl << endl;
		cout << foundLoc->getCityName();
		cout << ", " << foundLoc->getCountryName();
		cout << ", " << foundLoc->getRegion();
		cout << ", " << foundLoc->getLatDeg();
		cout << ", " << foundLoc->getLatMin();
		cout << ", " << foundLoc->getLatDirection();
		cout << ", " << foundLoc->getLonDeg();
		cout << ", " << foundLoc->getLonMin();
		cout << ", " << foundLoc->getLonDirection() << endl << endl;
		}
		while (fieldChoice != 9);

	case 2:
		cout << endl << "DELETING ENTRY" << endl << endl;
		if (foundNode->getDupsNo() == 0) {
			if (locT->deleteNode(city)) {
				cout << "City has been removed" << endl << endl;
			} else {
				cout << "WARNING! Deletion unsuccessful" << endl << endl;
			}
		} else {
			if (locT->deleteDupNode(foundNode, foundLoc->getNum())) {
				cout << "City has been removed" << endl << endl;
			} else {
				cout << "WARNING! Deletion unsuccessful" << endl << endl;
			}
		}
		system("PAUSE");
		break;
	case 3:
		break;
	default:
		cout << endl << "Invalid Choice" <<endl << endl;
		cin.clear();
	   	cin.ignore();
		break;
	}
}

Location* Menu::getExactLocation(Node* node, string city) {
	int choice = -1;
	foundNode = locT->getCity(node, city);
	if (foundNode == NULL) {
		cout << endl << "This city is not in the database." << endl << endl;
		system("PAUSE");
		Menu::menuOptions(choice);
	} else {
		foundLoc = foundNode->getLocation();
		if (foundNode->noDups == 0) {
			cout << endl << "City Name: " << foundLoc->getCityName()  << endl;
			cout << "In Country: " << foundNode->getLocation()->getCountryName() << endl;
			cout << "In Region: " << foundNode->getLocation()->getRegion() << endl;
			cout << "Latitude Degrees: " << foundNode->getLocation()->getLatDeg() << endl;
			cout << "Latitude Minutes: " << foundNode->getLocation()->getLatMin() << endl;
			cout << "Latitude Direction: " << foundNode->getLocation()->getLatDirection() << endl;
			cout << "Longitude Degrees: " << foundNode->getLocation()->getLonDeg() << endl;
			cout << "Longitude Minutes: " << foundNode->getLocation()->getLonMin() << endl;
			cout << "Longitude Direction: " << foundNode->getLocation()->getLonDirection() << endl;
		} else {
			int totalDups = foundNode->getDupsNo();
			cout << endl << totalDups+1 << " match(es) found for: " << foundLoc->getCityName()  << endl;
			for (int i=0; i <= totalDups; i++) {
				cout << foundLoc->getNum() << ". " << foundLoc->getCityName();
				cout << ", " << foundLoc->getCountryName();
				cout << ", " << foundLoc->getRegion();
				cout << ", " << foundLoc->getLatDeg();
				cout << ", " << foundLoc->getLatMin();
				cout << ", " << foundLoc->getLatDirection();
				cout << ", " << foundLoc->getLonDeg();
				cout << ", " << foundLoc->getLonMin();
				cout << ", " << foundLoc->getLonDirection() << endl;
				foundLoc = foundLoc->getDups();
			}
			cout << totalDups+2 << ". None of the above " << endl << endl;
			int citySelect;
			int cinFailed;
			do {
			   cout << "Enter a choice (number): ";
			   cin >> citySelect;
			   cinFailed = cin.fail();
			   cin.clear();
			   cin.ignore(INT_MAX,'\n');
			}
			while (citySelect < 1 || citySelect > totalDups + 2 || cinFailed);


			foundLoc = foundNode->getLocation();
			if (citySelect == totalDups+2) {
				Menu:menuOptions(choice);
			} else {
				while (foundLoc->getNum() != citySelect) {
					foundLoc = foundLoc->getDups();
				}
			}
		}
	}
	return foundLoc;
}

void Menu::findDistance() {
	string cityOne;
	string cityTwo;
	int inKm;
	int cinFailed;
	Node* rootNode = locT->getRoot();

	cout << endl << "\t\t\t-----------------------------" << endl;
	cout << "\t\t\t- World Distance Calculator -" << endl;
	cout << "\t\t\t-----------------------------" << endl << endl;

	cout << "Find Distance" << endl << endl;
	cout << "Enter the First City's Name: ";
	getline(cin,cityOne);
	Location* locOne = Menu::getExactLocation(rootNode, cityOne);
	cout << "Enter the Second City's Name: ";
	getline(cin,cityTwo);
	Location* locTwo = Menu::getExactLocation(rootNode, cityTwo);
	do {
	cout << "Result in Miles (1) or Km (2)?: ";
	cin >> inKm;
	cinFailed = cin.fail();
	cin.clear();
	cin.ignore(INT_MAX,'\n');
	}
	while (inKm < 1 || inKm > 2 || cinFailed);

	Calculator calc;
	if (inKm == 1) {
		double dist = calc.getDistanceBetween(locOne,locTwo,0);
		cout << "Distance between is: " << dist << " Miles" << endl;
	}
	else {
		double dist = calc.getDistanceBetween(locOne,locTwo,1);
		cout << "Distance between is: " << dist << "Km" << endl;
	}
}

void Menu::saveFile(){
	ReaderWriter rw;
	cout << endl << "Saving Cities to file: locations.txt" << endl;
	rw.saveFile("locations.txt",locT);
}

void Menu::displayLocations() {
	string output = locT->serialise(locT->getRoot());
	cout << output << endl;

	cout << "Press any key to continue...";
	cin.get();

	int choice = -1;
	Menu:menuOptions(choice);

}



