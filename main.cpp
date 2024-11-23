#include <iostream>
#include <string>
#include <cctype> 

using namespace std;


bool validarTarjetaLuhn(const string& tarjeta) {
    int suma = 0;
    bool duplicar = false;

    
    for (int i = tarjeta.length() - 1; i >= 0; i--) {
        
        if (!isdigit(tarjeta[i])) return false; 
        int digito = tarjeta[i] - '0';

        if (duplicar) {
            digito *= 2;
            if (digito > 9) digito -= 9; 
        }

        suma += digito;
        duplicar = !duplicar; 
    }

    
    return (suma % 10 == 0);
}

int main() {
    string tarjeta;

    cout << "Ingrese el número de tarjeta de crédito: ";
    cin >> tarjeta;

    
    if (tarjeta.length() < 13 || tarjeta.length() > 19) {
        cout << "Número de tarjeta inválido (longitud incorrecta)." << endl;
        return 1;
    }

    if (validarTarjetaLuhn(tarjeta)) {
        cout << "El número de tarjeta es válido." << endl;
    } else {
        cout << "El número de tarjeta es inválido." << endl;
    }

    return 0;
}
