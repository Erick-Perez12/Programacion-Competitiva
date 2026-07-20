#include <iostream>
#include <string>
using namespace std;

const int d = 256;
const int q = 101;

void RabinKarp(string texto, string patron) {
    int n = texto.length();
    int m = patron.length();
    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;
    int p = 0;
    int t = 0;
    for (int i = 0; i < m; i++) {
        p = (d * p + patron[i]) % q;
        t = (d * t + texto[i]) % q;
    }
    bool encontrado = false;
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool iguales = true;
            for (int j = 0; j < m; j++) {
                if (texto[i + j] != patron[j]) {
                    iguales = false;
                    break;
                }
            }
            if (iguales) {
                cout << "Patron encontrado en la posicion: "<< i << endl;
                encontrado = true;
            }
        }

        if (i < n - m) {
            t = (d * (t - texto[i] * h)
                 + texto[i + m]) % q;
            if (t < 0)
                t += q;
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
    RabinKarp(texto, patron);
    return 0;
}