#include <iostream>
#include <cstring>
#include <ctime>
#include "rlutil.h"

using namespace std;

#include "combinacionesGanadoras.h"

bool escalera(int vec[], int tam){
    int i, j;
	bool hayEscalera = true;
	for(i=0; i<tam-1; i++){
        for(j=i+1; j<tam; j++){
            if(vec[i]==vec[j]){
                hayEscalera = false;
            }
        }
	}
    return hayEscalera;
}

bool sexteto6(int vec[], int tam){
    int i;
	bool haySexteto = true;
	for(i=0; i<6; i++){
        if(vec[i]!=6){
            haySexteto = false;
        }
	}
    return haySexteto;
}

int sumaDados(int vec[], int tam){
    int i, sumar = 0;
    for(i=0; i<tam; i++){
        sumar += vec[i];
    }
    return sumar;
}

int trioX(int valor){
    return valor * 10;
}

int sextetoX(int valor){
    return valor * 50;
}
