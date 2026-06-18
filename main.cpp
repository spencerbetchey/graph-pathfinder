#include "graph.h"
#include "bfs.h"
#include "dijkstra.h"
#include "fileloader.h"

int main() {

    Graph g;
    FileLoader loader;

    //Load the graph from the text file
    if (!loader.loadGraph(g, "graph.txt")) {
        return 1; //Exit if file loading failed
    }

    //Print the loaded graph
    g.printGraph();

    //Test Breadth-First Search
    BFS bfs;
    vector<string> bfsPath = bfs.findPath(g, "A", "E");
    bfs.printPath(bfsPath, "A", "E");

    //Test Dijkstra
    Dijkstra dijkstra;
    vector<string> dijkstraPath = dijkstra.findPath(g, "A", "E");

    //Calculate total cost of the Dijkstra path
    int totalCost = 0;
    const auto& adjList = g.getAdjacencyList();
    for (int i = 0; i < dijkstraPath.size() - 1; i++) {
        string current = dijkstraPath[i];
        string next = dijkstraPath[i + 1];
        for (const Edge& edge : adjList.at(current)) {
            if (edge.neighbor == next) {
                totalCost += edge.weight;
                break;
            }
        }
    }

    dijkstra.printPath(dijkstraPath, "A", "E", totalCost);

    return 0;
}