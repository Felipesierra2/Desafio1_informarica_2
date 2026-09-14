#ifndef TABLERO_H
#define TABLERO_H

int calcularBytesTablero(int filas, int columnas);
unsigned char* crearTablero(int bytes);
void inicializarBuffer(unsigned char* buffer, int &bytesTablero);
void guardarFicha(unsigned char* memoria, int posicion, unsigned char fichas);
void llenarTablero(unsigned char* tablero, int filas, int columnas);
int calcularPosicion(int fila, int columna, int columnas);
unsigned char asignarLetra(unsigned char ficha);

#endif // TABLERO_H
