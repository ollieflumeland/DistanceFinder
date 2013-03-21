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

Location::Location(string name, string country, int latDeg, int latMin,
		string latDir, int lonDeg, int lonMin, string lonDir) {
	setCityName(name);
	setCountryName(country);
	setLatDeg(latDeg);
	setLatMin(latMin);
	setLatDirection(latDir);
	setLonDeg(lonDeg);
	setLonMin(lonMin);
	setLonDirection(lonDir);
	dupe = 0;

}

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

void Location::setRegion(int region) {
	this->region = region;
}

int Location::getRegion() {
	return region;
}

void Location::setRefNumber(int ref) {
	refNumber = ref;
}

int Location::getRefNumber() {
	return refNumber;
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

