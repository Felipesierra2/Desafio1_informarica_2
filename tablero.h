#ifndef TABLERO_H
#define TABLERO_H

unsigned char generarFicha();
void llenarTablero(unsigned char* tablero, int filas, int columnas);
unsigned char asignarLetra(unsigned char ficha);
int combHorizontales(unsigned char* tablero, int fila, int columna, int columnas);
int combVerticales(unsigned char* tablero, int fila, int columna, int filas, int columnas);
bool estaEliminada(int* eliminadas, int cantidadEliminadas, int posicion);
int buscarCombinaciones(unsigned char* tablero, int *eliminadas, int filas, int columnas);


#endif // TABLERO_H
