/*
 * ReaderWriter.cpp
 *
 *  Created on: Mar 20, 2013
 *      Author: bourgein
 */

#include "ReaderWriter.h"

using namespace std;

//Constructor
ReaderWriter::ReaderWriter() {
	};

LocationTree * ReaderWriter::createTreeFromFile(string fileName) {
	LocationTree* locTree = new LocationTree();
	fstream inf;
	inf.open(fileName.c_str(),ios::in);

	/*note this is not istream.getline() but
	 * part of the std namespace <string> stuff
	 */
	while (!inf.eof()) {

		string name;
		getline(inf,name,'|');
	   //	cout << "name: " << name << endl;
		Location *tempLoc;

		string country;
		string region;
		string latDegString;
		string latMinString;
		string latDirection;

		getline(inf, country, '|');
		getline(inf,region,'|');
		//get lat stuff
		getline(inf, latDegString, '|');
		int latDeg = atoi(latDegString.c_str());
		getline(inf, latMinString, '|');
		int latMin = atoi(latMinString.c_str());
		getline(inf, latDirection, '|');

		string lonDegString;
		string lonMinString;
		string lonDirection;

		//get lon stuff
		getline(inf, lonDegString, '|');
		int lonDeg = atoi(lonDegString.c_str());
		getline(inf, lonMinString, '|');
		int lonMin = atoi(lonMinString.c_str());
		getline(inf, lonDirection);

		tempLoc = new Location(name, country, region, latDeg, latMin, latDirection,
				lonDeg, lonMin, lonDirection);
		locTree->addNode(tempLoc);
	}
	inf.close();
	return locTree;
}


void ReaderWriter::saveFile(string fileName, LocationTree* locTree){
	ofstream saveFile(fileName.c_str()); //ofstream should clear file

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
