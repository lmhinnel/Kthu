#include<math.h>
#include<iostream>
#include<iomanip>
#include "Tria.h"
using namespace std;

Triangle::Triangle() {
	e[0] = NULL;
	e[1] = NULL;
	e[2] = NULL;
	type = "T";
}

// Enter edge respectively
void Triangle::edge(double f, int i) {
	if (f < 0) type = "WI";
	else e[i] = f;
}

// Enter unit of edge respectively
void Triangle::unit(string str, int i) {
	UNIT u; // convert string to enum UNIT
	str == "mm" ? u = mm : (str == "cm" ? u = cm : (str == "dm" ? u = dm : u = m));
	switch (u) {
	case mm:
		e[i] *= 0.001; break;
	case cm:
		e[i] *= 0.01; break;
	case dm:
		e[i] *= 0.1; break;
	}
}

// Calculate triangle's area
double Triangle::area() {
	if (type == "WI") return 0.0;

	if ((e[0] + e[1] > e[2]) && (e[2] + e[1] > e[0]) && (e[0] + e[2] > e[1])) {
		double p = (e[0] + e[1] + e[2]) / 2;
		return sqrt(p * (p - e[0]) * (p - e[1]) * (p - e[2]));
	}

	type = "NT";
	return 0.0;
}

std::string Triangle::areaToString() {
	double s = area();
	if (type == "T") {
		std::string str = "Area: " + to_string((round)(s * 10000) / 10000.0) + " m2\n\n";
		return str;
	}
	else return type + "\n\n";
}
