// Durán Rendón Santiago
// 15 de febrero de 2025
// Estructura de Datos y Algoritmos I
// Ejercicio 4 Práctica 1: Preguntar la dimensión de dos matrices si cumplen con las condiciones para multiplicarlas, crear los arreglos, realizar la multiplicación, almacenar el resultado en un tercer arreglo y mostrar dicho resultado.

#include <stdio.h>
#include <stdlib.h> //necesario para el exit.
#define MAX 10 //Tamaño máximo que puede tener las matrices.

int fila_matriz1 = 0, columna_matriz1 = 0;
int  fila_matriz2 = 0, columna_matriz2 = 0;

int matriz1[MAX][MAX];
int matriz2[MAX][MAX];
int matriz_resultado[MAX][MAX];

void dimensiones();
void Ingresar_matrices();
void multiplicacion();
void Imprimir_matriz(int matriz[MAX][MAX], int filas, int columnas);

int main(){
    printf("\nPrograma que a partir de dos matrices, las multiplica y muestra el resultado\n");
    dimensiones();
    Ingresar_matrices();
    multiplicacion();
    Imprimir_matriz(matriz_resultado, fila_matriz1, columna_matriz2);
    
    return 0;
}//main

void dimensiones(){
    printf("\n=====================================================================================================================\n");
    printf("Calculando dimensiones de la matriz...\n");

    printf("\nIngrese el numero de filas de la primera matriz (maximo %d):\n ", MAX);
    scanf("%d", &fila_matriz1);
    printf("Ingrese el numero de columnas de la primera matriz (maximo %d):\n ", MAX);
    scanf("%d", &columna_matriz1);

    printf("Ingrese el numero de filas de la segunda matriz (maximo %d):\n ", MAX);
    scanf("%d", &fila_matriz2);
    printf("Ingrese el numero de columnas de la segunda matriz (maximo %d):\n ", MAX);
    scanf("%d", &columna_matriz2);

    printf("\nDimensiones de la primer matriz: %d x %d\n", fila_matriz1, columna_matriz1);
    printf("Dimensiones de la segunda matriz: %d x %d\n", fila_matriz2, columna_matriz2);

    if (columna_matriz1 == fila_matriz2){
        printf("\nSe puede realizar la multiplicacion ya que son compatibles las matrices\n");
    }/*if*/ else if (columna_matriz1 != fila_matriz2){
        printf("\nNo se puede realizar la multiplicacion ya que no son compatibles las matrices\n");
        exit(0);
    }//else if

    printf("\n=====================================================================================================================\n");
}//void dimensiones

void Ingresar_matrices(){
    printf("\n=====================================================================================================================\n");

    printf("\nIngrese los valores de la primer matriz \n");
    for(int i = 0; i < fila_matriz1; i++){
        for(int j = 0; j < columna_matriz1; j++){
            printf("matriz1[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz1[i][j]);
        }//for
    }//for

    printf("\nIngrese los valores de la segunda matriz \n");
    for(int i = 0; i < fila_matriz2; i++){
        for(int j = 0; j < columna_matriz2; j++){
            printf("matriz2[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz2[i][j]);
        }//for
    }//for

    printf("\n=====================================================================================================================\n");
}//void Ingresar_matrices

void multiplicacion(){
    printf("\n=====================================================================================================================\n");

    printf("\nRealizando multiplicacion...\n");
    for(int i = 0; i < fila_matriz1; i++){
        for(int j = 0; j < columna_matriz2; j++){
            matriz_resultado[i][j] = 0;
            for(int k = 0; k < columna_matriz1; k++){
                matriz_resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }//for
        }//for
    }//for
    
    printf("\n=====================================================================================================================\n");
}//void multiplicacion

void Imprimir_matriz(int matriz[MAX][MAX], int filas, int columnas){
    printf("\n=====================================================================================================================\n");

    printf("\nMatriz resultante\n");
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            printf("%4d", matriz[i][j]); //Se usa el espacio de cuatro números se imprimen para asergurar de que quede alineado a la impresión
        }//for
        printf("\n");
    }//for
    printf("\n=====================================================================================================================\n");
}//void