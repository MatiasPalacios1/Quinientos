#include <iostream>
#include <cstring>
#include <ctime>
#include "rlutil.h"

using namespace std;

#include "declaracionRecuadro.h"

///X = DONDE EMPIEZA (COLUMNA)
///Y = DONDE TERMINA (FILA)
///ANCHO Y ALTO = TAMAÑO

///FOR = I EMPIEZA EN X (COLUMNA) Y DIBUJA HASTA LA ULTIMA COLUMNA (HORIZONTAL) X+ANCHO

void dibujarRecuadro(int x, int y, int ancho, int alto){
    int i;
    for(i=x; i<=x+ancho; i++){
        rlutil::setColor(15);
        rlutil::locate(i, y);
        cout << (char) 205;
        rlutil::locate(i, y+alto);
        cout << (char) 205;
    }

///FOR = I EMPIEZA EN Y (FILA) Y DIBUJA HASTA LA ULTIMA FILA (VERTICAL) Y+ALTO

     for(i=y; i<=y+alto; i++){
        rlutil::setColor(15);
        rlutil::locate(x, i);
        cout << (char) 186;
        rlutil::locate(x+ancho, i);
        cout << (char) 186;
    }

///ACA DIBUJO LOS BORDES DE TODAS LAS PUNTAS

    rlutil::locate(x, y);
    cout << (char) 201;

    rlutil::locate(x, y+alto);
    cout << (char) 200;

    rlutil::locate(x+ancho, y);
    cout << (char) 187;

    rlutil::locate(x+ancho, y+alto);
    cout << (char) 188;
}
