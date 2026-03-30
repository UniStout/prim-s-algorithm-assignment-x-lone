//Please put header information in this file.
#ifndef PRIM_H

#define PRIM_H

#include <vector>

class Graph {
public:
    Graph(int V );
    void addEdge(int u, int v, int weight);
    int V;
    std::vector<std::vector<int>> adjMatrix;
};

#endif