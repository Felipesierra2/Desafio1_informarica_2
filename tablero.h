#ifndef TABLERO_H
#define TABLERO_H

int calcularBytesTablero(int filas, int columnas);
unsigned char* crearTablero(int filas, int columnas, int bytes);
void inicializarBuffer(unsigned char* buffer, int &bytesTablero);
void guardarFicha(unsigned char* memoria, int posicion, unsigned char fichas);
int calcularPosicion(int fila, int columna, int columnas);
unsigned char asignarLetra(int ficha);

#endif // TABLERO_H
