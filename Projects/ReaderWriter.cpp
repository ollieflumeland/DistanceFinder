//============================================================================
// Name : ReaderWriter.cpp
// Authors : Bourgein, Oliver, Worth
// Date : Created on: Mar 20, 2013
// Version :
// Copyright : copyright reserved
// Description : A Read/Write Class to handle file i/o
//============================================================================/*


#include "ReaderWriter.h"

using namespace std;

//Constructor
ReaderWriter::ReaderWriter() {
};

LocationTree * ReaderWriter::createTreeFromFile(string fileName) {
	LocationTree* locTree = new LocationTree();
	fstream inf;
	inf.open(fileName.c_str(),ios::in);

	Location *tempLoc;

	stringstream ss;
	string line;
	string name;
	string country;
	string region;
	string latDegString;
	string latMinString;
	string latDirection;
	string lonDegString;
	string lonMinString;
	string lonDirection;
	int latDeg;
	int latMin;
	int lonDeg;
	int lonMin;

	/*note this is not istream.getline() but
	* part of the std namespace <string> stuff
	*/
	while (!inf.eof()) {
		getline(inf,line);
		ss.clear();
		ss.str(line);

		getline(ss,name,'|');
		// cout << "name: " << name << endl;

		getline(ss, country, '|');
		getline(ss,region,'|');

		//get lat stuff
		getline(ss, latDegString, '|');
		latDeg = atoi(latDegString.c_str());
		getline(ss, latMinString, '|');
		latMin = atoi(latMinString.c_str());
		getline(ss, latDirection, '|');

		//get lon stuff
		getline(ss, lonDegString, '|');
		lonDeg = atoi(lonDegString.c_str());
		getline(ss, lonMinString, '|');
		lonMin = atoi(lonMinString.c_str());
		getline(ss, lonDirection);

		tempLoc = new Location(name, country, region, latDeg, latMin, latDirection,
		lonDeg, lonMin, lonDirection);
		locTree->addToTree(locTree, tempLoc, locTree->getRoot(), name);
	}
	inf.close();
	return locTree;
}


void ReaderWriter::saveFile(string fileName, LocationTree* locTree){
	ofstream saveFile(fileName.c_str()); //ofstream should clear file
	string treeString;
	treeString = locTree->serialise(locTree->getRoot());

	treeString = treeString.substr(0, treeString.size()-1);//trims last newline character
	if (saveFile.is_open()){
		saveFile << treeString;
		//end for each
		saveFile.close();
	}
	else{
		cout << "Unable to open file to save";
	}

}

