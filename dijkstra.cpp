#include "dijkstra.h"
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

vector<string> Dijkstra::findPath(const Graph& graph, const string& start, const string& end) {

    //Check that both vertices exist in the graph
    if (!graph.hasVertex(start) || !graph.hasVertex(end)) {
        cout << "Error: One or both vertices not found in graph." << endl;
        return {};
    }

    //Stores the shortest known distance to each vertex
    unordered_map<string, int> distance;

    //Tracks how each vertex was reached for path reconstruction
    unordered_map<string, string> cameFrom;

    //Tracks which vertices have been fully processed
    unordered_map<string, bool> visited;

    //Priority queue
    //Min heap so the lowest cost vertex is always processed first
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    //Initialize all distances to infinity
    const auto& adjList = graph.getAdjacencyList();
    for (const auto& pair : adjList) {
        distance[pair.first] = INT_MAX;
    }

    //Start vertex has a distance of 0
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {

        //Get the vertex with the lowest current cost
        string current = pq.top().second;
        int currentCost = pq.top().first;
        pq.pop();

        //Skip if this vertex has already been processed
        if (visited[current]) {
            continue;
        }
        visited[current] = true;

        //Stop early if destination has been reached
        if (current == end) {
            break;
        }

        //Check all neighbors of the current vertex
        for (const Edge& edge : adjList.at(current)) {
            int newCost = currentCost + edge.weight;

            //If a cheaper path to the neighbor is found, update the distance and path
            if (newCost < distance[edge.neighbor]) {
                distance[edge.neighbor] = newCost;
                cameFrom[edge.neighbor] = current;
                pq.push({newCost, edge.neighbor});
            }
        }
    }

    //If the end vertex was never reached, no path exists
    if (distance[end] == INT_MAX) {
        return {};
    }

    //Reconstruct the path by working backwards from end to start
    vector<string> path;
    string step = end;
    while (step != start) {
        path.push_back(step);
        step = cameFrom[step];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    return path;
}

void Dijkstra::printPath(const vector<string>& path, const string& start, const string& end, int totalCost) {
    if (path.empty()) {
        cout << "No path found between " << start << " and " << end << "." << endl;
        return;
    }

    cout << "\nDijkstra Shortest Path (lowest weight): ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
    cout << "Total cost: " << totalCost << endl;
}