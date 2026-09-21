#include "memoriatablero.h"
#include "tablero.h"
#include <iostream>

using namespace std;

int main(){
    srand(time(0));
    int eliminacionesUsuario = 0;
    int fichasEliminadas = 0;
    int combinacionesDetectadas = 0;
    int cascadasActuales = 0;
    int puntuacion = 0;
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

    while(opcion != 7){
        std::cout << std::endl;
        if(opcion == 1){
            eliminacionesUsuario++;

            procesarEliminacionFicha(tablero, filas, columnas);

            redimensionarEliminadas(eliminadas, filas, columnas);

            procesarCascadas(tablero,eliminadas,filas,columnas,fichasEliminadas,combinacionesDetectadas,
                             cascadasActuales,puntuacion);

            cout << "Eliminaciones realizadas: "
                 << eliminacionesUsuario << endl;

            cout << "Fichas eliminadas en total: "
                 << fichasEliminadas << endl;

            cout << "Combinaciones detectadas: "
                 << combinacionesDetectadas << endl;

            cout << "Cascadas de esta eliminacion: "
                 << cascadasActuales << endl;

            cout << "Puntuacion: "
                 << puntuacion << endl;

        }else if(opcion == 2){
            int fila = filaSeleccion(filas);

            agregarFila(tablero,filas,columnas,fila);

            redimensionarEliminadas(eliminadas, filas, columnas);

            procesarCascadas(tablero,
                             eliminadas,
                             filas,
                             columnas,
                             fichasEliminadas,
                             combinacionesDetectadas,
                             cascadasActuales,
                             puntuacion);

            cout << "Eliminaciones realizadas: "
                 << eliminacionesUsuario << endl;

            cout << "Fichas eliminadas en total: "
                 << fichasEliminadas << endl;

            cout << "Combinaciones detectadas: "
                 << combinacionesDetectadas << endl;

            cout << "Cascadas de esta eliminacion: "
                 << cascadasActuales << endl;

            cout << "Puntuacion: "
                 << puntuacion << endl;

        }else if(opcion == 3){
            int fila = filaSeleccion(filas);

            eliminarFila(tablero,filas,columnas,fila);

            redimensionarEliminadas(eliminadas, filas, columnas);

            procesarCascadas(tablero,
                             eliminadas,
                             filas,
                             columnas,
                             fichasEliminadas,
                             combinacionesDetectadas,
                             cascadasActuales,
                             puntuacion);

            cout << "Eliminaciones realizadas: "
                 << eliminacionesUsuario << endl;

            cout << "Fichas eliminadas en total: "
                 << fichasEliminadas << endl;

            cout << "Combinaciones detectadas: "
                 << combinacionesDetectadas << endl;

            cout << "Cascadas de esta eliminacion: "
                 << cascadasActuales << endl;

            cout << "Puntuacion: "
                 << puntuacion << endl;

        }else if(opcion == 4){
            int columna = columnaSeleccion(columnas);

            agregarColumna(tablero,filas,columnas,columna);

            redimensionarEliminadas(eliminadas, filas, columnas);

            procesarCascadas(tablero,
                             eliminadas,
                             filas,
                             columnas,
                             fichasEliminadas,
                             combinacionesDetectadas,
                             cascadasActuales,
                             puntuacion);

            cout << "Eliminaciones realizadas: "
                 << eliminacionesUsuario << endl;

            cout << "Fichas eliminadas en total: "
                 << fichasEliminadas << endl;

            cout << "Combinaciones detectadas: "
                 << combinacionesDetectadas << endl;

            cout << "Cascadas de esta eliminacion: "
                 << cascadasActuales << endl;

            cout << "Puntuacion: "
                 << puntuacion << endl;
        }else if(opcion == 5){
            int columna = columnaSeleccion(columnas);

            eliminarColumna(tablero,filas,columnas,columna);

            redimensionarEliminadas(eliminadas, filas, columnas);

            procesarCascadas(tablero,
                             eliminadas,
                             filas,
                             columnas,
                             fichasEliminadas,
                             combinacionesDetectadas,
                             cascadasActuales,
                             puntuacion);

            cout << "Eliminaciones realizadas: "
                 << eliminacionesUsuario << endl;

            cout << "Fichas eliminadas en total: "
                 << fichasEliminadas << endl;

            cout << "Combinaciones detectadas: "
                 << combinacionesDetectadas << endl;

            cout << "Cascadas de esta eliminacion: "
                 << cascadasActuales << endl;

            cout << "Puntuacion: "
                 << puntuacion << endl;
        }else if(opcion == 6){
            std::cout << "Bytes del tablero: " << bytesTablero << std::endl;
            imprimirBits(tablero,bytesTablero);
            std::cout << std::endl;
        }else if(opcion == 7)break;

        mostrarTablero(tablero,filas,columnas);
        opcion = pedirAccion();

        if(opcion == 6){
            break;
        }

    }

    delete[] tablero;
    delete[]eliminadas;
    tablero = nullptr;
    eliminadas = nullptr;

    return 0;
}



