//
// Created by roobe on 28/11/2023.
//

#ifndef VECTORES_POLINOMIOS_VECTORS_H
#define VECTORES_POLINOMIOS_VECTORS_H

#include "vectors_function.h"

void vectores(){
    int quantity,option,optionWhile=1;
    printf("Programa que realiza operaciones con vectores de n dimensiones\n");
    printf("Dime de cuantas dimensiones seran los vectores\n");
    char input[10];
    if(fgets(input,10,stdin)==NULL){
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    quantity=(int)strtol(input,NULL,10);
    if(errno==ERANGE){
        printf("Error: Numero fuera del rango.\n");
        exit(1);
    }else if(quantity<=0){
        printf("Error: la cantidad debe ser mayor que cero.\n");
        exit(1);
    }
    float *vector1 = (float *) calloc(quantity,sizeof(float ));
    float *vector2 = (float *) calloc(quantity,sizeof(float ));
    float *resultantVector = (float *) calloc(quantity,sizeof(float ));

    fillVectors(vector1,vector2,quantity);

    do {
        printf("Que operacion te gustaria realizar\n");
        printf("0) Salir\n1) Suma\n2) Resta\n3) Producto por un escalar\n4) Norma\n5) Angulo entre vectores\n");
        if(fgets(input,10,stdin)==NULL){
            printf("Error: No se pudo leer la entrada");
            exit(1);
        }
        option=(int)strtol(input,NULL,10);
        if(option==0){
            optionWhile=option;
        }
        if(errno==ERANGE){
            printf("Error: Numero fuera de rango.\n");
            exit(1);
        }else if(option<0 || option>5){
            printf("Numero fuera de rango");
            exit(1);
        }
        switch (option) {
            case 0:
                printf("Gracias por usar el programa\n");
                break;
            case 1:
                printVectors(vector1,vector2,quantity);
                printf("Seleccionaste Suma\n");
                sumVectors(resultantVector,vector1,vector2,quantity);
                break;
            case 2:
                printVectors(vector1,vector2,quantity);
                printf("Seleccionste resta\n");
                subtractVectors(resultantVector,vector1,vector2,quantity);
                break;
            case 3:
                printVectors(vector1,vector2,quantity);
                printf("Seleccionaste Producto por un Escalar\n");
                scalarMultiplication(resultantVector,vector1,vector2,quantity);
                break;
            case 4:
                printVectors(vector1,vector2,quantity);
                printf("Seleccionaste Norma\n");
                normaOfAVector(vector1,vector2,quantity);
                break;
            case 5:
                printVectors(vector1,vector2,quantity);
                printf("Seleccionaste Angulo entre 2 vectores\n");
                angleBetweenVectors(vector1,vector2,quantity);
                break;
            default:
                printf("Opcion no disponoble\n");
                break;
        }
    } while (optionWhile!=0);
}

#endif //VECTORES_POLINOMIOS_VECTORS_H
