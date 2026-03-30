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

void Graph::printMatrix() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int vectors = 3;
    Graph g(vectors);

    g.addEdge(0, 1, 4);
    g.addEdge(1, 2, 5);
    g.addEdge(0, 2, 6);

    g.printMatrix();

    return 0;
}