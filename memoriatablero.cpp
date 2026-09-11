#include "memoriatablero.h"
#include <iostream>



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
