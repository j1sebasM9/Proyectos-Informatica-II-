//Modulo encargado de la creación del tablero 

#include "tablero.h"

unsigned char **tablero; 
int ancho;
int alto; 
int bytesPorFila; 


void crearTablero(int an, int al){
    ancho = an; 
    alto = al; 
    //Calculo de las columnas
    bytesPorFila = ancho / 8;

    //Creación el arreglo dinamico de punteros 
    tablero = new unsigned char * [alto];

    //Creación del arreglo dinanimico de bytes (del tipo unsigned char)
    for( int i = 0; i < alto; i++){
        tablero[i] = new unsigned char [bytesPorFila];

        for (int j = 0; j < bytesPorFila; j++){
            tablero[i][j] = 0x00; //todas las celdas vacías
        }
    }
}


void destruirTablero(){
    for (int i = 0; i < alto; i++){
        delete[] tablero[i]; //liberamos cada fila
    }
    delete []    tablero; //liberamos el arreglo de punteros
}


void ocuparCelda (int fila, int col){

    int byteIndex = col / 8;  //Byte de la fila
    int bitIndex = col % 8; //Bit dentro del byte

    unsigned char mascara = 0x80 >> bitIndex; //Creamos la mascara para el bit específico
    tablero[fila][byteIndex] |= mascara; //Ocupamos la celda usando OR bit a bit
}


int celdaOcupada(int fila, int col){
    int byteIndex = col / 8; //Byte de la fila
    int bitIndex = col % 8;//Bit dentro del byte

    unsigned char mascara = 0x80 >> bitIndex;
    
    //Verificamos si la celda está ocupada usando AND bit a bit
    return tablero[fila][byteIndex] & mascara; 
}





//Estas funciones retornan las dimensiones
// del tablero y el número de bytes por fila, lo cual es útil 
//para otras partes del programa que necesiten conocer 
//estas características del tablero.

int obtenerAncho(){
    return ancho;
}

int obtenerAlto(){
    return alto;
}

int obtenerBytesPorFila(){
    return bytesPorFila;
}
