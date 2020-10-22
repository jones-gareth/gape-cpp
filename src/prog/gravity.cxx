/*
 * gravity.cpp
 *
 *  Created on: May 21, 2014
 *      Author: Gareth Jones
 */

#include <iostream>

using namespace std;

const double G = { 6.67384e-11 };
const double M { 5.97219e24 };
const double m { 800.0 };
const double re { 6378100.0 };
const double kwhInJoules {3.6e6};

double pe(double r) {
	return (-G * M * m) / r;
}

int main(int argc, char* argv[]) {

	double surfacePe = pe(re);
	double orbitPe = pe(re + 370000);

	cout << "surface PE joules " << surfacePe << endl;
	cout << "Orbit  PE joules " << orbitPe << endl;

	double diff = orbitPe - surfacePe;
	cout << "Difference joules " << diff << endl;
	double diffKwh = diff/kwhInJoules;
	cout << "Difference Kwh " << diffKwh<< endl;
}

