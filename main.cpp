#include "memoriatablero.h"
#include "tablero.h"
#include <iostream>

using namespace std;

unsigned char fichas[20] = {
    1, 2, 3, 4, 5,
    5, 4, 3, 2, 1,
    0, 1, 0, 4, 5,
    2, 3, 4, 5, 2
};


int main(){
    int filas = 5, columnas = 4;
    int bytesTablero = calcularBytesTablero(filas, columnas);
    unsigned char* tablero = crearTablero(filas, columnas, bytesTablero);
    inicializarBuffer(tablero, bytesTablero);

    for(int fila = 0; fila < filas; fila++){
        cout << "fila " << fila << ": ";
        for(int columna = 0; columna < columnas; columna++){
            int posicion = calcularPosicion(fila,columna,columnas);
            unsigned char ficha = fichas[posicion];
            guardarFicha(tablero, posicion, ficha);
            unsigned char obtFicha = obtenerFicha(tablero, posicion);
            unsigned char letra = asignarLetra(obtFicha);
            cout << letra << " ";
        }
        cout << endl;
    }

    cout << "Bytes del tablero: " << bytesTablero << endl;

    cout << endl;

    imprimirBits(tablero,bytesTablero);

    cout << endl;

    // for(int i = 0; i <= bytesTablero; i++){
    //     unsigned char ficha = obtenerFicha(tablero, i);
    //     cout << "Ficha: " << i << " = " << (int)ficha << " (";
    //     for(int j = 2; j >= 0; j--){
    //         cout << ((ficha >> j) & 1);
    //     }

    //     cout << ")" << endl;
    // }

    return 0;
}



