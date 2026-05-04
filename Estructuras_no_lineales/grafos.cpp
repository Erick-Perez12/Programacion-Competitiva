#include "grafos.h"
#include <algorithm>
#include <iostream>
#include <queue>

Graph::Graph(int vertices) : V(vertices), adj(vertices) {}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::removeEdge(int u, int v) {
    adj[u].erase(std::remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
    adj[v].erase(std::remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
}

void Graph::dfsRecursive(int vertex, std::vector<bool>& visited) const {
    visited[vertex] = true;
    std::cout << vertex << " ";
    for (int neighbor : adj[vertex]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, visited);
        }
    }
}

void Graph::DFS(int start) const {
    std::vector<bool> visited(V, false);
    dfsRecursive(start, visited);
    std::cout << std::endl;
}

void Graph::BFS(int start) const {
    std::vector<bool> visited(V, false);
    std::queue<int> queue;
    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        std::cout << vertex << " ";
        for (int neighbor : adj[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }

    std::cout << std::endl;
}
