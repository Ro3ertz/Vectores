#include <stdio.h>
#include <stdlib.h>

#include "vectors.h"


int main() {
    int option;
    char input[10];
    do {
        printf("Programa que realiza operaciones con vectores\n");
        printf("Selecciona el tipo de operaciones que quieres realizar\n");
        printf("0) Salir\n1) Vectores\n");
        if(fgets(input,10,stdin)==NULL){
            printf("Error: No se pudo leer la entrada");
            exit(1);
        }
        option=(int)strtol(input,NULL,10);
        switch (option) {
            case 0:
                printf("*****Seleccionaste Salir*****\n");
                break;
            case 1:
                printf("*****Seleccionaste Vectores*****\n");
                vectores();
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while (option != 0);

    return 0;
}
