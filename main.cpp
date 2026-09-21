#include "memoriatablero.h"
#include "tablero.h"
#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    int filas = pedirFilas(), columnas = pedirColumnas();

    if(filas == -1 || columnas == -1){
        cout << "Dimensiones invalidas." << endl;
        return 0;
    }

    int bytesTablero = calcularBytesTablero(filas, columnas);
    int* eliminadas = new int[filas*columnas];
    unsigned char* tablero = crearTablero(bytesTablero);

    inicializarBuffer(tablero, bytesTablero);
    llenarTablero(tablero, filas,columnas);
    mostrarTablero(tablero,filas,columnas);

    int cantidadEliminadas;
    int opcion = pedirAccion();

    while(opcion != 6){
        std::cout << std::endl;

        if(opcion == 1){
            procesarEliminacionFicha(tablero, filas, columnas);

            cantidadEliminadas = buscarCombinaciones(tablero, eliminadas, filas, columnas);

            eliminarFichas(tablero, eliminadas, cantidadEliminadas);

            hacerCaerTablero(tablero, filas, columnas);

            rellenarTablero(tablero, filas, columnas);
        }else if(opcion == 2){
            int fila = filaSeleccion(filas);

            agregarFila(tablero,filas,columnas,fila);
        }else if(opcion == 3){
            int fila = filaSeleccion(filas);

            eliminarFila(tablero,filas,columnas,fila);

        }else if(opcion == 4){
            int columna = columnaSeleccion(columnas);

            agregarColumna(tablero,filas,columnas,columna);
        }else if(opcion == 5){
            int columna = columnaSeleccion(columnas);

            eliminarColumna(tablero,filas,columnas,columna);
        }else if(opcion == 6)break;

        mostrarTablero(tablero,filas,columnas);
        opcion = pedirAccion();

        if(opcion == 6){
            break;
        }

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



