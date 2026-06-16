#include "graph.h"
#include "bfs.h"

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

    vector<string> path1 = bfs.findPath(g, "A", "E");
    bfs.printPath(path1, "A", "E");

    vector<string> path2 = bfs.findPath(g, "B", "E");
    bfs.printPath(path2, "B", "E");

    //Test with a vertex that doesn't exist
    vector<string> path3 = bfs.findPath(g, "A", "Z");
    bfs.printPath(path3, "A", "Z");

    return 0;
}