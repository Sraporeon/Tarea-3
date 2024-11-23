#include <iostream>
#include <string>
#include <cctype> // Para funciones como isdigit

using namespace std;

// Función para validar usando el Algoritmo de Luhn
bool validarTarjetaLuhn(const string& tarjeta) {
    int suma = 0;
    bool duplicar = false;

    // Iterar desde el último dígito hacia el primero
    for (int i = tarjeta.length() - 1; i >= 0; i--) {
        // Convertir el carácter a número
        if (!isdigit(tarjeta[i])) return false; // Validar que todos los caracteres sean dígitos
        int digito = tarjeta[i] - '0';

        if (duplicar) {
            digito *= 2;
            if (digito > 9) digito -= 9; // Si el número es mayor a 9, resta 9
        }

        suma += digito;
        duplicar = !duplicar; // Cambiar entre duplicar y no duplicar
    }

    // La suma debe ser múltiplo de 10
    return (suma % 10 == 0);
}
