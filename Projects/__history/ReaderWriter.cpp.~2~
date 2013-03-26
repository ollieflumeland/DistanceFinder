/*
 * ReaderWriter.cpp
 *
 *  Created on: Mar 20, 2013
 *      Author: bourgein
 */

 #include "ReaderWriter.h"

using namespace std;

ReaderWriter::ReaderWriter() {
	};

LocationTree createTreeFromFile(string fileName) {
	LocationTree* tree;
	ifstream inf(fileName);

	string name;

	/*note this is not istream.getline() but
	 * part of the std namespace <string> stuff
	 */
	while (!getline(inf, name, '|').eof()) {
		Location* tempLoc;

		string country = getline(inf, country, '|');

		/*get lat stuff*/
		string latDegString = getline(inf, latDegString, '|');
		int latDeg;
		stringstream convert(latDegString);
		convert >> latDeg;
		string latMinString = getline(inf, latMinString, '|');
		int latMin;
		convert(latMinString);
		convert >> latMin;
		string latDirection = getline(inf, latDirection, '|');

		/*get lon stuff*/
		string lonDegString = getline(inf, lonDegString, '|');
		int lonDeg;
		stringstream convert(lonDegString);
		convert >> lonDeg;
		string lonMinString = getline(inf, lonMinString, '|');
		int lonMin;
		convert(lonMinString);
		convert >> lonMin;
		string lonDirection = getline(inf, lonDirection, '|');

		tempLoc = new Location(name, country, latDeg, latMin, latDirection,
				lonDeg, lonMin, lonDirection);
		tree->addNode(tempLoc->getCityName());
	}
	inf.close();
	return tree;
}

void saveFile(string fileName, LocationTree tree){
	ofstream saveFile(fileName); //ofstream should clear file

	if (saveFile.is_open()){
		//for each node of the tree
			//get location from node as tempLoc
			Location tempLoc;
			saveFile << tempLoc.getCityName();
			saveFile << "|";
			saveFile << tempLoc.getCountryName();
			saveFile << "|";
			saveFile << tempLoc.getRegion();
			saveFile << "|";
			saveFile << tempLoc.getLatDeg();
			saveFile << "|";
			saveFile << tempLoc.getLatMin();
			saveFile << "|";
			saveFile << tempLoc.getLatDirection();
			saveFile << "|";
			saveFile << tempLoc.getLonDeg();
			saveFile << "|";
			saveFile << tempLoc.getLonMin();
			saveFile << "|";
			saveFile << tempLoc.getLonDirection();
			saveFile << "\n";
		//end for each
		saveFile.close();
	}
	else{
		cout << "Unable to open file";
	}

}
