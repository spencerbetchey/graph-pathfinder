#include "graph.h"
#include "bfs.h"
#include "dijkstra.h"

int main() {

    Graph g;

    //Add vertices
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");

    //Add edges with weights
    g.addEdge("A", "B", 4);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 5);
    g.addEdge("C", "D", 1);
    g.addEdge("D", "E", 3);

    //Print the graph
    g.printGraph();

    //Test Breadth-First Search
    BFS bfs;
    vector<string> bfsPath = bfs.findPath(g, "A", "E");
    bfs.printPath(bfsPath, "A", "E");

    //Test Dijkstra
    Dijkstra dijkstra;
    vector<string> dijkstraPath = dijkstra.findPath(g, "A", "E");

    //Calculate total cost of the path
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

    //Test with a vertex that doesn't exist
    vector<string> badPath = dijkstra.findPath(g, "A", "Z");
    dijkstra.printPath(badPath, "A", "Z", 0);

    return 0;
}