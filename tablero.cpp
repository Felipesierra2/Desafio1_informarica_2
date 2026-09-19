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
    if (columna >= columnas) return -1;

    int posicion = calcularPosicion(fila, columna, columnas);
    unsigned char fichaBase = obtenerFicha(tablero, posicion);

    int contador = 1;
    int c = columna + 1;

    while (c < columnas) {
        posicion = calcularPosicion(fila, c, columnas);
        unsigned char ficha = obtenerFicha(tablero, posicion);

        if (ficha != fichaBase) {
            break;
        }

        contador++;
        c++;
    }

    return contador;
}

int combVerticales(unsigned char* tablero, int fila, int columna, int filas, int columnas){
    if (tablero == 0) return -1;
    if (fila < 0 || columna < 0 || filas <= 0 || columnas <= 0) return -1;
    if (fila >= filas || columna >= columnas) return -1;

    int posicion = calcularPosicion(fila, columna, columnas);
    unsigned char fichaBase = obtenerFicha(tablero, posicion);

    int contador = 1;
    int f = fila + 1;

    while (f < filas) {
        posicion = calcularPosicion(f, columna, columnas);
        unsigned char ficha = obtenerFicha(tablero, posicion);

        if (ficha != fichaBase) {
            break;
        }

        contador++;
        f++;
    }

    return contador;
}

bool estaEliminada(int* eliminadas, int cantidadEliminadas, int posicion){
    for(int i = 0; i < cantidadEliminadas; i++){
        if(eliminadas[i] == posicion){
            return true;
        }
    }

    return false;
}

int buscarCombinaciones(unsigned char* tablero, int* eliminadas,int filas, int columnas){
    if(tablero == 0 || eliminadas == 0) return -1;
    if(filas <= 0 || columnas <= 0) return -1;

    int cantidadEliminadas = 0;

    for(int fila = 0; fila < filas; fila++){

        for(int columna = 0; columna < columnas; columna++){

            // Buscamos combinaciones horizontales
            int cantidadHorizontal = combHorizontales(tablero, fila, columna, columnas);

            if(cantidadHorizontal >= 3){

                for(int i = 0; i < cantidadHorizontal; i++){

                    int posicion = calcularPosicion(fila, columna + i, columnas);

                    if(!estaEliminada(eliminadas,cantidadEliminadas,posicion)){
                        eliminadas[cantidadEliminadas] = posicion;
                        cantidadEliminadas++;
                    }
                }
            }

            // Buscamos combinaciones verticales
            int cantidadVertical = combVerticales(tablero, fila, columna, filas, columnas);

            if(cantidadVertical >= 3){

                for(int i = 0; i < cantidadVertical; i++){

                    int posicion = calcularPosicion(fila + i, columna, columnas);

                    if(!estaEliminada(eliminadas,cantidadEliminadas,posicion)){
                        eliminadas[cantidadEliminadas] = posicion;
                        cantidadEliminadas++;
                    }
                }
            }
        }
    }

    for(int i = 0; i < cantidadEliminadas; i++){

        int posicion = eliminadas[i];

        std::cout << "Posicion " << posicion
             << " -> ficha "
             << (int)obtenerFicha(tablero, posicion)
             << std::endl;
    }

    return cantidadEliminadas;
}
