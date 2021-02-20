#pragma once
#include <list>
#include <string>


using std::string;
using std::list;
using std::ostream;




class Graph {
public:
	Graph(string file);
	void printBFT(ostream& out);
private:
	list<int>* adjList;
	int numNodes;
};