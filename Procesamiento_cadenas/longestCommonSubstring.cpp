#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonSubstring(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int longitud = 0;
    int posicion = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(dp[i][j] > longitud){
                    longitud = dp[i][j];
                    posicion = i;
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return s1.substr(posicion - longitud, longitud);
}

int main(){
    string s1, s2;
    cout << "Primera cadena: ";
    cin >> s1;
    cout << "Segunda cadena: ";
    cin >> s2;
    cout << "La subcadena comun mas larga es: "<< longestCommonSubstring(s1, s2);
    return 0;
}