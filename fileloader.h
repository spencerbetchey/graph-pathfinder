#ifndef FILELOADER_H
#define FILELOADER_H

#include <string>
#include "graph.h"

using namespace std;

class FileLoader {
public:
    //Loads a graph from a text file
    //Returns true if successful, false if the file could not be opened
    bool loadGraph(Graph& graph, const string& filename);
};

#endif