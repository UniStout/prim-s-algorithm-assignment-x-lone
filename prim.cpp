//All procedures including main
#include "prim.h"
#include <iostream>

using namespace std;

Graph::Graph(int V) {
    this->V = V;
    adjMatrix = std::vector<std::vector<int>>(V, std::vector<int>(V, 0));
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = adjMatrix[v][u] = weight;
}

int main() {

    return 0;
}