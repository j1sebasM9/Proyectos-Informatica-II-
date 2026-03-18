#ifndef PIEZA_H
#define PIEZA_H


extern int tipoPieza; // 0= I, 1= O, 2= T, 3= S, 4= Z, 5= J, 6= L
extern int rotacionPieza; // 0, 1, 2, 3 (posibles rotaciones de cada pieza)
extern int filaPieza; //Posición vertical del tablero
extern int colPieza; // posición horizontal del tablero




// Llena forma[] con el patrón literal según el tipo
// tipo   : qué pieza es (0-6)
// forma  : arreglo de 4 bytes que se va a llenar
void generarFormaBase(int tipo, unsigned char forma[4]);

// Rota forma[] 90° a la derecha y deja resultado en nuevaForma[]
void rotarDerecha(unsigned char forma[4]);



// Rota forma[] 90° a la izquierda y deja resultado en nuevaForma[]
void rotarIzquierda(unsigned char forma[4]);



// Genera la forma final combinando base + N rotaciones
// tipo     : qué pieza
// rotacion : cuántas veces rotar
// sentido  : 'R' derecha, 'L' izquierda
// forma    : arreglo donde se deja el resultado
void generarForma(int tipo, int rotacion, char sentido, unsigned char forma[4]);

int maxRotaciones(int tipo); //Maximo de rotaciones por tetrimo.

int piezaAleatoria();

void iniciarPieza (int ancho);

#endif
