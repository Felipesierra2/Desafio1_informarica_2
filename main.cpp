#include "memoriatablero.h"
#include "tablero.h"
#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    int filas = pedirFilas(), columnas = pedirColumnas();
    int* eliminadas = new int[filas*columnas];

    if(filas == -1 || columnas == -1){
        cout << "Dimensiones invalidas." << endl;
        return 0;
    }

    int bytesTablero = calcularBytesTablero(filas, columnas);
    unsigned char* tablero = crearTablero(bytesTablero);

    inicializarBuffer(tablero, bytesTablero);
    llenarTablero(tablero, filas,columnas);

    int cantidadEliminadas;
    int opcion = pedirAccion();

    while(opcion != 6){
        std::cout << std::endl;
        mostrarTablero(tablero,filas,columnas);

        if(opcion == 1){
            procesarEliminacionFicha(tablero,filas,columnas);
        }else if(opcion == 2){
            int fila = filaSeleccion(filas);
            agregarFila(tablero,filas,columnas,fila);
            mostrarTablero(tablero,filas,columnas);
        }else if(opcion == 3){
            int fila = filaSeleccion(filas);
            eliminarFila(tablero,filas,columnas,fila);
            mostrarTablero(tablero,filas,columnas);
        }else if(opcion == 6)break;


        opcion = pedirAccion();

        if(opcion == 6){
            break;
        }

        cantidadEliminadas = buscarCombinaciones(tablero, eliminadas, filas, columnas);

        eliminarFichas(tablero, eliminadas, cantidadEliminadas);

        hacerCaerTablero(tablero, filas, columnas);

        rellenarTablero(tablero, filas, columnas);
    }

    std::cout << std::endl;

    std::cout << "Bytes del tablero: " << bytesTablero << std::endl;

    // imprimirBits(tablero,bytesTablero);

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



