//Pedimos al usuario las dimensiones del tablero y las validamos.
//Tambien leemos las acciones del usuario mediante el teclado.
//Estos resultados sirven para que otros modulos los utlicen.

#include <iostream>
using namespace std;

void leerDimensiones(int* ancho , int * alto){
    int valor_ancho_tablero;
    int valor_alto_tablero;


    cout << "Ingrese el ancho del tablero (Recuerde que debe ser multiplo de 8): ";
    cin >> valor_ancho_tablero;



    //Validamos que el ancho cumple con los requisitos
    //Ser mayor o igual a 8 y ser un multiplo de 8.
    //Condición necesaria para pdoer crear el tablero usando bytes.
    while (valor_ancho_tablero < 8 || valor_ancho_tablero % 8 != 0){
        cout << "El ancho debe ser un multiplo de 8 y mayor o igual a 8. Por favor, ingrese un valor válido: ";
        cin >> valor_ancho_tablero;
    }
    *ancho = valor_ancho_tablero;

    cout << "Ingrese el alto del tablero; ";
    cin >> valor_alto_tablero;

    //Validamos que alto sea mayor o igual a 8.
    while (valor_alto_tablero < 8){
        cout << "El alto debe ser mayor o igual a 8. Por favor, ingrese un valor válido: ";
        cin >> valor_alto_tablero;
    }
    *alto = valor_alto_tablero;

}

char leerAccion(){


    //Opciones validas:
    //'A' : mover izquierda
    //'D' : mover derecha
    //'S' : bajar
    //'W' : rotar derecha
    //'E' : rotar izquierda
    //'Q' : salir


    char accion;
    cout << "Ingrese una acción (A: izquierda, D: derecha, S: bajar, W: rotar derecha, E: rotar izquierda, Q: salir): ";
    cin >> accion;

    //Validamos que la acción ingresada sea una de las opciones válidas.
    while (accion != 'A' && accion != 'a' && accion != 'D' && accion != 'd' && accion != 'S' && accion != 's' && accion != 'W' && accion != 'w' && accion != 'E' && accion != 'e' && accion != 'Q' && accion != 'q'){
        cout << "Acción inválida. Por favor, ingrese una acción válida (A: izquierda, D: derecha, S: bajar, W: rotar derecha, E: rotar izquierda, Q: salir): ";
        cin >> accion;
    }
    return accion;



}
