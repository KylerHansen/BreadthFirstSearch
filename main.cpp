#pragma once
#include "Graph.h"
#include<iostream>
using namespace std;



int main() {
	std::ostream out(nullptr);
	out.rdbuf(cout.rdbuf());

	cout << "Graph 1 Created" << endl;
	Graph g1("graph.txt");
	cout << endl;
	cout << endl;

	cout << "Graph 2 Created" << endl;
	Graph g2("graph2.txt");
	cout << endl;
	cout << endl;

	cout << "Printing graph 1 " << endl;
	g1.printBFT(out);
	cout << endl;

	cout << "Printing graph 2 " << endl;
	g2.printBFT(out);

	return 0;
}