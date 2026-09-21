#include "tablero.h"
#include "memoriatablero.h"
#include <iostream>

int pedirFilas(){

    int filas;

    std::cout << "Ingrese la cantidad de filas: ";
    std::cin >> filas;

    if(filas <= 0){
        return -1;
    }

    std::cout << std::endl;

    return filas;
}

int pedirColumnas(){

    int columnas;

    std::cout << "Ingrese la cantidad de columnas: ";
    std::cin >> columnas;

    if(columnas <= 0){
        return -1;
    }

    std::cout << std::endl;

    return columnas;
}

int filaSeleccion(int filas){
    std::cout << "Ingrese la fila: ";
    int fila;
    std::cin >> fila;
    fila--;

    if(fila < 0 || fila >= filas){
        return -1;
    }

    return fila;
}

int columnaSeleccion(int columnas){
    int columna;
    std::cout << "Ingrese la columna: ";
    std::cin >> columna;
    columna--;

    if(columna < 0 || columna >= columnas){
        return -1;
    }

    return columna;
}

int pedirPosicion(int filas, int columnas){
    int fila = filaSeleccion(filas);
    int columna = columnaSeleccion(columnas);
    while(true){
        if(fila == -1){
            std::cout << "Debe ingresar un numero mayor a 0" << std::endl;
            int fila = filaSeleccion(filas);
        }else if(columna == -1){
            std::cout << "Debe ingresar un numero mayor a 0" << std::endl;
            int columna = columnaSeleccion(columnas);
        }else break;
    }
    return calcularPosicion(fila, columna, columnas);
}


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

void mostrarTablero(unsigned char* tablero, int filas, int columnas){
    for(int fila = 0; fila < filas; fila++){
        for(int columna = 0; columna < columnas; columna++){
            int posicion = calcularPosicion(fila,columna,columnas);
            unsigned char obtFicha = obtenerFicha(tablero, posicion);
            unsigned char letra = asignarLetra(obtFicha);
            std::cout << int(obtFicha) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
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

    return cantidadEliminadas;
}

void eliminarFichas(unsigned char* tablero, int* eliminadas,int cantidadEliminadas){
    for(int i = 0; i < cantidadEliminadas; i++){

        guardarFicha(tablero, eliminadas[i], 6);
    }
}

void hacerCaerTablero(unsigned char* tablero, int filas, int columnas){

    if(tablero == 0) return;
    if(filas <= 0 || columnas <= 0) return;

    for(int columna = 0; columna < columnas; columna++){

        hacerCaerColumna(tablero, columna, filas, columnas);
    }
}

void rellenarTablero(unsigned char* tablero, int filas, int columnas){
    if(tablero == 0) return;
    if(filas <= 0 || columnas <= 0) return;

    for(int fila = 0; fila < filas; fila++){

        for(int columna = 0; columna < columnas; columna++){

            int posicion = calcularPosicion(fila, columna, columnas);
            unsigned char ficha = obtenerFicha(tablero, posicion);

            if(ficha == 6){

                unsigned char nuevaFicha = generarFicha();

                guardarFicha(tablero, posicion, nuevaFicha);
            }
        }
    }
}

int pedirAccion(){
    int opcion;
    std::cout << "1. Eliminar ficha" << std::endl;
    std::cout << "2. Agregar fila" << std::endl;
    std::cout << "3. Eliminar fila" << std::endl;
    std::cout << "4. Agregar columna" << std::endl;
    std::cout << "5. Eliminar columna" << std::endl;
    std::cout << "6. Salir" << std::endl;

    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    if(opcion <= 0){
        return -1;
    }

    return opcion;
}




