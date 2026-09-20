#ifndef TABLERO_H
#define TABLERO_H

unsigned char generarFicha();
void llenarTablero(unsigned char* tablero, int filas, int columnas);
unsigned char asignarLetra(unsigned char ficha);
int combHorizontales(unsigned char* tablero, int fila, int columna, int columnas);
int combVerticales(unsigned char* tablero, int fila, int columna, int filas, int columnas);
bool estaEliminada(int* eliminadas, int cantidadEliminadas, int posicion);
int buscarCombinaciones(unsigned char* tablero, int *eliminadas, int filas, int columnas);
void eliminarFichas(unsigned char* tablero, int* eliminadas,int cantidadEliminadas);
void hacerCaerTablero(unsigned char* tablero, int filas, int columnas);
void rellenarTablero(unsigned char* tablero, int filas, int columnas);
void mostrarTablero(unsigned char* tablero, int filas, int columnas);
int filaSeleccion(int filas);
int pedirPosicion(int filas, int columnas);
int pedirFilas();
int pedirColumnas();
int pedirAccion();


#endif // TABLERO_H
