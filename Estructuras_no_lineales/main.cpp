#include <iostream>
#include "grafos.h"
#include "heap.h"
#include "tree.h"

int main() {
    std::cout << "=== ARBOL BST ===" << std::endl;
    Tree tree;
    int datosBST[] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 65};

    std::cout << "Insertando datos: ";
    for (int val : datosBST) {
        std::cout << val << " ";
        tree.insert(val);
    }
    std::cout << std::endl;
    std::cout << "Recorrido \n";
    std::cout << " - Inorder: ";
    tree.inorder();
    std::cout << " - Preorder: ";
    tree.preorder();
    std::cout << " - Postorder: ";
    tree.postorder();
    std::cout << "Buscar 40: " << (tree.search(40) ? "hallado" : "No hallado") << std::endl;
    std::cout << "Buscar 100: " << (tree.search(100) ? "hallado" : "No hallado") << std::endl;
    std::cout << "Eliminando 30" << std::endl;
    tree.remove(30);
    std::cout << "Recorrido despues de eliminar \n";
    std::cout << " - Inorder: ";
    tree.inorder();
    std::cout << " - Preorder: ";
    tree.preorder();
    std::cout << " - Postorder: ";
    tree.postorder();

    std::cout << "\n=== MAX HEAP ===" << std::endl;
    MaxHeap heap;
    int datosHeap[] = {15, 40, 10, 50, 30, 60, 20, 70, 5, 80};

    std::cout << "Insertando datos: ";
    for (int val : datosHeap) {
        std::cout << val << " ";
        heap.insert(val);
    }
    std::cout << std::endl;

    std::cout << "Heap actual: ";
    heap.print();
    std::cout << "Maximo: " << heap.getMax() << std::endl;
    std::cout << "Eliminando maximo" << std::endl;
    heap.extractMax();
    std::cout << "Heap despues: ";
    heap.print();

    std::cout << "\n=== GRAFO ===" << std::endl;

    Graph graph(10);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);
    graph.addEdge(3, 7);
    graph.addEdge(4, 8);
    graph.addEdge(5, 9);

    std::cout << "DFS desde 0: ";
    graph.DFS(0);
    std::cout << "BFS desde 0: ";
    graph.BFS(0);
    std::cout << "Eliminando arista (1,4)" << std::endl;
    graph.removeEdge(1, 4);

    std::cout << "DFS despues de eliminar: ";
    graph.DFS(0);
    std::cout << "BFS despues de eliminar: ";
    graph.BFS(0);

    return 0;
}