#include "juego.h"
#include "tablero.h"
#include "pieza.h"


//Función que permite indentificar una colsión con la ficha. 
int hayColision(unsigned char forma[4], int fila, int col){

    int alto         = obtenerAlto();
    int bytesporFila = obtenerBytesPorFila();

    for(int i = 0; i < 4; i++){

        // Fila vacía, no hay nada que verificar
        if(forma[i] == 0x00) continue;

        // Colisión con suelo usando bits
        // mascaraSuelo = 0xFF si fila válida, 0x00 si fuera del tablero
        // ~0xFF = 0x00 → no colisión
        // ~0x00 = 0xFF → forma[i] & 0xFF = forma[i] → colisión
        unsigned char mascaraSuelo = (fila + i < alto) ? 0xFF : 0x00;
        if(forma[i] & ~mascaraSuelo) return 1;

        //  Proyectar fila de pieza sobre el tablero 
        int byteInicio = col / 8;
        int bitOffset  = col % 8;

        unsigned char parteAlta = forma[i] >> bitOffset;
        unsigned char parteBaja = (bitOffset == 0) ? 0x00 : forma[i] << (8 - bitOffset);
                                  

        //  Borde izquierdo con bits 
        // Extrae bit de signo de col
        // si col < 0 → bit 31 activo → colisión
        if((unsigned int)col >> 31) return 1;

        //  Borde derecho con bits
        // parteBaja tiene bits activos pero no hay byte siguiente
        if((byteInicio + 1 >= bytesporFila) && (parteBaja != 0x00)) return 1;

        //  Colisión con piezas fijas en el tablero 
        if(tablero[fila + i][byteInicio] & parteAlta) return 1;

        if(byteInicio + 1 < bytesporFila)
            if(tablero[fila + i][byteInicio + 1] & parteBaja) return 1;
    }

    return 0;  // ninguna colisión detectada

}

//Función que permita fijar una pieza en el tablero. 
void fijarPieza(unsigned char forma[4], int fila, int col){

    int bytesporFila = obtenerBytesPorFila();

    for(int i = 0; i < 4; i++){

        // Fila vacía, nada que fijar
        if(forma[i] == 0x00) continue;

        //  Proyectar fila de pieza sobre el tablero 
        int byteInicio = col / 8;
        int bitOffset  = col % 8;

        unsigned char parteAlta = forma[i] >> bitOffset;
        unsigned char parteBaja = (bitOffset == 0) ? 0x00
                                  : forma[i] << (8 - bitOffset);

        //  Escribir en tablero con OR 
        // OR garantiza que bits ya fijos no se borren
        tablero[fila + i][byteInicio] |= parteAlta;

        if(byteInicio + 1 < bytesporFila)
            tablero[fila + i][byteInicio + 1] |= parteBaja;
    }
}


//Verificar si una fila ya se llenó. 
int filaLlena(int fila){

    int bytesporFila = obtenerBytesPorFila();

    for(int j = 0; j < bytesporFila; j++){

        // AND con 0xFF verifica los 8 bits de una vez
        // Si algún byte no es 0xFF : fila no está llena
        if((tablero[fila][j] & 0xFF) != 0xFF) return 0;
    }

    return 1;  // todos los bytes son 0xFF : fila llena
}



//Funcion para eliminar las filas llenas 
void limpiarFilas(){

    int alto         = obtenerAlto();
    int bytesporFila = obtenerBytesPorFila();

    int i = 0;

    while(i < alto){

        if(filaLlena(i)){

            // Guardar puntero de fila llena
            unsigned char* filaLimpia = tablero[i];

            // Limpiar con bits
            for(int j = 0; j < bytesporFila; j++)
                filaLimpia[j] &= 0x00;

            // Desplazar punteros superiores una posición hacia abajo
            for(int k = i; k > 0; k--)
                tablero[k] = tablero[k-1];

            // Insertar fila limpia al tope
            tablero[0] = filaLimpia;

            // NO incrementar i : revisar misma posición
            // porque bajó una fila nueva
        }
        else{
            i++;
        }
    }
}


int verificarGameOver(){

    int ancho = obtenerAncho();

    // Generar forma de la pieza nueva en posición inicial
    unsigned char forma[4] = {0x00, 0x00, 0x00, 0x00};
    generarFormaBase(tipoPieza, forma);

    // Verificar si la pieza puede colocarse en posición inicial
    // fila=0, col=ancho/2-2 : posición central superior
    if(hayColision(forma, 0, ancho/2 - 2)) return 1;

    return 0;
}