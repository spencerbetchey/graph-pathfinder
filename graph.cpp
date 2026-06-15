#include "graph.h"

//Add a vertex to the graph if it doesn't already exist
void Graph::addVertex(const string& name) {
    if (adjacencyList.find(name) == adjacencyList.end()) {
        adjacencyList[name] = vector<Edge>();
        cout << "Vertex \"" << name << "\" added." << endl;
    } else {
        cout << "Vertex \"" << name << "\" already exists." << endl;
    }
}

//Add a weighted edge between two vertices
void Graph::addEdge(const string& from, const string& to, int weight) {
    //Make sure both vertices exist before adding an edge
    if (!hasVertex(from) || !hasVertex(to)) {
        cout << "Error: One or both vertices not found." << endl;
        return;
    }

    //Add edge in both directions (since it's an undirected graph)
    adjacencyList[from].push_back({to, weight});
    adjacencyList[to].push_back({from, weight});

    cout << "Edge added: " << from << " <-> " << to << " (weight: " << weight << ")" << endl;
}

//Print every vertex and its neighbors
void Graph::printGraph() const {
    cout << "\n--- Graph Structure ---" << endl;
    for (const auto& pair : adjacencyList) {
        cout << pair.first << ": ";
        for (const Edge& edge : pair.second) {
            cout << "(" << edge.neighbor << ", " << edge.weight << ") ";
        }
        cout << endl;
    }
    cout << "-----------------------\n" << endl;
}

//Check if a vertex exists in the graph
bool Graph::hasVertex(const string& name) const {
    return adjacencyList.find(name) != adjacencyList.end();
}

//Return the full adjacency list
const unordered_map<string, vector<Edge>>& Graph::getAdjacencyList() const {
    return adjacencyList;
}