#ifndef BFS_H
#define BFS_H

#include <string>
#include <vector>
#include "graph.h"

using namespace std;

class BFS {
public:
    //Breadth-First Search 
    //Finds the shortest path between two vertices (not including weight)
    //Returns a vector of vertex names representing the path
    vector<string> findPath(const Graph& graph, const string& start, const string& end);

    //Print the path result
    void printPath(const vector<string>& path, const string& start, const string& end);
};

#endif