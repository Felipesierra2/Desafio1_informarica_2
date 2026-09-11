#include "tablero.h"

void inicializarBuffer(unsigned char* buffer, int& bytesTablero){
    int numBytes = (bytesTablero * 3 + 7) / 8;
    for (int i = 0; i < numBytes; i++){
        buffer[i] = 0;
    }
}

int calcularBytesTablero(int filas, int columnas) {
    return (filas * columnas * 3 + 7) / 8;
}

unsigned char* crearTablero(int filas, int columnas, int bytes){
    unsigned char* tablero = new unsigned char[bytes];

    return tablero;
}

unsigned char asignarLetra(int ficha){
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
