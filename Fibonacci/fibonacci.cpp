#include "fibonacci.h"
using namespace std;

long long Fibonacci::recursivo(int n) {
    if (n <= 1)
        return n;
    return recursivo(n - 1) + recursivo(n - 2);
}

long long Fibonacci::topDownAux(int n, vector<long long>& memo) {
    if (n <= 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = topDownAux(n - 1, memo) + topDownAux(n - 2, memo);
    return memo[n];
}

long long Fibonacci::topDown(int n) {
    vector<long long> memo(n + 1, -1);
    return topDownAux(n, memo);
}

long long Fibonacci::bottomUp(int n) {
    if (n <= 1)
        return n;

    vector<long long> f(n + 1);
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}