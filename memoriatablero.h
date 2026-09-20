#ifndef MEMORIATABLERO_H
#define MEMORIATABLERO_H

void guardarFicha(unsigned char* memoria, int posicion, unsigned char ficha);
int calcularBytesTablero(int filas, int columnas);
void inicializarBuffer(unsigned char* buffer, int &bytesTablero);
unsigned char* crearTablero(int bytes);
int calcularPosicion(int fila, int columna, int columnas);
unsigned char obtenerFicha(unsigned char* memoria, int posicion);
void imprimirBits(const unsigned char *byte, int numBytes);
void hacerCaerColumna(unsigned char* tablero, int columna,int filas, int columnas);


#endif // MEMORIATABLERO_H
