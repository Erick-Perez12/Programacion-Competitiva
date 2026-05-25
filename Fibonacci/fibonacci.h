#ifndef FIBONACCI_H
#define FIBONACCI_H
#include <vector>

class Fibonacci {
public:
    long long recursivo(int n);
    long long topDown(int n);
    long long bottomUp(int n);

private:
    long long topDownAux(int n, std::vector<long long>& memo);
};

#endif