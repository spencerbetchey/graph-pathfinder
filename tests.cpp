#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "graph.h"
#include "bfs.h"
#include "dijkstra.h"
#include "fileloader.h"

//Graph Tests
TEST_CASE("Adding vertices to the graph") {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");

    CHECK(g.hasVertex("A") == true);
    CHECK(g.hasVertex("B") == true);
    CHECK(g.hasVertex("C") == false);
}

TEST_CASE("Adding duplicate vertex does not crash") {
    Graph g;
    g.addVertex("A");
    g.addVertex("A"); //Should just print a message, not crash
    CHECK(g.hasVertex("A") == true);
}

TEST_CASE("Adding edges between vertices") {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addEdge("A", "B", 5);

    //Check both directions since graph is undirected
    const auto& adjList = g.getAdjacencyList();
    bool abFound = false;
    bool baFound = false;

    for (const Edge& e : adjList.at("A")) {
        if (e.neighbor == "B" && e.weight == 5) abFound = true;
    }
    for (const Edge& e : adjList.at("B")) {
        if (e.neighbor == "A" && e.weight == 5) baFound = true;
    }

    CHECK(abFound == true);
    CHECK(baFound == true);
}

TEST_CASE("Adding edge with missing vertex does not crash") {
    Graph g;
    g.addVertex("A");
    g.addEdge("A", "Z", 3); //Z doesn't exist
    CHECK(g.hasVertex("Z") == false);
}

//Breadth-First Search Tests
TEST_CASE("BFS finds a path between two connected vertices") {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addEdge("A", "B", 1);
    g.addEdge("B", "C", 1);

    BFS bfs;
    vector<string> path = bfs.findPath(g, "A", "C");

    CHECK(path.empty() == false);
    CHECK(path.front() == "A");
    CHECK(path.back() == "C");
}

TEST_CASE("BFS returns empty path for disconnected vertices") {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    //No edge between A and B

    BFS bfs;
    vector<string> path = bfs.findPath(g, "A", "B");
    CHECK(path.empty() == true);
}

TEST_CASE("BFS returns empty path for invalid vertex") {
    Graph g;
    g.addVertex("A");

    BFS bfs;
    vector<string> path = bfs.findPath(g, "A", "Z");
    CHECK(path.empty() == true);
}

TEST_CASE("BFS finds shortest path by hops") {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addEdge("A", "B", 10);
    g.addEdge("A", "C", 1);
    g.addEdge("C", "D", 1);
    g.addEdge("B", "D", 1);

    BFS bfs;
    vector<string> path = bfs.findPath(g, "A", "D");

    //Both paths are 2 hops
    //Just verify path is valid
    CHECK(path.front() == "A");
    CHECK(path.back() == "D");
    CHECK(path.size() == 3);
}

//Dijkstra's Algorithm Tests
TEST_CASE("Dijkstra's finds a path between two connected vertices") {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addEdge("A", "B", 4);
    g.addEdge("B", "C", 2);

    Dijkstra dijkstra;
    vector<string> path = dijkstra.findPath(g, "A", "C");

    CHECK(path.empty() == false);
    CHECK(path.front() == "A");
    CHECK(path.back() == "C");
}

TEST_CASE("Dijkstra's returns empty path for disconnected vertices") {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    //No edge between A and B

    Dijkstra dijkstra;
    vector<string> path = dijkstra.findPath(g, "A", "B");
    CHECK(path.empty() == true);
}

TEST_CASE("Dijkstra's returns empty path for invalid vertex") {
    Graph g;
    g.addVertex("A");

    Dijkstra dijkstra;
    vector<string> path = dijkstra.findPath(g, "A", "Z");
    CHECK(path.empty() == true);
}

TEST_CASE("Dijkstra's finds lowest weight path") {
    Graph g;
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addEdge("A", "B", 4);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 5);
    g.addEdge("C", "D", 1);

    Dijkstra dijkstra;
    vector<string> path = dijkstra.findPath(g, "A", "D");

    //Cheapest path should be A to C to D (cost of 3) not A to B to D (cost of 9)
    CHECK(path.size() == 3);
    CHECK(path[0] == "A");
    CHECK(path[1] == "C");
    CHECK(path[2] == "D");
}

//FileLoader Tests
TEST_CASE("FileLoader loads graph from valid file") {
    Graph g;
    FileLoader loader;
    bool result = loader.loadGraph(g, "graph.txt");

    CHECK(result == true);
    CHECK(g.hasVertex("A") == true);
    CHECK(g.hasVertex("E") == true);
}

TEST_CASE("FileLoader returns false for missing file") {
    Graph g;
    FileLoader loader;
    bool result = loader.loadGraph(g, "nonexistent.txt");
    CHECK(result == false);
}