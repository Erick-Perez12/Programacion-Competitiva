#include <iostream>
#include <string>

using namespace std;

int distanciaHamming(string cadena1, string cadena2){
    if(cadena1.length() != cadena2.length())
        return -1;

    int distancia = 0;
    for(int i = 0; i < cadena1.length(); i++){
        if(cadena1[i] != cadena2[i])
            distancia++;
    }

    return distancia;
}

int main(){
    string cadena1, cadena2;
    cout << "Primera cadena: ";
    cin >> cadena1;
    cout << "Segunda cadena: ";
    cin >> cadena2;
    int resultado = distanciaHamming(cadena1, cadena2);
    if(resultado == -1)
        cout << "Longitud Distinta" << endl;
    else
        cout << "La distancia es: " << resultado << endl;

    return 0;
}