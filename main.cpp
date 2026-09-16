#include "memoriatablero.h"
#include "tablero.h"
#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    int filas = 1, columnas = 5;
    int fila = 1, columna = 2;
    int bytesTablero = calcularBytesTablero(filas, columnas);
    unsigned char* tablero = crearTablero(bytesTablero);
    inicializarBuffer(tablero, bytesTablero);
    llenarTablero(tablero, filas,columnas);

    int bytes = calcularBytesTablero(filas, columnas);

    unsigned char* tableroP = crearTablero(bytesTablero);
    inicializarBuffer(tablero, bytesTablero);

    guardarFicha(tableroP, 0, 1); // A
    guardarFicha(tableroP, 1, 0); // A
    guardarFicha(tableroP, 2, 0); // A
    guardarFicha(tableroP, 3, 0); // B
    guardarFicha(tableroP, 4, 0);

    for(int i = 0; i < columnas; i++){
        cout << (int)obtenerFicha(tableroP, i) << " ";
    }

    cout << endl;

    cout << combHorizontales(tableroP, 0, 1, columnas) << endl;


    // while(true){
    //     for(int fila = 0; fila < filas; fila++){
    //         for(int columna = 0; columna < columnas; columna++){
    //             int posicion = calcularPosicion(fila,columna,columnas);
    //             unsigned char obtFicha = obtenerFicha(tablero, posicion);
    //             unsigned char letra = asignarLetra(obtFicha);
    //             std::cout << letra << " ";
    //         }
    //         std::cout << std::endl;
    //     }
    //     break;
    // }

    // std::cout << "Bytes del tablero: " << bytesTablero << std::endl;

    // std::cout << std::endl;

    // imprimirBits(tablero,bytesTablero);

    // std::cout << std::endl;

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



