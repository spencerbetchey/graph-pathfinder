#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

//Represents a single edge connecting to a neighbor with a given weight
struct Edge {
    string neighbor;
    int weight;
};

//Graph class 
//Adjacency list representation of a graph where each vertex is a string and edges have weights
class Graph {
private:
    //Maps each vertex name to a list of its edges
    unordered_map<string, vector<Edge>> adjacencyList;

public:
    //Add a vertex to the graph
    void addVertex(const string& name);

    //Add a weighted edge between two vertices
    void addEdge(const string& from, const string& to, int weight);

    //Print the graph to the console
    void printGraph() const;

    //Check if a vertex exists in the graph
    bool hasVertex(const string& name) const;

    //Get the adjacency list (for BFS and Djikstra's algorithm)
    const unordered_map<string, vector<Edge>>& getAdjacencyList() const;        
};

#endif