//============================================================================
// Name        : Location.cpp
// Author      : Jemble
// Date        :
// Version     :
// Copyright   : copyright reserved
// Description : A Location Class to store cities
//============================================================================/*

#include "Location.h"

using namespace std;

// Default Constructor
// Standard Contructor
Location::Location(string name, string country, string region, int latDeg, int latMin,
		string latDir, int lonDeg, int lonMin, string lonDir) {
	//cout << "Location object created with name: " << name << endl;
    setRegion(region);
	setCityName(name);
	setCountryName(country);
	setLatDeg(latDeg);
	setLatMin(latMin);
	setLatDirection(latDir);
	setLonDeg(lonDeg);
	setLonMin(lonMin);
	setLonDirection(lonDir);

}

Location::~Location(){};

void Location::setCityName(string name) {
	cityName = name;
}

string Location::getCityName() {
	return cityName;
}

void Location::setCountryName(string country) {
	countryName = country;
}

string Location::getCountryName() {
	return countryName;
}

void Location::setRegion(string region) {
	this->region = region;
}

string Location::getRegion() {
	return region;
}

void Location::setLatDeg(int deg) {
	cityLatDeg = deg;
}

void Location::setLatMin(int min) {
	cityLatMin = min;
}

void Location::setLatDirection(string dir) {
	cityLatDirection = dir;
}

void Location::setLonDeg(int lon) {
	cityLonDeg = lon;
}

void Location::setLonMin(int min) {
	cityLonMin = min;
}

void Location::setLonDirection(string dir) {
	cityLonDirection = dir;
}

int Location::getLatDeg() {
	return cityLatDeg;
}

int Location::getLatMin() {
	return cityLatMin;
}

string Location::getLatDirection() {
	return cityLatDirection;
}

int Location::getLonDeg() {
	return cityLonDeg;
}

int Location::getLonMin() {
	return cityLonMin;
}

string Location::getLonDirection() {
	return cityLonDirection;
}

