#include <iostream>
#include <vector>
#include <chrono>
#include "mochila.h"

using namespace std;
using namespace chrono;

int main() {
    Mochila mochila;

    vector<int> pesos = {
        2, 3, 4, 5, 9,
        7, 6, 8, 10, 11,
        13, 1, 12, 14, 15
    };

    vector<int> valores = {
        3, 4, 8, 8, 10,
        13, 7, 9, 15, 20,
        18, 2, 16, 22, 25
    };

    int capacidad = 35;

    int n = pesos.size();
    cout << "---------- PROBLEMA DE LA MOCHILA ----------" << endl;
    cout << "\nPesos: ";
    for (int p : pesos)
        cout << p << " ";

    cout << "\nValores: ";
    for (int v : valores)
        cout << v << " ";

    cout << "\nCapacidad maxima: "
         << capacidad << endl;

    auto inicio1 = high_resolution_clock::now();
    int resultado1 = mochila.recursivo(pesos, valores, n, capacidad);
    auto fin1 = high_resolution_clock::now();
    auto tiempo1 = duration_cast<microseconds>(fin1 - inicio1);

    cout << "\n--------- METODO RECURSIVO ---------" << endl;
    cout << "Valor maximo obtenido: " << resultado1 << endl;
    cout << "Tiempo total: " << tiempo1.count() << " ms" << endl;

    auto inicio2 = high_resolution_clock::now();
    int resultado2 = mochila.topDown(pesos, valores, n, capacidad);
    auto fin2 = high_resolution_clock::now();
    auto tiempo2 = duration_cast<microseconds>(fin2 - inicio2);

    cout << "\n--------- METODO TOP-DOWN ---------" << endl;
    cout << "Valor maximo obtenido: " << resultado2 << endl;
    cout << "Tiempo total: " << tiempo2.count() << " ms" << endl;

    auto inicio3 = high_resolution_clock::now();
    int resultado3 = mochila.bottomUp(pesos, valores, n, capacidad);
    auto fin3 = high_resolution_clock::now();
    auto tiempo3 = duration_cast<microseconds>(fin3 - inicio3);

    cout << "\n--------- METODO BOTTOM-UP ---------" << endl;
    cout << "Valor maximo obtenido: " << resultado3 << endl;
    cout << "Tiempo total: " << tiempo3.count() << " ms" << endl;

    return 0;
}