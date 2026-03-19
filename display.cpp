#include <iostream>
#include "display.h"

using namespace std;


// Imprime el tablero con la pieza activa superpuesta
void imprimirTablero(unsigned char forma[4], int fila, int col){

    int ancho = obtenerAncho();
    int alto  = obtenerAlto();

    cout << endl;

    for(int i = 0; i < alto; i++){

        for(int j = 0; j < ancho; j++){

            int ocupado = celdaOcupada(i, j);
            int partePieza = 0;

            // verificar si la pieza activa ocupa esta celda
            int filaRel = i - fila;
            int colRel  = j - col;

            if(filaRel >= 0 && filaRel < 4 && colRel >= 0 && colRel < 4){

                unsigned char mascara = 0x80 >> colRel;

                if(forma[filaRel] & mascara)
                    partePieza = 1;
            }

            if(ocupado || partePieza)
                cout << "# ";
            else
                cout << ". ";
        }

        cout << endl;
    }

    cout << endl;
}


// Imprime el tablero y mensaje de Game Over
void imprimirGameOver(unsigned char forma[4], int fila, int col){

    imprimirTablero(forma, fila, col);

    cout << endl;
    cout << "===== GAME OVER =====" << endl;
}
