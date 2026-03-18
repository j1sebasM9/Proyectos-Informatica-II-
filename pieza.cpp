#include "pieza.h"


// Variables globales
int tipoPieza;
int rotacionPieza;
int filaPieza;
int colPieza;
unsigned int semilla = 123456789; // Semilla para números aleatorios


void generarFormaBase(int tipo, unsigned char forma[4]){

    forma[0] = 0x00;
    forma[1] = 0x00;
    forma[2] = 0x00;
    forma[3] = 0x00;

    if(tipo ==0){ //Es la pieza I
        forma[0] = 0b11110000;
    }

    else if(tipo == 1){ //Es la pieza O
        forma[0] = 0b11000000;
        forma[1] = 0b11000000;
    }

    else if(tipo == 2){ //Es la pieza T
        forma[0] = 0b11100000;
        forma[1] = 0b01000000;
    }

    else if(tipo == 3){ // es la pieza S
        forma[0] = 0b01100000;
        forma[1] = 0b11000000;
    }

    else if(tipo == 4){ //Es la pieza Z
        forma[0] = 0b11000000;
        forma[1] = 0b01100000;
    }

    else if(tipo == 5){  //Es la pieza J
        forma[0] = 0b11100000;
        forma[1] = 0b10000000;
    }

    else if(tipo == 6){
        forma[0] = 0b11100000;
        forma[1] = 0b00100000;
    }
}



//Función para rotar la pieza base 90° a la derecha
//Inicializar nueva forma en 0x00
void rotarDerecha(unsigned char forma[4]){

    unsigned char f0 = forma[0];   // guardar solo 4 bytes
    unsigned char f1 = forma[1];   // no un arreglo completo
    unsigned char f2 = forma[2];
    unsigned char f3 = forma[3];

    forma[0] = ((f3 & 0x80) >> 0) | ((f2 & 0x80) >> 1)
               | ((f1 & 0x80) >> 2) | ((f0 & 0x80) >> 3);

    forma[1] = ((f3 & 0x40) << 1) | ((f2 & 0x40) >> 0)
               | ((f1 & 0x40) >> 1) | ((f0 & 0x40) >> 2);

    forma[2] = ((f3 & 0x20) << 2) | ((f2 & 0x20) << 1)
               | ((f1 & 0x20) >> 0) | ((f0 & 0x20) >> 1);

    forma[3] = ((f3 & 0x10) << 3) | ((f2 & 0x10) << 2)
               | ((f1 & 0x10) << 1) | ((f0 & 0x10) >> 0);
}

//Función para rotar la pieza base 90° a la izquierda
void rotarIzquierda(unsigned char forma[4]){

    unsigned char f0 = forma[0];   // guardar solo 4 bytes
    unsigned char f1 = forma[1];   // no un arreglo completo
    unsigned char f2 = forma[2];
    unsigned char f3 = forma[3];

    forma[0] = ((f0 & 0x10) << 3) | ((f1 & 0x10) << 2)
               | ((f2 & 0x10) << 1) | ((f3 & 0x10) >> 0);

    forma[1] = ((f0 & 0x20) << 2) | ((f1 & 0x20) << 1)
               | ((f2 & 0x20) >> 0) | ((f3 & 0x20) >> 1);

    forma[2] = ((f0 & 0x40) << 1) | ((f1 & 0x40) >> 0)
               | ((f2 & 0x40) >> 1) | ((f3 & 0x40) >> 2);

    forma[3] = ((f0 & 0x80) >> 0) | ((f1 & 0x80) >> 1)
               | ((f2 & 0x80) >> 2) | ((f3 & 0x80) >> 3);
}


//Función para generar la forma completa de la ficha.
void generarForma(int tipo, int rotacion, char sentido, unsigned char forma[4]){

    generarFormaBase(tipo, forma);

    for(int i = 0; i < rotacion; i++){
        if(sentido == 'R')
            rotarDerecha(forma);
        else
            rotarIzquierda(forma);
    }
}

//Maximo de rotaciones por tetrimo.
int maxRotaciones(int tipo){

    if(tipo == 1)           // O
        return 1;
    if(tipo == 0 || tipo == 3 || tipo == 4)  // I, S, Z
        return 2;
    return 4;               // T, J, L

}


//Función para generar un numero aleatorio (0-6) para cada ficha.
int piezaAleatoria(){
    semilla = semilla * 1664525 + 1013904223 ;
    return(semilla >> 24) % 7;
}

//Función para iniciar la pieza en la parte superior del tablero y centrada horizontalmente.
void iniciarPieza (int ancho){
    tipoPieza     = piezaAleatoria();
    rotacionPieza = 0;
    filaPieza     = 0;
    colPieza      = ancho/2 - 2;
}
