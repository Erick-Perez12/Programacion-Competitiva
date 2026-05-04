#ifndef GRAFOS_H
#define GRAFOS_H

#include <vector>

class Graph {
public:
    explicit Graph(int vertices);
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    void DFS(int start) const;
    void BFS(int start) const;

private:
    int V;
    std::vector<std::vector<int>> adj;

    void dfsRecursive(int vertex, std::vector<bool>& visited) const;
};

#endif
