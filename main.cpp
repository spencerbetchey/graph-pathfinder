#include "graph.h"
#include "bfs.h"
#include "dijkstra.h"
#include "fileloader.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {

    Graph g;
    FileLoader loader;

    cout << "==============================" << endl;
    cout << "   Graph Path Finder" << endl;
    cout << "==============================\n" << endl;

    //Ask user for a graph file to load
    string filename;
    cout << "Enter graph file to load (ex: graph.txt): ";
    cin >> filename;

    if (!loader.loadGraph(g, filename)) {
        return 1; //Exit if file loading failed
    }

    //Main menu loop
    int choice = 0;
    while (choice != 4) {

        cout << "\n--- Menu ---" << endl;
        cout << "1. Print graph" << endl;
        cout << "2. Find shortest path by hops (Breadth-First Search)" << endl;
        cout << "3. Find shortest path by weight (Dijkstra's Algorithm)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        //Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            g.printGraph();

        } else if (choice == 2) {
            string start, end;
            cout << "Enter start vertex: ";
            cin >> start;
            cout << "Enter end vertex: ";
            cin >> end;

            BFS bfs;
            vector<string> path = bfs.findPath(g, start, end);
            bfs.printPath(path, start, end);

        } else if (choice == 3) {
            string start, end;
            cout << "Enter start vertex: ";
            cin >> start;
            cout << "Enter end vertex: ";
            cin >> end;

            Dijkstra dijkstra;
            vector<string> path = dijkstra.findPath(g, start, end);

            //Calculate total cost
            int totalCost = 0;
            const auto& adjList = g.getAdjacencyList();
            for (int i = 0; i < path.size() - 1; i++) {
                string current = path[i];
                string next = path[i + 1];
                for (const Edge& edge : adjList.at(current)) {
                    if (edge.neighbor == next) {
                        totalCost += edge.weight;
                        break;
                    }
                }
            }

            dijkstra.printPath(path, start, end, totalCost);

        } else if (choice == 4) {
            cout << "\nGoodbye!" << endl;

        } else {
            cout << "Invalid choice. Please enter 1, 2, 3, or 4." << endl;
        }
    }

    return 0;
}