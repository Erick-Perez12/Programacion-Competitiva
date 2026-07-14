#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string resultado = "";
    int i = m;
    int j = n;
    while(i > 0 && j > 0){
        if(s1[i - 1] == s2[j - 1]){
            resultado += s1[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

int main(){
    string s1, s2;
    cout << "Primera cadena: ";
    cin >> s1;
    cout << "Segunda cadena: ";
    cin >> s2;
    cout << "El LCS es: "<< LCS(s1, s2);
    return 0;
}