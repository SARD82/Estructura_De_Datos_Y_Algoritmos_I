#include <stdio.h>

int main(){

    int X[6][5] = {
        {0,1,2,3,4}, 
        {6,7,8,9,10}, 
        {11,12,13,14,15}, 
        {16,17,18,19,20}, 
        {21,22,23,24,25}, 
        {0,1,2,3,4}
    };

    int *p = &X[0][0];
    int total = 6 * 5;
    
    //Inmprimir direcciones de memoria de x en forma lexicográfico.
    printf("\nDirecciones de memoria: ");
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            printf("\nDirecci%cn de memoria X[%d][%d]: %x", 162, i, j, (void *)&X[i][j]); //%x para hexadecimal y (void *) -> es un puntero generico para evitar advertencias
        }//for    
    }//for

    printf("\n\n=========================================================\n");

    //Inmprimir los elementos de un arreglo.
    printf("\nElementos del arreglo en orden lexicogr%cfico", 160);
    for(int i = 0; i < total; i++){
        printf("\nElemento %d: %d", i, *(p + i));
    }//for
    return 0;
}//main