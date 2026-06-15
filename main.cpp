#include "graph.h"

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

    return 0;
}