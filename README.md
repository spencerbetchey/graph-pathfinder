# Graph Path Finder

A graph pathfinding application built in C++ that supports loading weighted graphs from text files and finding shortest paths using two graph algorithms: **Breadth First Search (BFS)** and **Dijkstra's Algorithm**.

## Features

* Load graphs from text files containing named vertices and weighted edges
* Display the graph structure using an adjacency list
* Find the shortest path by fewest hops using Breadth First Search (BFS)
* Find the shortest path by lowest total weight using Dijkstra's Algorithm
* Interactive command line interface with a menu
* Unit tests covering graph operations, pathfinding, and file loading

## How to Use

1. Clone the repository
2. Navigate to the project folder
3. Compile the project:

   ```
   g++ main.cpp graph.cpp bfs.cpp dijkstra.cpp fileloader.cpp -o pathfinder
   ```
4. Run the application:

   ```
   ./pathfinder
   ```

## Example Usage

```text
==============================
      Graph Path Finder
==============================

Enter graph file to load (e.g. graph.txt): graph.txt

Graph loaded successfully from "graph.txt".

--- Menu ---
1. Print graph
2. Find shortest path by hops (BFS)
3. Find shortest path by weight (Dijkstra)
4. Exit

Enter choice: 2

Enter start vertex: A
Enter end vertex: E

BFS Shortest Path (fewest hops):
A -> B -> D -> E

Total hops: 3

Enter choice: 3

Enter start vertex: A
Enter end vertex: E

Dijkstra Shortest Path (lowest weight):
A -> C -> D -> E

Total cost: 6
```

## Graph File Format

```text
vertices
A B C D E

edges
A B 4
A C 2
B D 5
C D 1
D E 3
```

Two sample graph files are included:

* `graph.txt` — simple weighted graph with 5 nodes
* `graph2.txt` — graph of U.S. cities connected by distances

## Project Structure
```
graph-pathfinder/
├── .vscode/
│   ├── .gitignore         # Git ignore rules
│   └── tasks.json         # VS Code build tasks
├── bfs.h                 # BFS class declaration
├── bfs.cpp               # BFS implementation and path reconstruction
├── dijkstra.h            # Dijkstra class declaration
├── dijkstra.cpp          # Dijkstra implementation using a priority queue
├── doctest.h             # Doctest testing framework (not my own)
├── fileloader.h          # FileLoader class declaration
├── fileloader.cpp        # Graph file parsing implementation
├── graph.h              # Graph class declaration
├── graph.cpp            # Graph implementation using adjacency lists
├── graph.txt            # Sample graph file with 5 nodes
├── graph2.txt           # Sample graph file with U.S. cities
├── main.cpp             # Entry point and interactive menu
├── tests.cpp            # Unit tests
└── README.md
```
## How to Run Tests

1. Compile the test suite:

   ```
   g++ tests.cpp graph.cpp bfs.cpp dijkstra.cpp fileloader.cpp -o tests
   ```
2. Run the tests:

   ```
   ./tests
   ```

All 14 tests should pass, covering graph operations, BFS pathfinding, Dijkstra pathfinding, and file loading.

## Concepts Demonstrated

* **Graph Theory** — representing weighted undirected graphs using adjacency lists
* **Breadth First Search (BFS)** — traversing graphs level by level to find the shortest path by number of hops
* **Dijkstra's Algorithm** — using a priority queue to find the minimum cost path in a weighted graph
* **Path Reconstruction** — rebuilding a complete route in reverse
* **File I/O** — parsing structured text files to construct graphs
* **Object-Oriented Design** — separating functionality into reusable classes and header/implementation files
* **Unit Testing** — writing structured tests with doctest covering functionality and error cases

*Built as a portfolio project*
