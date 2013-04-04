/*
 * Calculator.cpp
 *
 *  Created on: Mar 14, 2013
 *      Author: bourgein
 */
 #include "Calculator.h"

 using namespace std;

Calculator::Calculator() {
}

double Calculator::getDistanceBetween(Location* firstLoc, Location* secondLoc) {
	this->loc1DecLat = convertToDec(firstLoc->getLatDeg(), firstLoc->getLatMin(),
			firstLoc->getLatDirection());
			//cout << "loc1DecLat: "<< this->loc1DecLat << endl;
	this->loc1DecLon = convertToDec(firstLoc->getLonDeg(), firstLoc->getLonMin(),
			firstLoc->getLonDirection());
			//cout << "loc1DecLon: "<< this->loc1DecLon << endl;
	this->loc2DecLat = convertToDec(secondLoc->getLatDeg(), secondLoc->getLatMin(),
			secondLoc->getLatDirection());
		   //	cout << "loc2DecLat: "<< this->loc2DecLat << endl;
	this->loc2DecLon = convertToDec(secondLoc->getLonDeg(), secondLoc->getLonMin(),
			secondLoc->getLonDirection());
			//�cout << "loc2DecLon: "<< this->loc2DecLon << endl;
	return calcDistBetween();
}

double Calculator::convertToDec(int deg, int min, string isNeg) {
	double result = deg + (min / 60);
	if (isNeg == "W" || isNeg == "S") {
		result = result * -1;
	}
	return result;

}

double Calculator::calcDistBetween() {
	double dLat = M_PI*(loc2DecLat - loc1DecLat)/180;   //result is in radians
	double dLon = M_PI*(loc2DecLon - loc1DecLon)/180;   //result is in radians
	double latOne = M_PI*loc1DecLat/180;       //radians
	double latTwo = M_PI*loc2DecLat/180;       //radians
	double a = pow((sin(dLat / 2)), 2) + cos(latOne) * cos(latTwo) * pow((sin(dLon / 2)), 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	double d = EARTH_RAD * c;

	return d;
}

