#include <iostream>
#include "display.h"
#include <cstdint>

using namespace std;


// Imprime el tablero con la pieza activa superpuesta y con borde
void imprimirTablero(uint8_t forma[4], int fila, int col){

    int ancho = obtenerAncho();
    int alto  = obtenerAlto();

    cout << endl;

    // borde superior
    cout << "+";
    for(int j = 0; j < ancho; j++){
        cout << "--";
    }
    cout << "+" << endl;

    for(int i = 0; i < alto; i++){

        // borde izquierdo
        cout << "|";

        for(int j = 0; j < ancho; j++){

            int ocupado = celdaOcupada(i, j);
            int partePieza = 0;

            // verificar si la pieza activa ocupa esta celda
            int filaRel = i - fila;
            int colRel  = j - col;

            if(filaRel >= 0 && filaRel < 4 && colRel >= 0 && colRel < 4){

                uint8_t mascara = 0x80 >> colRel;

                if(forma[filaRel] & mascara)
                    partePieza = 1;
            }

            if(ocupado || partePieza)
                cout << "# ";
            else
                cout << ". ";
        }

        // borde derecho
        cout << "|" << endl;
    }

    // borde inferior
    cout << "+";
    for(int j = 0; j < ancho; j++){
        cout << "--";
    }
    cout << "+" << endl;

    cout << endl;
}


void imprimirGameOver(uint8_t forma[4], int fila, int col){

    imprimirTablero(forma, fila, col);

    cout << endl;
    cout << "===== GAME OVER =====" << endl;
}
