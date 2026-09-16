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
