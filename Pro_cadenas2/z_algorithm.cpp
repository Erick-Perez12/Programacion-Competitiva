#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> calcularZ(string s) {
    int n = s.length();
    vector<int> Z(n);
    int L = 0;
    int R = 0;
    for (int i = 1; i < n; i++) {
        if (i <= R)
            Z[i] = min(R - i + 1, Z[i - L]);
        while (i + Z[i] < n &&
               s[Z[i]] == s[i + Z[i]])
            Z[i]++;
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

void buscar(string texto, string patron) {
    string cadena = patron + "$" + texto;
    vector<int> Z = calcularZ(cadena);
    bool encontrado = false;
    for (int i = 0; i < Z.size(); i++) {
        if (Z[i] == patron.length()) {
            cout << "Patron encontrado en la posicion: "<< i - patron.length() - 1<< endl;
            encontrado = true;
        }
    }
    if (!encontrado)
        cout << "Patron no encontrado" << endl;
}

int main() {
    string texto, patron;
    cout << "Texto: ";
    getline(cin, texto);
    cout << "Patron: ";
    getline(cin, patron);
    buscar(texto, patron);
    return 0;
}