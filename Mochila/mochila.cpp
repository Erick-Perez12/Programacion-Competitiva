#include "mochila.h"

using namespace std;

int Mochila::recursivo(vector<int>& pesos, vector<int>& valores, int n, int capacidad) {
    if (n == 0 || capacidad == 0)
        return 0;

    if (pesos[n - 1] > capacidad) {
        return recursivo(pesos, valores, n - 1, capacidad);
    }

    int incluir = valores[n - 1] + recursivo(pesos, valores, n - 1, capacidad - pesos[n - 1]);
    int excluir = recursivo(pesos, valores, n - 1, capacidad);

    return max(incluir, excluir);
}

int Mochila::topDownAux(vector<int>& pesos, vector<int>& valores, int n, int capacidad, vector<vector<int>>& memo) {
    if (n == 0 || capacidad == 0)
        return 0;

    if (memo[n][capacidad] != -1)
        return memo[n][capacidad];

    if (pesos[n - 1] > capacidad) {

        memo[n][capacidad] = topDownAux(pesos, valores, n - 1, capacidad, memo);
    }
    else {

        int incluir = valores[n - 1] + topDownAux(pesos, valores, n - 1, capacidad - pesos[n - 1],  memo);
        int excluir = topDownAux(pesos, valores, n - 1, capacidad, memo);
        memo[n][capacidad] = max(incluir, excluir);
    }

    return memo[n][capacidad];
}

int Mochila::topDown(vector<int>& pesos, vector<int>& valores, int n, int capacidad) {
    vector<vector<int>> memo( n + 1, vector<int>(capacidad + 1, -1));
    return topDownAux(pesos, valores, n, capacidad, memo);
}

int Mochila::bottomUp(vector<int>& pesos, vector<int>& valores, int n, int capacidad) {

    vector<vector<int>> dp( n + 1, vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacidad; w++) {
            if (pesos[i - 1] <= w) {
                dp[i][w] = max(
                    valores[i - 1] +
                    dp[i - 1][w - pesos[i - 1]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacidad];
}