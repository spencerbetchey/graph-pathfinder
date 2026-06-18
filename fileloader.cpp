#include "fileloader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

bool FileLoader::loadGraph(Graph& graph, const string& filename) {

    //Try to open the file
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file \"" << filename << "\"." << endl;
        return false;
    }

    string line;
    string section = ""; //Tracks whether we are in the vertices or edges section

    while (getline(file, line)) {

        //Skip empty lines
        if (line.empty()) {
            continue;
        }

        //Check if we are entering a new section
        if (line == "vertices") {
            section = "vertices";
            continue;
        }

        if (line == "edges") {
            section = "edges";
            continue;
        }

        //Process vertices section
        if (section == "vertices") {
            //Each line in vertices section is a space separated list of vertex names
            istringstream stream(line);
            string vertex;
            while (stream >> vertex) {
                graph.addVertex(vertex);
            }
        }

        //Process edges section
        if (section == "edges") {
            //Each line in edges section is from to weight (ex: A B 4), A to B with weight 4
            istringstream stream(line);
            string from, to;
            int weight;
            if (stream >> from >> to >> weight) {
                graph.addEdge(from, to, weight);
            } else {
                cout << "Warning: Skipping invalid edge line: " << line << endl;
            }
        }
    }

    file.close();
    cout << "\nGraph loaded successfully from \"" << filename << "\"." << endl;
    return true;
}