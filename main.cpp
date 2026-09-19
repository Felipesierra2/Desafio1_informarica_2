#include "memoriatablero.h"
#include "tablero.h"
#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    int filas = 7, columnas = 6;
    int* eliminadas = new int[filas*columnas];
    int bytesTablero = calcularBytesTablero(filas, columnas);
    unsigned char* tablero = crearTablero(bytesTablero);
    inicializarBuffer(tablero, bytesTablero);
    llenarTablero(tablero, filas,columnas);

    int bytes = calcularBytesTablero(filas, columnas);

    int combinaciones = buscarCombinaciones(tablero,eliminadas,filas,columnas);

    cout << "Combinaciones: " << combinaciones << endl;

    while(true){
        for(int fila = 0; fila < filas; fila++){
            for(int columna = 0; columna < columnas; columna++){
                int posicion = calcularPosicion(fila,columna,columnas);
                unsigned char obtFicha = obtenerFicha(tablero, posicion);
                unsigned char letra = asignarLetra(obtFicha);
                std::cout << int(obtFicha) << " ";
            }
            std::cout << std::endl;

        }
        break;

    }

    std::cout << "Bytes del tablero: " << bytesTablero << std::endl;

    std::cout << std::endl;

    imprimirBits(tablero,bytesTablero);

    std::cout << std::endl;

    // for(int i = 0; i <= bytesTablero; i++){
    //     unsigned char ficha = obtenerFicha(tablero, i);
    //     cout << "Ficha: " << i << " = " << (int)ficha << " (";
    //     for(int j = 2; j >= 0; j--){
    //         cout << ((ficha >> j) & 1);
    //     }

    //     cout << ")" << endl;
    // }
    delete[] tablero;
    tablero = nullptr;
    delete[]eliminadas;
    eliminadas = nullptr;

    return 0;
}



