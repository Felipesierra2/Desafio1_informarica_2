#include "memoriatablero.h"
#include "tablero.h"
#include <iostream>

using namespace std;


int main(){
    srand(time(0));
    int filas = 7, columnas = 5;
    int bytesTablero = calcularBytesTablero(filas, columnas);
    unsigned char* tablero = crearTablero(bytesTablero);
    inicializarBuffer(tablero, bytesTablero);
    llenarTablero(tablero, filas,columnas);

    for(int fila = 0; fila < filas; fila++){
        std::cout << "fila " << fila << ": ";
        for(int columna = 0; columna < columnas; columna++){
            int posicion = calcularPosicion(fila,columna,columnas);
            unsigned char ficha = tablero[posicion];
            unsigned char obtFicha = obtenerFicha(tablero, posicion);
            unsigned char letra = asignarLetra(obtFicha);
            std::cout << letra << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Bytes del tablero: " << bytesTablero << std::endl;

    std::cout << std::endl;

    imprimirBits(tablero,bytesTablero);

    std::cout << std::endl;

    for(int i = 0; i <= bytesTablero; i++){
        unsigned char ficha = obtenerFicha(tablero, i);
        cout << "Ficha: " << i << " = " << (int)ficha << " (";
        for(int j = 2; j >= 0; j--){
            cout << ((ficha >> j) & 1);
        }

        cout << ")" << endl;
    }

    return 0;
}



