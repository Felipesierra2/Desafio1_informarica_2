#include "tablero.h"
#include "memoriatablero.h"
#include <iostream>



/*La función retorna un numero entre 0 y 5*/
unsigned char generarFicha(){
    return rand() % 6;
}

unsigned char asignarLetra(unsigned char ficha){
    if( ficha == 0) return 'A';
    else if(ficha == 1) return 'B';
    else if(ficha == 2) return 'C';
    else if(ficha == 3) return 'D';
    else if(ficha == 4) return 'E';
    else if(ficha == 5) return 'F';
}

/*La responsabilidad de esta función es llenar el tablero con las fichas aleatorias, esto lo realiza mediante
 la funcion generarFicha, la cual genera fichas aleatorias mientras itera sobre la posición donde sera almacenada en el tablero*/
void llenarTablero(unsigned char *tablero, int filas, int columnas){
    for(int fila = 0; fila < filas; fila++){
        for(int columna = 0; columna < columnas; columna++){
            unsigned char ficha = generarFicha();
            int posicion = calcularPosicion(fila,columna,columnas);
            guardarFicha(tablero,posicion,ficha);
        }
    }
}

int combHorizontales(unsigned char* tablero, int fila, int columna, int columnas){
    if (tablero == 0) return -1;
    if (fila < 0 || columna < 0 || columnas <= 0) return -1;
    if (columna + 2 >= columnas) return 0;

    int numFicha = calcularPosicion(fila,columna,columnas);
    unsigned char fichaBase = obtenerFicha(tablero, numFicha);

    if (columna > 0) {
        int posicion = calcularPosicion(fila,columna - 1,columnas);
        unsigned char izquierda = obtenerFicha(tablero,posicion);
        if (izquierda == fichaBase) {
            return 0;
        }
    }

    int contador = 1;
    int c = columna + 1;

    while (c < columnas) {
        int posicion = calcularPosicion(fila,c,columnas);
        unsigned char siguiente = obtenerFicha(tablero,posicion);
        if (siguiente == fichaBase) {
            contador++;
            c++;
        } else {
            break;
        }
    }

    if (contador >= 3) {
        return contador;
    }
    return 0;
}
