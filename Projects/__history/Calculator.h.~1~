#include <iostream>
#include <string>
#include <cmath>
#include "Location.h"

using namespace std;

class Calculator {
public:
	Calculator(Location loc1, Location loc2);
	double getDistanceBetween();
private:
	Location loc1;
	Location loc2;

	double loc1DecLon;
	double loc1DecLat;

	double loc2DecLat;
	double loc2DecLon;

	double distanceBetween;
	double convertToDec(int deg, int min, string isNeg);
	void calcDistBetween();
};


