#include "memoriatablero.h"
#include "tablero.h"
#include <iostream>


//Operacion que usamos para saber cuantos bytes va a requerir el tablero
int calcularBytesTablero(int filas, int columnas) {
    return (filas * columnas * 3 + 7) / 8;
}

/*Funcion que se encarga de dimensionar el arreglo en base a los bytes
 calculados*/
unsigned char* crearTablero(int bytes){
    unsigned char* tablero = new unsigned char[bytes];

    return tablero;
}

/*Funcion que se encarga de llenar el buffer del tablero con ceros,
 de esta manera sera mas fácil manipular los bits*/
void inicializarBuffer(unsigned char* buffer, int& bytesTablero){
    int numBytes = (bytesTablero * 3 + 7) / 8;
    for (int i = 0; i < numBytes; i++){
        buffer[i] = 0;
    }
}

int calcularPosicion(int fila, int columna, int columnas){
    return fila*columnas + columna;
}

void guardarFicha(unsigned char* memoria, int posicion, unsigned char ficha){
    ficha = ficha & 0x07;

    int bitInicial = posicion * 3;
    int byteInicio = bitInicial / 8;
    int offSetBit = bitInicial % 8;

    int bitsEscritos = 0;
    int byteActual = byteInicio;
    int bitActual = offSetBit;

    unsigned char mascara = 0x80; //10000000

    while(bitsEscritos < 3){
        unsigned char bitValor = (ficha >> (2 - bitsEscritos)) & 1;

        if(bitValor){
            memoria[byteActual] |=  (mascara >> bitActual);
        }else{
            memoria[byteActual] &= ~(mascara >> bitActual);
        }

        bitsEscritos++;
        bitActual++;
        if(bitActual == 8){
            bitActual = 0;
            byteActual++;
        }
    }
}

unsigned char obtenerFicha(unsigned char* memoria, int numFicha){
    int bitInicial = numFicha * 3;
    int byteInicio = bitInicial / 8;
    int offSetBit = bitInicial % 8;

    unsigned char resultado = 0;

    int bitsEscritos = 0;
    int byteActual = byteInicio;
    int bitActual = offSetBit;

    while(bitsEscritos < 3){
        unsigned char bit = (memoria[byteActual] >> (7 - bitActual)) & 1;
        resultado = (resultado << 1) | bit;

        bitsEscritos++;
        bitActual++;
        if(bitActual == 8){
            bitActual = 0;
            byteActual++;
        }
    }
    return resultado;
}

void imprimirBits(const unsigned char* byte, int numBytes){
    for(int i = 0; i < numBytes; i++){
        for(int j = 7; j>= 0; j--){
            std::cout << ((byte[i] >> j) & 1);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

void hacerCaerColumna(unsigned char* tablero, int columna,int filas, int columnas){
    if(tablero == 0) return;
    if(columna < 0 || columna >= columnas) return;
    if(filas <= 0 || columnas <= 0) return;

    for(int fila = filas - 1; fila >= 0; fila--){

        int posicion = calcularPosicion(fila, columna, columnas);
        unsigned char ficha = obtenerFicha(tablero, posicion);

        if(ficha == 6){

            int filaSuperior = fila - 1;

            while(filaSuperior >= 0){

                int posicionSuperior = calcularPosicion(filaSuperior, columna, columnas);

                unsigned char fichaSuperior = obtenerFicha(tablero, posicionSuperior);

                if(fichaSuperior != 6){

                    guardarFicha(tablero, posicion, fichaSuperior);
                    guardarFicha(tablero, posicionSuperior, 6);

                    break;
                }

                filaSuperior--;
            }
        }
    }
}

void procesarEliminacionFicha(unsigned char* tablero, int filas, int columnas){
    int posicion = pedirPosicion(filas, columnas);

    if(posicion == -1){
        std::cout << "Posicion invalida." << std::endl;
        return;
    }

    guardarFicha(tablero, posicion, 6);

    hacerCaerTablero(tablero, filas, columnas);

    rellenarTablero(tablero, filas, columnas);
}

void agregarFila(unsigned char*& tablero,int& filas,int columnas,int fila){
    if(tablero == 0) return;
    if(filas <= 0 || columnas <= 0) return;
    if(fila < 1 || fila > filas + 1) return;

    int nuevasFilas = filas + 1;

    int bytesViejos = calcularBytesTablero(filas, columnas);
    int bytesNuevos = calcularBytesTablero(nuevasFilas, columnas);

    unsigned char* nuevoTablero = crearTablero(bytesNuevos);

    if(nuevoTablero == 0) return;

    inicializarBuffer(nuevoTablero, bytesNuevos);

    int nuevaPosicion = 0;

    for(int f = 0; f < nuevasFilas; f++){

        if(f == fila){
            for(int c = 0; c < columnas; c++){
                int posicion = calcularPosicion(f, c, columnas);

                guardarFicha(nuevoTablero,posicion,generarFicha());
            }
        }
        else{
            int filaVieja = f;

            if(f > fila){
                filaVieja--;
            }

            for(int c = 0; c < columnas; c++){

                int posicionVieja = calcularPosicion(filaVieja, c, columnas);

                unsigned char ficha = obtenerFicha(tablero, posicionVieja);

                int posicionNueva = calcularPosicion(f, c, columnas);

                guardarFicha(nuevoTablero,posicionNueva,ficha);
            }
        }
    }

    delete[] tablero;

    tablero = nuevoTablero;
    filas = nuevasFilas;

    std::cout << "Fila recibida: " << fila << std::endl;
    std::cout << "Nuevas filas: " << filas << std::endl;
}

void agregarColumna(unsigned char*& tablero,int filas,int& columnas,int columna){

    if(tablero == 0) return;
    if(filas <= 0 || columnas <= 0) return;
    if(columna < 0 || columna >= columnas) return;

    int nuevasColumnas = columnas + 1;

    int bytesNuevos = calcularBytesTablero(filas, nuevasColumnas);

    unsigned char* nuevoTablero = crearTablero(bytesNuevos);

    if(nuevoTablero == 0) return;

    inicializarBuffer(nuevoTablero, bytesNuevos);

    for(int f = 0; f < filas; f++){

        for(int c = 0; c < nuevasColumnas; c++){

            if(c == columna + 1){

                int posicionNueva =
                    calcularPosicion(f, c, nuevasColumnas);

                guardarFicha(nuevoTablero,posicionNueva,generarFicha());
            }
            else{

                int columnaVieja;

                if(c <= columna){
                    columnaVieja = c;
                }
                else{
                    columnaVieja = c - 1;
                }

                int posicionVieja = calcularPosicion(f, columnaVieja, columnas);

                unsigned char ficha = obtenerFicha(tablero, posicionVieja);

                int posicionNueva = calcularPosicion(f, c, nuevasColumnas);

                guardarFicha(nuevoTablero,posicionNueva,ficha);
            }
        }
    }

    delete[] tablero;

    tablero = nuevoTablero;
    columnas = nuevasColumnas;
}

void eliminarFila(unsigned char*& tablero,int& filas,int columnas,int fila){
    if(tablero == 0) return;
    if(filas <= 1 || columnas <= 0) return;
    if(fila < 1 || fila > filas) return;

    int nuevasFilas = filas - 1;

    int bytesNuevos = calcularBytesTablero(nuevasFilas, columnas);
    unsigned char* nuevoTablero = crearTablero(bytesNuevos);

    if(nuevoTablero == 0) return;

    inicializarBuffer(nuevoTablero, bytesNuevos);

    for(int f = 0; f < nuevasFilas; f++){

        int filaVieja;

        if(f < fila){
            filaVieja = f;
        }
        else{
            filaVieja = f + 1;
        }

        for(int c = 0; c < columnas; c++){

            int posicionVieja = calcularPosicion(filaVieja, c, columnas);

            unsigned char ficha = obtenerFicha(tablero, posicionVieja);

            int posicionNueva = calcularPosicion(f, c, columnas);

            guardarFicha(nuevoTablero,posicionNueva,ficha);
        }
    }

    delete[] tablero;

    tablero = nuevoTablero;
    filas = nuevasFilas;
}

void eliminarColumna(unsigned char*& tablero,int filas,int& columnas,int columna){
    if(tablero == 0) return;
    if(filas <= 0 || columnas <= 1) return;
    if(columna < 0 || columna >= columnas) return;

    int nuevasColumnas = columnas - 1;

    int bytesNuevos =
        calcularBytesTablero(filas, nuevasColumnas);

    unsigned char* nuevoTablero =
        crearTablero(bytesNuevos);

    if(nuevoTablero == 0) return;

    inicializarBuffer(nuevoTablero, bytesNuevos);

    for(int f = 0; f < filas; f++){

        for(int c = 0; c < nuevasColumnas; c++){

            int columnaVieja;

            if(c < columna){
                columnaVieja = c;
            }
            else{
                columnaVieja = c + 1;
            }

            int posicionVieja = calcularPosicion(f, columnaVieja, columnas);

            unsigned char ficha = obtenerFicha(tablero, posicionVieja);

            int posicionNueva = calcularPosicion(f, c, nuevasColumnas);

            guardarFicha(nuevoTablero,posicionNueva,ficha);
        }
    }

    delete[] tablero;

    tablero = nuevoTablero;
    columnas = nuevasColumnas;
}

void procesarCascadas(unsigned char* tablero,int* eliminadas,int filas,int columnas,int& fichasEliminadas,
                      int& combinacionesDetectadas,
                      int& cascadasActuales,
                      int& puntuacion){
    int cantidadEliminadas;

    cascadasActuales = 0;

    bool primeraEliminacion = true;

    while(true){

        cantidadEliminadas =buscarCombinaciones(tablero,eliminadas,filas,columnas,combinacionesDetectadas);

        if(cantidadEliminadas <= 0){
            break;
        }

        if(!primeraEliminacion){
            cascadasActuales++;
        }

        primeraEliminacion = false;

        fichasEliminadas += cantidadEliminadas;
        puntuacion += cantidadEliminadas * 10;

        eliminarFichas(tablero,eliminadas,cantidadEliminadas);

        hacerCaerTablero(tablero,filas,columnas);

        rellenarTablero(tablero,filas,columnas);
    }
}

void redimensionarEliminadas(int*& eliminadas, int filas, int columnas){
    if(filas <= 0 || columnas <= 0) return;

    int nuevaCantidad = filas * columnas;

    int* nuevasEliminadas = new int[nuevaCantidad];

    if(nuevasEliminadas == 0) return;

    delete[] eliminadas;

    eliminadas = nuevasEliminadas;
}
