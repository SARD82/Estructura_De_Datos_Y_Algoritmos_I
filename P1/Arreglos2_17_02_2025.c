#include <stdio.h>

int main(){
    //Declarar matriz
    int matriz[4][3] = {{1, 9, 2}, {0, -4, 8}, {10, 100, -56}, {12, 34, 55}};

    //Declarar apuntador
    int *ap;

    //Declarar a que apunta el apuntador
    ap = &matriz[0][0]; //Obtiene la dirección de memoria del primer elemento de la matriz.
    /*ap = matriz[0][0];*/ //Obtiene el valor del primer elemento de la matriz.

    printf("Arreglos con apuntadores\n");

    //Como Recorrer La Matriz.
    for(int f = 0; f < 4; f++){ //Recorre las filas.
        for(int c = 0; c < 3; c++){ //Recorre las columnas.
            printf("%d ", matriz[f][c]);
        }//for
        printf("\n"); //Salto entre cada fila de la matriz.
    }//for

    printf("\n");

    //Recorrer La Matriz Usando Formula.
    for(int f = 0; f < 4; f++){ //Recorre las filas.
        for(int c = 0; c < 3; c++){ //Recorre las columnas.
            printf("%d ", *(ap + (f * 3) + c)); //(fila actual * número de columnas) + columna actual.
        }//for
        printf("\n"); //Salto entre cada fila de la matriz.
    }//for

    printf("\n");

    //Otra Forma De Recorrer La Matriz.
    int filas = 4, columnas = 3;
    for(int i = 0; i < 12; i++){ //Recorre La Matriz, 12 = 4 filas * 3 columnas.
        printf("%d ", *(ap + i)); //Recorre toda la matriz de forma que se encuentra en la RAM.
        if((i + 1) % (columnas) == 0){ //if para hacer el salto de línea entre fila y fila.
            printf("\n"); 
        }//if
    }//for

    return 0;
}//main