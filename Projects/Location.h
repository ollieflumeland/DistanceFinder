#ifndef Location_H
#define Location_H

#include <iostream>
#include <string>

using namespace std;

class Location {
private:
	//Variables
	string cityName;
	string countryName;
	int region;
	int cityLatDeg;
	int cityLatMin;
	string cityLatDirection;
	int cityLonDeg;
	int cityLonMin;
	string cityLonDirection;

public:


	//Constructor for class Location
	Location(string name, string country, int latDeg, int latMin, string latDir, int lonDeg, int lonMin, string lonDir);
	Location(); // default constructor

	//Destructor
	~Location();

	//  Function Prototypes
	void setCityName(string name);
	string getCityName();
	void setCountryName(string country);
	string getCountryName();
	void setRegion(int region);
	int getRegion();
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

};

#endif

