#include "tablero.h"
#include "memoriatablero.h"
#include <iostream>


/*Funcion que se encarga de llenar el buffer del tablero con ceros,
 de esta manera sera mas fácil manipular los bits*/
void inicializarBuffer(unsigned char* buffer, int& bytesTablero){
    int numBytes = (bytesTablero * 3 + 7) / 8;
    for (int i = 0; i < numBytes; i++){
        buffer[i] = 0;
    }
}

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

unsigned char asignarLetra(unsigned char ficha){
    if( ficha == 0) return 'A';
    else if(ficha == 1) return 'B';
    else if(ficha == 2) return 'C';
    else if(ficha == 3) return 'D';
    else if(ficha == 4) return 'E';
    else if(ficha == 5) return 'F';
}

void guardarFicha(unsigned char* memoria, int posicion, unsigned char fichas){
    fichas = fichas & 0x07;

    int bitInicial = posicion * 3;
    int byteInicio = bitInicial / 8;
    int offSetBit = bitInicial % 8;

    int bitsEscritos = 0;
    int byteActual = byteInicio;
    int bitActual = offSetBit;

    unsigned char mascara = 0x80; //10000000

    while(bitsEscritos < 3){
        unsigned char bitValor = (fichas >> (2 - bitsEscritos)) & 1;

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

int calcularPosicion(int fila, int columna, int columnas){
    return fila*columnas + columna;
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
