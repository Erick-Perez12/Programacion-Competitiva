#ifndef MOCHILA_H
#define MOCHILA_H

#include <vector>

class Mochila {
public:
    int recursivo(std::vector<int>& pesos, std::vector<int>& valores, int n, int capacidad);
    int topDown(std::vector<int>& pesos, std::vector<int>& valores, int n, int capacidad);
    int bottomUp(std::vector<int>& pesos, std::vector<int>& valores, int n, int capacidad);

private:
    int topDownAux(std::vector<int>& pesos, std::vector<int>& valores, int n, int capacidad, std::vector<std::vector<int>>& memo);
};

#endif