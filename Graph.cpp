#include "Graph.h"
#include <fstream>
#include <stdexcept>
#include <cstdint>
#include <queue>
#include<iostream>
#include<set>

using std::ifstream;
using std::invalid_argument;
using std::list;
using std::queue;
using std::set;
using std::cout;
using std::endl;



Graph::Graph(string file) {
	ifstream input;
	input.open(file);
	if (!input) {
		throw invalid_argument("Could not read file");
	}
	input >> numNodes; //insert first line for number of nodes
	adjList = new list<int>[numNodes];  //create adjacency which is an dynamic array filled with list of integers

	for (int i = 0; i < numNodes; i++) {
		int value;
		input >> value;
		cout << i <<"-> ";
		while (value >= 0) { //stops at negative numbers
			adjList[i].push_back(value);
			cout << value << "-> ";  //used for testing purposes
			input >> value;
		}
		cout << endl;
	}

}



void Graph::printBFT(ostream& out) {
	queue<int> unvisited;
	set<int> discovered;

	unvisited.push(0);
	discovered.insert(0);
	int curr;
	

	while (unvisited.size() > 0) {
		curr = unvisited.front(); //may need to switch order
		unvisited.pop();
		out << curr << " ";

		for (list<int>::iterator listIt = adjList[curr].begin(); listIt != adjList[curr].end(); listIt++) {
			if (discovered.count(*listIt) == 0) {
				unvisited.push(*listIt);
				discovered.insert(*listIt);
			}
		}
	}
	out << endl;
}