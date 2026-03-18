#ifndef JUEGO_H
#define JUEGO_H

// Retorna 1 si hay colisión, 0 si no
int hayColision(unsigned char forma[4], int fila, int col);

// Fija la pieza activa en el tablero
void fijarPieza(unsigned char forma[4], int fila, int col);

// Retorna 1 si la fila está completamente llena
int filaLlena(int fila);

// Elimina filas llenas y sube filas vacías al tope
void limpiarFilas();

// Retorna 1 si hay game over
int verificarGameOver();

#endif 