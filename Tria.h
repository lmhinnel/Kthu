#pragma once

#include<string>
#include<math.h>

class Triangle {
private:
	enum UNIT { mm, cm, dm, m };
	double e[3]; // 3 edges of triangle;
	std::string type;

public:
	Triangle();

	// Enter edge respectively
	void edge(double f, int i);

	// Enter unit of edge respectively
	void unit(std::string str, int i);

	// Calculate triangle's area
	double area();
	
	// Print area of triangle
	std::string areaToString();
};
