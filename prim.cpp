//All procedures including main
#include "prim.h"
#include <iostream>
#include <fstream>

using namespace std;

Graph::Graph(int V) {
    this->V = V;
    adjMatrix = std::vector<std::vector<int>>(V, std::vector<int>(V, 0));
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = adjMatrix[v][u] = weight;
}

void Graph::printMatrix() {
    for (int row = 0; row < V; row++) {
        for (int col = 0; col < V; col++) {
            std::cout << adjMatrix[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::primMST() {
    std::vector<bool> visited(V, false);
    std::vector<int> key(V, INT_MAX);
    std::vector<int> parent(V, -1);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {

        int min = INT_MAX;
        int u = -1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] && !visited[v] && adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }

    for (int v = 1; v < V; v++) {
        std::cout << parent[v] << " - " << v
                  << " weight " << adjMatrix[v][parent[v]] << "\n";
    }
}

int main() {
    std::ifstream file("input.txt");

    if (!file) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    int V, E;
    file >> V >> E;

    Graph g(V);

    int u, v, w;

    for (int i = 0; i < E; i++) {
        file >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.primMST();

    return 0;
}