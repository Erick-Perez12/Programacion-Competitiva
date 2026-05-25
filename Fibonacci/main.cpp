#include <iostream>
#include <chrono>
#include "fibonacci.h"

using namespace std;
using namespace chrono;

int main() {
    Fibonacci fib;
    int n;
    cout << "Fibonacci n= ";
    cin >> n;

    auto inicio1 = high_resolution_clock::now();
    long long resultado1 = fib.recursivo(n);
    auto fin1 = high_resolution_clock::now();
    auto tiempo1 = duration_cast<microseconds>(fin1 - inicio1);

    cout << "\n--------- METODO RECURSIVO ---------\n";
    cout << "Fibonacci(" << n << ") = " << resultado1 << endl;
    cout << "Tiempo total: "  << tiempo1.count() << " ms\n";

    auto inicio2 = high_resolution_clock::now();
    long long resultado2 = fib.topDown(n);
    auto fin2 = high_resolution_clock::now();
    auto tiempo2 = duration_cast<microseconds>(fin2 - inicio2);

    cout << "\n--------- METODO TOP-DOWN ---------\n";
    cout << "Fibonacci(" << n << ") = " << resultado2 << endl;
    cout << "Tiempo total: " << tiempo2.count()  << " ms\n";

    auto inicio3 = high_resolution_clock::now();
    long long resultado3 = fib.bottomUp(n);
    auto fin3 = high_resolution_clock::now();
    auto tiempo3 = duration_cast<microseconds>(fin3 - inicio3);

    cout << "\n--------- METODO BOTTOM-UP ---------\n";
    cout << "Fibonacci(" << n << ") = " << resultado3 << endl;
    cout << "Tiempo total: " << tiempo3.count() << " ms\n";

    return 0;
}