#include "bfs.h"
#include <queue>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> BFS::findPath(const Graph& graph, const string& start, const string& end) {

    //Check that both vertices exist in the graph
    if (!graph.hasVertex(start) || !graph.hasVertex(end)) {
        cout << "Error: One or both vertices not found in graph." << endl;
        return {};
    }

    //Queue holds the current vertex that is being visited
    queue<string> toVisit;

    //Tracks which vertices have already been visited to avoid cycles
    unordered_map<string, bool> visited;

    //Tracks how we got to each vertex so we can reconstruct the path
    unordered_map<string, string> cameFrom;

    //Start BFS from the start vertex
    toVisit.push(start);
    visited[start] = true;

    while (!toVisit.empty()) {

        //Take the next vertex off the front of the queue
        string current = toVisit.front();
        toVisit.pop();

        //If destination is reached, reconstruct the path and return it
        if (current == end) {
            vector<string> path;
            string step = end;

            //Walk backwards from end to start using cameFrom
            while (step != start) {
                path.push_back(step);
                step = cameFrom[step];
            }
            path.push_back(start);

            //Reverse so path goes from start to end
            reverse(path.begin(), path.end());
            return path;
        }

        //Visit all unvisited neighbors and add them to the queue
        const auto& adjList = graph.getAdjacencyList();
        for (const Edge& edge : adjList.at(current)) {
            if (!visited[edge.neighbor]) {
                visited[edge.neighbor] = true;
                cameFrom[edge.neighbor] = current;
                toVisit.push(edge.neighbor);
            }
        }
    }

    //If queue is exhausted without finding the end vertex, return an empty path (no path exists)
    return {};
}

void BFS::printPath(const vector<string>& path, const string& start, const string& end) {
    if (path.empty()) {
        cout << "No path found between " << start << " and " << end << "." << endl;
        return;
    }

    cout << "\nBFS Shortest Path (fewest hops): ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
    cout << "Total hops: " << path.size() - 1 << endl;
}