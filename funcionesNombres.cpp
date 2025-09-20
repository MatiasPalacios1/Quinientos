#include <iostream>
#include <cstring>
#include "rlutil.h"

using namespace std;

#include "declaracionNombres.h"

void cargarNombre(char *vec, int tam){
    int i=0;
    fflush(stdin);
    for (i=0; i<tam; i++){
        vec[i]=cin.get();
            if (vec[i]=='\n'){
                break;
            }
    }
    vec[i]='\0';
    fflush(stdin);
}

void mostrarNombre(char vec[], int tam){
    fflush(stdin);
    cout << vec;
}
