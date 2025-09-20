#include <iostream>
#include <cstring>
#include <ctime>
#include "rlutil.h"

using namespace std;

#include "declaracionDados.h"

void tirarDados(int vec[], int tam){
    int i;
    srand(time(0));
        for( i=0; i<tam; i++ ){
            vec[i] = (rand()%6)+1;
            /*cout << vec[i] << "\t";*/
        }
}

void dibujarCuadrado(int posX, int posY){ ///LE MANDO COMO PARAMETROS LA UBICACION, POSX (COLUMNA) POSY (FILA).
    const int ANCHO = 10, ALTO = 4;
    int i;
    for(i=posX; i<=posX+ANCHO; i++){
            rlutil::setColor(15);
            rlutil::locate(i, posY);
            cout << (char) 196;
            rlutil::locate(i, posY+ALTO);
            cout << (char) 196;
    }
    for(i=posY; i<=posY+ALTO; i++){
        rlutil::setColor(15);
        rlutil::locate(posX, i);
        cout << (char) 179;
        rlutil::locate(posX+ANCHO, i);
        cout << (char) 179;
    }
///ESQUINAS
rlutil::setColor(15);
rlutil::locate(posX, posY);
cout << (char) 218;
rlutil::locate(posX+ANCHO, posY);
cout << (char) 191;
rlutil::locate(posX, posY+ALTO);
cout << (char) 192;
rlutil::locate(posX+ANCHO, posY+ALTO);
cout << (char) 217;
}

void dibujarValor(int numero, int posX, int posY){
    dibujarCuadrado(posX, posY);
    rlutil::setColor(15);
        switch(numero){
        case 1: rlutil::locate(posX+5, posY+2);
            cout << (char) 254;
            break;
        case 2: rlutil::locate(posX+7, posY+1);
            cout << (char) 254;
            rlutil::locate(posX+3, posY+3);
            cout << (char) 254;
            break;
        case 3: rlutil::locate(posX+5, posY+2);
            cout << (char) 254;
            rlutil::locate(posX+8, posY+1);
            cout << (char) 254;
            rlutil::locate(posX+2, posY+3);
            cout << (char) 254;
            break;
        case 4: rlutil::locate(posX+3, posY+1);
            cout << (char) 254;
            rlutil::locate(posX+3, posY+3);
            cout << (char) 254;
            rlutil::locate(posX+7, posY+1);
            cout << (char) 254;
            rlutil::locate(posX+7, posY+3);
            cout << (char) 254;
            break;
        case 5: rlutil::locate(posX+5, posY+2);
            cout << (char) 254;
            rlutil::locate(posX+3, posY+1);
            cout << (char) 254;
            rlutil::locate(posX+3, posY+3);
            cout << (char) 254;
            rlutil::locate(posX+7, posY+1);
            cout << (char) 254;
            rlutil::locate(posX+7, posY+3);
            cout << (char) 254;
            break;
        case 6: rlutil::locate(posX+3, posY+1);
            cout << (char) 254;
            rlutil::locate(posX+3, posY+2);
            cout << (char) 254;
            rlutil::locate(posX+3, posY+3);
            cout << (char) 254;
            rlutil::locate(posX+7, posY+1);
            cout << (char) 254;
            rlutil::locate(posX+7, posY+2);
            cout << (char) 254;
            rlutil::locate(posX+7, posY+3);
            cout << (char) 254;
            break;
        }
}

void dibujarDado(int numero, int posX, int posY){
        dibujarCuadrado(posX, posY);
        dibujarValor(numero, posX, posY);
}
