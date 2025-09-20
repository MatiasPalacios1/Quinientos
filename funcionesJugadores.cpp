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

int modo1Jugador(int dados[], int repetidos[], char nomJugador[], char nGanador[]){

    bool primerPuntaje;
    int puntajeGanador, puntajeTotal, maxPuntaje, puntaje, lanzamiento, ronda;
    int posMax, maxDado, valor;

    primerPuntaje = true;
    puntajeGanador = 0;
    puntajeTotal = 0;
    maxPuntaje = 0;
    puntaje = 0;
    lanzamiento = 1;
    ronda = 1;
        while(puntajeTotal<500){
                rlutil::cls();
                ponerCeroVector(repetidos, 6);
                rlutil::locate(1, 1);
                cout << "TURNO DE ";
                mostrarNombre(nomJugador, 12);
                rlutil::locate(23, 1);
                cout << "|";
                rlutil::locate(25, 1);
                cout << "RONDA N";
                rlutil::locate(32, 1);
                cout << (char) 248;
                rlutil::locate(34, 1);
                cout << ronda;
                rlutil::locate(37, 1);
                cout << "|";
                rlutil::locate(39, 1);
                cout << "PUNTAJE TOTAL: " << puntajeTotal;
                rlutil::locate(58, 1);
                cout << "PUNTOS";
                rlutil::locate(1, 2);
                cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
                rlutil::locate(1, 3);
                if(lanzamiento == 1){
                    cout << "MAXIMO PUNTAJE DE LA RONDA: " << 0;
                }
                else{
                    cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntaje;
                }
                rlutil::locate(32, 3);
                cout << " PUNTOS";
                rlutil::locate(1, 4);
                cout << "LANZAMIENTO N";
                rlutil::locate(14, 4);
                cout << (char) 248;
                rlutil::locate(16, 4);
                cout << lanzamiento;
                rlutil::locate(1, 5);
                cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
                tirarDados(dados, 6);
                valor = dados[0];
                dibujarDado(valor, 4, 8);
                valor = dados[1];
                dibujarDado(valor, 15, 8);
                valor = dados[2];
                dibujarDado(valor, 26, 8);
                valor = dados[3];
                dibujarDado(valor, 37, 8);
                valor = dados[4];
                dibujarDado(valor, 48, 8);
                valor = dados[5];
                dibujarDado(valor, 59, 8);
                /*if(escalera(dados, 6)){
                    rlutil::locate(1, 14);
                    cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!";
                    rlutil::anykey();
                    return 0;
                }*/
                if(sexteto6(dados, 6)){
                    puntaje = 0;
                    lanzamiento = 4;
                    rlutil::locate(1, 14);
                    cout << "SEXTETO 6 ¡PERDES TODOS LOS PUNTOS!";
                    rlutil::anykey();
                }
                for(int i=0; i<6; i++){
                    repetidos[i] = contarNumerosRepetidos(dados, 6, i+1);
                }
                posMax = maximoVector(repetidos, 6);
                maxDado = posMax + 1;
                if(contarNumerosRepetidos(dados, 6, maxDado)<3){
                    rlutil::locate(1, 14);
                    cout << "SUMA DE DADOS";
                    puntaje = sumaDados(dados, 6);
                    rlutil::locate(1, 15);
                    cout << "PUNTAJE: " << puntaje;
                }
                if(contarNumerosRepetidos(dados, 6, maxDado)>2 && contarNumerosRepetidos(dados, 6, maxDado)<6){
                    rlutil::locate(1, 14);
                    cout << "TRIO X++ ( )";
                    rlutil::locate(11, 14);
                    cout << maxDado;
                    puntaje = trioX(maxDado);
                    rlutil::locate(1, 15);
                    cout << "PUNTAJE: " << puntaje;
                }
                if(contarNumerosRepetidos(dados, 6, maxDado)==6 && maxDado!=6){
                    rlutil::locate(1, 14);
                    cout << "SEXTETO X ( )";
                    rlutil::locate(12, 14);
                    cout << maxDado;
                    puntaje = sextetoX(maxDado);
                    rlutil::locate(1, 15);
                    cout << "PUNTAJE: " << puntaje;
                }
                if(primerPuntaje){
                    maxPuntaje = puntaje;
                    primerPuntaje = false;
                }
                else{
                    if(puntaje > maxPuntaje){
                        maxPuntaje = puntaje;
                    }
                }
                if(lanzamiento<3){
                    lanzamiento++;
                }
                else{
                    lanzamiento = 1;
                    ronda++;
                    puntajeTotal+=maxPuntaje;
                    primerPuntaje = true;
                }
                rlutil::anykey();
            }
            rlutil::cls();
            puntajeGanador = puntajeTotal;
            strcpy(nGanador, nomJugador);
            mostrarPuntajes(nGanador, puntajeGanador);
            return puntajeGanador;
}

int modo2Jugadores(int dados [], int repetidos [], char Jugador1 [], char Jugador2 [], char nombreAUXILIAR [], char nombreGanador []){

    bool primerRonda, primerPuntaje, j1_500, j2_500;
    int puntajeTotal, maxPuntaje, puntaje, puntajeTotalJ2, puntajeGanador;
    int lanzamiento, ronda, valor, posMax, maxDado;

    strcpy(nombreAUXILIAR, Jugador1);
    primerRonda = true;
    primerPuntaje = true;
    j1_500 = false;
    j2_500 = false;
    puntajeTotal = 0;
    maxPuntaje = 0;
    puntaje = 0;
    puntajeTotalJ2 = 0;
    puntajeGanador = 0;
    lanzamiento = 1;
    ronda = 1;
        while(puntajeTotal<500 && puntajeTotalJ2<500){
            rlutil::cls();
            dibujarRecuadro(10, 4, 50, 10);
            rlutil::locate(28, 6);
            cout << "RONDA N";
            rlutil::locate(35, 6);
            cout << (char) 248;
            rlutil::locate(37, 6);
            cout << ronda;
            rlutil::locate(24, 7);
            cout << "PROXIMO TURNO: ";
            mostrarNombre(nombreAUXILIAR, 12);
            rlutil::locate(19, 9);
            cout << "PUNTAJE ";
            mostrarNombre(Jugador1, 12);
            rlutil::locate(40, 9);
            cout << ": " << puntajeTotal;
            rlutil::locate(46, 9);
            cout << "PUNTOS";
            rlutil::locate(19, 10);
            cout << "PUNTAJE ";
            mostrarNombre(Jugador2, 12);
            rlutil::locate(40, 10);
            cout << ": " << puntajeTotalJ2;
            rlutil::locate(46, 10);
            cout << "PUNTOS";
            rlutil::locate(1, 20);
            cout << "PRESIONE UNA TECLA PARA CONTINUAR...";
            rlutil::anykey();
                while(lanzamiento<=3){
                    rlutil::cls();
                    ponerCeroVector(repetidos, 6);
                    rlutil::locate(1, 1);
                    cout << "TURNO DE ";
                    mostrarNombre(nombreAUXILIAR, 12);
                    rlutil::locate(23, 1);
                    cout << "|";
                    rlutil::locate(25, 1);
                    cout << "RONDA N";
                    rlutil::locate(32, 1);
                    cout << (char) 248;
                    rlutil::locate(34, 1);
                    cout << ronda;
                    rlutil::locate(37, 1);
                    cout << "|";
                    rlutil::locate(39, 1);
                    cout << "PUNTAJE TOTAL: ";
                    if(primerRonda){
                        cout << puntajeTotal;
                    }
                    else{
                        cout << puntajeTotalJ2;
                    }
                    rlutil::locate(58, 1);
                    cout << "PUNTOS";
                    rlutil::locate(1, 2);
                    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
                    rlutil::locate(1, 3);
                    if(lanzamiento == 1){
                    cout << "MAXIMO PUNTAJE DE LA RONDA: " << 0;
                    }
                    else{
                        cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntaje;
                    }
                    rlutil::locate(32, 3);
                    cout << " PUNTOS";
                    rlutil::locate(1, 4);
                    cout << "LANZAMIENTO N";
                    rlutil::locate(14, 4);
                    cout << (char) 248;
                    rlutil::locate(16, 4);
                    cout << lanzamiento;
                    rlutil::locate(1, 5);
                    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
                    tirarDados(dados, 6);
                    valor = dados[0];
                    dibujarDado(valor, 4, 8);
                    valor = dados[1];
                    dibujarDado(valor, 15, 8);
                    valor = dados[2];
                    dibujarDado(valor, 26, 8);
                    valor = dados[3];
                    dibujarDado(valor, 37, 8);
                    valor = dados[4];
                    dibujarDado(valor, 48, 8);
                    valor = dados[5];
                    dibujarDado(valor, 59, 8);
                    /*if(escalera(dados, 6)){
                        rlutil::locate(1, 14);
                        cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!";
                        rlutil::anykey();
                        return 0;
                    }*/
                    if(sexteto6(dados, 6)){
                        puntaje = 0;
                        lanzamiento = 4;
                        rlutil::locate(1, 14);
                        cout << "SEXTETO 6 ¡PERDES TODOS LOS PUNTOS DE LA RONDA!";
                        rlutil::anykey();
                    }
                    for(int i=0; i<6; i++){
                        repetidos[i] = contarNumerosRepetidos(dados, 6, i+1);
                    }
                    posMax = maximoVector(repetidos, 6);
                    maxDado = posMax + 1;
                    if(contarNumerosRepetidos(dados, 6, maxDado)<3){
                        rlutil::locate(1, 14);
                        cout << "SUMA DE DADOS";
                        puntaje = sumaDados(dados, 6);
                        rlutil::locate(1, 15);
                        cout << "PUNTAJE: " << puntaje;
                    }
                    if(contarNumerosRepetidos(dados, 6, maxDado)>2 && contarNumerosRepetidos(dados, 6, maxDado)<6){
                        rlutil::locate(1, 14);
                        cout << "TRIO X++ ( )";
                        rlutil::locate(11, 14);
                        cout << maxDado;
                        puntaje = trioX(maxDado);
                        rlutil::locate(1, 15);
                        cout << "PUNTAJE: " << puntaje;
                    }
                    if(contarNumerosRepetidos(dados, 6, maxDado)==6 && maxDado!=6){
                        rlutil::locate(1, 14);
                        cout << "SEXTETO X ( )";
                        rlutil::locate(12, 14);
                        cout << maxDado;
                        puntaje = sextetoX(maxDado);
                        rlutil::locate(1, 15);
                        cout << "PUNTAJE: " << puntaje;
                    }
                    if(primerPuntaje){
                        maxPuntaje = puntaje;
                        primerPuntaje = false;
                    }
                    else{
                        if(puntaje > maxPuntaje){
                            maxPuntaje = puntaje;
                        }
                    }
                    if(lanzamiento<3){
                        lanzamiento++;
                    }
                    else{
                        lanzamiento = 4;
                    }
                    rlutil::anykey();
                }
                if(primerRonda){
                    strcpy(nombreAUXILIAR, Jugador2);
                    puntajeTotal+=maxPuntaje;
                    primerPuntaje = true;
                    primerRonda = false;
                }
                else{
                    strcpy(nombreAUXILIAR, Jugador1);
                    puntajeTotalJ2+=maxPuntaje;
                    primerPuntaje = true;
                    primerRonda = true;
                    ronda++;
                }
                lanzamiento = 1;
        }
        rlutil::cls();
        if(puntajeTotal>500){
            j1_500 = true;
        }
        else{
            j2_500 = true;
        }
        if(j1_500){
            puntajeGanador = puntajeTotal;
            strcpy(nombreGanador, Jugador1);
            mostrarPuntajesModo2J(nombreGanador, puntajeGanador, ronda);
        }
        else{
            ronda--;
            puntajeGanador = puntajeTotalJ2;
            strcpy(nombreGanador, Jugador2);
            mostrarPuntajesModo2J(nombreGanador, puntajeGanador, ronda);
        }
        return puntajeGanador;
}
