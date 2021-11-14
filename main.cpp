#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "Tria.h"
using namespace std;

int main() {
	Triangle tr;
	double f;
	string str, line;

	ifstream inf("input");
	ofstream outf("output");
	if (inf.is_open() && outf.is_open()) {
		while (!inf.eof()) {
			Triangle tr;
			for (int i = 0; i < 3; i++) {
				inf >> f >> str;
				tr.edge(f, i);
				tr.unit(str, i);
			}
			outf << tr.areaToString();
		}
		inf.close();
		outf.close();
	}
	return 0;
}
