// Durán Rendón Santiago.
// 15 de febrero de 2025.
// Estructura de Datos y Algoritmos I.
// Ejercicio 2 Práctica 1: Generar 100 números aleatorios y almacenar los pares en un arreglo y los impares en otro arreglo.

#include <stdio.h>
#include <stdlib.h> //para poder usar rand.

void aleatorios();

int main(){

    printf("\nPrograma que genera 100 numeros aleatorios y los almacena en un arreglo de pares y uno de impares\n");

    aleatorios();

    return 0;
}//main

void aleatorios(){

    int n_aleatorio, indice_par = 0, indice_impar = 0;
    int pares[101], impares[101];

    printf("\n============================================================\n");
    printf("Generando numeros aleatorios...\n");

    printf("\n============================================================\n");
    printf("Almacenando numeros aleatorios...\n");

    for(int i = 0; i < 100; i++){

        n_aleatorio = rand() % 100; //para generar aleatorios del 0 al 100.
        printf("numero aleatorio %d aleatorio = %d\n", i + 1, n_aleatorio);

        if((n_aleatorio % 2) == 0){
            pares[indice_par] = n_aleatorio;
            indice_par++;
        }/*if*/ else if((n_aleatorio % 2) != 0){
            impares[indice_impar] = n_aleatorio;
            indice_impar++;
        }//else if
    }//for
    
    printf("\n============================================================\n");
    printf("Imprimiendo arreglos...\n");

    printf("Arreglo de pares: ");
    for(int i = 0; i < indice_par; i++){ //Esta fórmula obtiene el tamaño total del arreglo en bytes y lo divide entre el tamaño de un solo elemento lo que da la cantidad de elementos en el arreglo.

        printf("%d ", pares[i]);
    }//for
    
    printf("\nArreglo de impares: ");
    for(int i = 0; i < indice_impar; i++){

        printf("%d ", impares[i]);
    }//for

}//void