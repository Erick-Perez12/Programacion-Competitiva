#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> construirLPS(string patron) {
    int m = patron.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (patron[i] == patron[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMP(string texto, string patron) {
    vector<int> lps = construirLPS(patron);
    int i = 0;
    int j = 0;
    bool encontrado = false;
    while (i < texto.length()) {
        if (texto[i] == patron[j]) {
            i++;
            j++;
        }
        if (j == patron.length()) {
            cout << "Patron encontrado en la posicion: " << i - j << endl;

            encontrado = true;
            j = lps[j - 1];
        }

        else if (i < texto.length() &&
                 texto[i] != patron[j]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i++;
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
    KMP(texto, patron);
    return 0;
}