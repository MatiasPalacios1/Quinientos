#include <iostream>
#include <cstring>
#include <ctime>
#include "rlutil.h"

using namespace std;

#include "combinacionesGanadoras.h"
#include "declaracionDados.h"
#include "declaracionNombres.h"
#include "declaracionRecuadro.h"
#include "funciones.h"
#include "modoJugadores.h"

int main(){

    int dados[6], vecRepetidos[6], opcion = 0, puntajeGanador = 0, puntajeMaximo = 0;
    char nombreJugador[12], nombreJugador2[12], nombreAUX[12], nombreGanador[12], ganadorMaximo[12];
    bool primerPuntaje = true;

    rlutil::hidecursor();
    rlutil::setBackgroundColor(9);
    rlutil::setColor(15);
    rlutil::cls();

    while(true){

        opcionMenu("NUEVO JUEGO: UN JUGADOR", 22, 9, opcion == 0);
        opcionMenu("NUEVO JUEGO: DOS JUGADORES", 21, 10, opcion == 1);
        opcionMenu("PUNTUACION MAS ALTA", 24, 11, opcion == 2);

        switch(rlutil::getkey()){
        case 14: ///TECLA PARA ARRIBA
            rlutil::locate(18, 6+opcion);
            cout << " ";
            opcion--;
            if(opcion<0){
                opcion = 0;
            }
            break;
        case 15: ///TECLA PARA ABAJO
            rlutil::locate(18, 6+opcion);
            cout << " ";
            opcion++;
            if(opcion>2){
                opcion = 2;
            }
            break;
        case 1: ///ENTER. OPCIONES DEL MENU
            switch(opcion){
            case 0:
                rlutil::cls();
                rlutil::locate(1, 1);
                cout << "NOMBRE DEL JUGADOR: ";
                cargarNombre(nombreJugador, 12);
                puntajeGanador = modo1Jugador(dados, vecRepetidos, nombreJugador, nombreGanador);
                rlutil::anykey();
                rlutil::cls();
                break;
            case 1:
                rlutil::cls();
                rlutil::locate(1, 1);
                cout << "JUGADOR 1";
                rlutil::locate(1, 3);
                cout << "NOMBRE: ";
                cargarNombre(nombreJugador, 12);
                rlutil::cls();
                rlutil::locate(1, 1);
                cout << "JUGADOR 2";
                 rlutil::locate(1, 3);
                cout << "NOMBRE: ";
                cargarNombre(nombreJugador2, 12);
                puntajeGanador = modo2Jugadores(dados, vecRepetidos, nombreJugador, nombreJugador2, nombreAUX, nombreGanador);
                rlutil::anykey();
                rlutil::cls();
                break;
            case 2:
                rlutil::setColor(15);
                rlutil::cls();
                if(primerPuntaje){
                    strcpy(ganadorMaximo, nombreGanador);
                    puntajeMaximo = puntajeGanador;
                    mostrarPuntajes(ganadorMaximo, puntajeMaximo);
                    primerPuntaje = false;
                }
                else{
                    if(puntajeGanador > puntajeMaximo){
                        strcpy(ganadorMaximo, nombreGanador);
                        puntajeMaximo = puntajeGanador;
                        mostrarPuntajes(ganadorMaximo, puntajeMaximo);
                    }
                    else{
                        mostrarPuntajes(ganadorMaximo, puntajeMaximo);
                    }
                }
                rlutil::anykey();
                rlutil::cls();
                break;
            }
        default:
            break;
        }
    }
    return 0;
}
