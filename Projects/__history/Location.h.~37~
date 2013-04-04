//============================================================================
// Name        : Location.h
// Authors     : Bourgein, Oliver, Worth
// Date        :
// Version     :
// Copyright   : copyright reserved
// Description : A Location Class to store cities
//============================================================================/*

#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>


using namespace std;

class Location {
private:
	//Variables
	string cityName;
	string countryName;
	string region;
	int cityLatDeg;
	int cityLatMin;
	string cityLatDirection;
	int cityLonDeg;
	int cityLonMin;
	string cityLonDirection;
	Location* dups;
	int locNum;

public:

	//Constructor for class Location
	Location(string name, string country,string region, int latDeg, int latMin, string latDir, int lonDeg, int lonMin, string lonDir);
	Location(); // default constructor

	//Destructor
	~Location();

	//  Function Prototypes
	void setCityName(string name);
	string getCityName();
	void setCountryName(string country);
	string getCountryName();
	void setRegion(string region);
	string getRegion();
	void setLatDeg(int deg);
	void setLatMin(int min);
	void setLatDirection(string dir);
	void setLonDeg(int deg);
	void setLonMin(int min);
	void setLonDirection(string dir);
	int getLatDeg();
	int getLatMin();
	string getLatDirection();
	int getLonDeg();
	int getLonMin();
	string getLonDirection();
	Location* getDups();
	Location* setDups(Location* dups);
	int getNum();
	void plusNum();
	void minusNum();

};

#endif /* LOCATION_H_ */

