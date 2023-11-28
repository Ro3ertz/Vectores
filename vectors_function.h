//
// Created by roobe on 28/11/2023.
//

#ifndef VECTORES_POLINOMIOS_VECTORS_FUNCTION_H
#define VECTORES_POLINOMIOS_VECTORS_FUNCTION_H
#include <math.h>

void fillVectors(float *vector1, float *vector2, int quantity){
    char input[10];
    for (int i = 0; i < quantity; ++i) {
        printf("Ingresa el valor del vector 1 en el indice [%d]\n",i+1);
        if(fgets(input,10,stdin)==NULL){
            printf("Error: No se pudo leer la entrada");
            exit(1);
        }
        vector1[i] = strtof(input,NULL);
        if(errno==ERANGE){
            printf("Error: Mumero fuera de rango.\n");
            exit(1);
        }
    }
    for (int i = 0; i < quantity; ++i) {
        printf("Ingresa el valor del vector 2 en el indice [%d]\n",i+1);
        if(fgets(input,10,stdin)==NULL){
            printf("Error: No se pudo leer la entrada");
            exit(1);
        }
        vector2[i] = strtof(input,NULL);
        if(errno==ERANGE){
            printf("Error: Mumero fuera de rango.\n");
            exit(1);
        }
    }
}

void printVectors(float *vector1,float *vector2,int quantity){
    printf("\nVector 1");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf("%.2f,",vector1[i]);
    }
    printf(")\n");
    printf("\nVector 2");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf("%.2f,",vector2[i]);
    }
    printf(")\n");
}

void sumVectors(float *resultantVector,const float *vector1, const float *vector2,const int quantity){
    for (int i = 0; i < quantity; ++i) {
        resultantVector[i] = vector1[i]+vector2[i];
    }
    printf("\nEl resultado del vector es: ");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf("%.2f,",resultantVector[i]);
    }
    printf(")\n");
}

void subtractVectors(float *resultantVector,const float *vector1, const float *vector2,const int quantity){
    for (int i = 0; i < quantity; ++i) {
        resultantVector[i] = vector1[i]-vector2[i];
    }
    printf("\nEl resultado del vector es V1-V2 es: ");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf("%.2f,",resultantVector[i]);
    }
    printf(")\n");
    for (int i = 0; i < quantity; ++i) {
        resultantVector[i] = vector2[i]-vector1[i];
    }
    printf("\nEl resultado del vector es V2-V1 es: ");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf("%.2f,",resultantVector[i]);
    }
    printf(")\n");
}

void scalarMultiplication(float *resultantVector, const float *vector1, const float *vector2, const int quantity){
    char input[10];
    float scalar;
    printf("Dame el valor del escalar:");
    if(fgets(input,10,stdin)==NULL){
        printf("Error: No se pudo leer la entrada.\n");
        exit(1);
    }
    scalar= strtof(input,NULL);
    for (int i = 0; i < quantity; ++i) {
        resultantVector[i] = vector1[i]*scalar;
    }
    printf("\nEl resultado del vector V1 multiplicado por el escalar es: ");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf("%.2f,",resultantVector[i]);
    }
    printf(")\n");
    for (int i = 0; i < quantity; ++i) {
        resultantVector[i] = vector2[i]*scalar;
    }
    printf("\nEl resultado del vector V2 multiplicado por el escalar es: ");
    printf("(");
    for (int i = 0; i < quantity; ++i) {
        printf("%.2f,",resultantVector[i]);
    }
    printf(")\n");
}

float sumVectorComponents(const float *vector1, int quantity){
    float sum=0;
    for (int i = 0; i < quantity; ++i) {
        sum += vector1[i];
    }
    return sum;
}

void normaOfAVector(const float *vector1, const float *vector2, int quantity){
    float *newVector1 = (float *)calloc(quantity, sizeof(float ));
    float *newVector2 = (float *)calloc(quantity, sizeof(float ));
    float sumVector1;
    float sumVector2;
    for (int i = 0; i < quantity; ++i) {
        newVector1[i] = vector1[i]*vector1[i];
        newVector2[i] = vector2[i]*vector2[i];
    }
    sumVector1 = sumVectorComponents(newVector1,quantity);
    sumVector2 = sumVectorComponents(newVector2,quantity);
    printf("La norma del vector 1 es %.2f\n",sqrtf(sumVector1));
    printf("La norma del vector 2 es %.2f\n",sqrtf(sumVector2));
}

float dotProduct(const float *vector1,const float *vector2,int quantity){
    float sum = 0;
    for (int i = 0; i < quantity; ++i) {
        sum += vector1[i]*vector2[i];
    }
    return sum;
}

float normUniqueVector(const float *vector,int quantity){
    float *newVector = (float *)calloc(quantity,sizeof(float));
    float sumVector;
    for (int i = 0; i < quantity; ++i) {
        newVector[i] = vector[i]*vector[i];
    }
    sumVector = sumVectorComponents(newVector,quantity);
    return sqrtf(sumVector);
}

void angleBetweenVectors(float *vector1, float *vector2, int quantity){
    float sum = dotProduct(vector1,vector2,quantity);
    float norm1 = normUniqueVector(vector1,quantity);
    float norm2 = normUniqueVector(vector2,quantity);
    float degree = (sum/(norm1*norm2));
    float result = acosf(degree);
    double resultDegrees = result*(180/M_PI);
    printf("El angulo entre los vectores es: %.2f radianes\n",result);
    printf("El angulo entre los vectores es: %.2f grados\n",resultDegrees);
}

#endif //VECTORES_POLINOMIOS_VECTORS_FUNCTION_H
