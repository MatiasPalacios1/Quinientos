#include <iostream>
#include <cstring>
#include <ctime>
#include "rlutil.h"

using namespace std;

#include "funciones.h"
#include "declaracionNombres.h"

int contarNumerosRepetidos(int v[], int tam, int numero){
    int i, cont = 0;
    for(i=0; i<tam; i++){
        if(v[i]==numero){
            cont++;
        }
    }
    return cont;
}

int maximoVector(int vec[], int tam){
    int i, posMax = 0;
    for(i=1; i<tam; i++){
        if(vec[i]>=vec[posMax]){
            posMax = i;
        }
    }
    return posMax;
}

int minimoVector(int vec[], int tam){
    int i, posMin = 0;
    for(i=1; i<tam; i++){
        if(vec[i]<vec[posMin]){
            posMin = i;
        }
    }
    return posMin;
}

int ponerCeroVector(int vec[], int tam){
    int i;
    for(i=0; i<tam; i++){
        vec[i] = 0;
    }
}

void mostrarPuntajes(char v[], int puntos){
    rlutil::locate(1, 1);
    cout << "NOMBRE DEL JUGADOR: ";
    mostrarNombre(v, 12);
    rlutil::locate(1, 2);
    cout << "PUNTAJE MAXIMO: " << puntos;
}

void mostrarPuntajesModo2J(char v[], int puntos, int rondas){
    rlutil::locate(1, 1);
    cout << "NOMBRE DEL JUGADOR: ";
    mostrarNombre(v, 12);
    rlutil::locate(1, 2);
    cout << "PUNTAJE MAXIMO: " << puntos;
    rlutil::locate(1, 3);
    cout << "CANTIDAD DE RONDAS: " << rondas;
}

void opcionMenu(const char * texto, int posX, int posY, bool opcion){

    if(opcion){
        rlutil::setBackgroundColor(15);
        rlutil::setColor(9);
        rlutil::locate(posX - 2, posY);
        cout << (char)175 << " " << texto << " " << (char)174;
    }
    else{
        rlutil::setBackgroundColor(9);
        rlutil::setColor(15);
        rlutil::locate(posX - 2, posY);
        cout << "  " << texto << "  ";
    }
    rlutil::setBackgroundColor(9);
}
