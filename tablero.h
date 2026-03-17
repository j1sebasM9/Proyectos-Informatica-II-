#ifndef TABLERO_H
#define TABLERO_H


// Declaración externa para acceso directo desde otros módulos
extern unsigned char** tablero;
extern int ancho;
extern int alto;
extern int bytesPorFila;

// Creacion y destruccion del tablero
void crearTablero(int ancho, int alto);
void destruirTablero();

// Operaciones sobre celdas
void ocuparCelda(int fila, int col);
int  celdaOcupada(int fila, int col);

// Consultas de dimensiones
int  obtenerAncho();
int  obtenerAlto();
int  obtenerBytesPorFila();

#endif