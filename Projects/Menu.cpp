#include <iostream>
//#include "Location.h"
//#include "Node.h"
#include "Menu.h"

using namespace std;

//constructor
Menu::Menu()
{
// Nothing to do, wait till next week
}

void Menu::menuOptions(int &choice) {

    do {
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t- World Distance Calculator -" << endl;
    cout << "\t\t\t-----------------------------" << endl;

    cout << "\tMain Menu - Choose an Option below:" << endl << endl;

    cout << "\t1. Add Record" << endl;
    cout << "\t2. Administer Record" << endl;
    cout << "\t3. Find Distance" << endl << endl;
    cout << "\t5. Quit" << endl << endl;

    cout << "\tChoose an Option: ";
    cin >> choice;


        switch(choice){
            case 1:
                addRecord();
                break;
            case 2:
                administerRecord();
                break;
            case 3:
                cout << "Find Distance";
                break;
            case 4:
                cout << "Quit";
                exit(EXIT_SUCCESS);
                break;
            default:
                cout << endl << "Invalid Choice" <<endl << endl;
                break;
        }
    } while (choice != 4);
}

void Menu::addRecord() {

    char city[10], country[10], continent[10], latitude[10], longitude[10];

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t- World Distance Calculator -" << endl;
    cout << "\t\t\t-----------------------------" << endl << endl;

    cout << "\tAdd Record" << endl << endl;

    cout << "\tEnter City: "; cin >> city;
    cout << "\tEnter Country: "; cin >> country;
    cout << "\tEnter Continent: "; cin >> continent;
    cout << "\tEnter Latitude: "; cin >> latitude;
    cout << "\tEnter Longitude: "; cin >> longitude;
    cout << endl;
}

void Menu::administerRecord() {

    int choice;
    char city[10];

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t- World Distance Calculator -" << endl;
    cout << "\t\t\t-----------------------------" << endl << endl;

    cout << "\tAdminister Record - Find by:" << endl << endl;

    cout << "\t1. City" << endl;
    cout << "\t2. Country" << endl;
    cout << "\t3. Continent" << endl;
    cout << "\t4. Show All" << endl;
    cout << "\t5. Quit to Main Menu" << endl;

    cout << endl << "\tChoose an Option: ";
    cin >> choice;

    do {
        switch(choice){
            case 1:
                cout << "Enter City Name: "; cin >> city;
                cout << endl << "Cities found matching "; city;
            }
    } while (choice != 5);

}

void Menu::findDistance() {
}



