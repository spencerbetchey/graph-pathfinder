#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <string>
#include <vector>
#include "graph.h"

using namespace std;        

class Dijkstra {
public:
    //Finds the shortest path by total weight between two vertices
    //Returns a vector of vertex names representing the path
    vector<string> findPath(const Graph& graph, const string& start, const string& end);

    //Prints the path result and total cost
    void printPath(const vector<string>& path, const string& start, const string& end, int totalCost);
};

#endif