#include <stdio.h>

int main(){
    //Declarar arreglo
    int arreglo[20] = {1, 9, 2, 0, -4, 8, 10, 100, -56, 12, 34, 55, 90, 70, 28, 21, 76, 45, 30 ,50};

    //Declarar apuntador
    int *ap;

    //Declarar a que apunta el apuntador
    ap = &arreglo[0]; //Obtiene la dirección de memoria del primer elemento del arreglo.
    /*ap = arreglo[0];*/ //Obtiene el valor del primer elemento del arreglo.

    printf("Arreglo con apuntadores\n");

    //Como Recorrer El Arreglo
    for(int i = 0; i < 20; i++){
        printf("%d ", arreglo[i]);
        //arreglo imprime la dirección de memoria.
        //* da el contenido de la dirección de memoria de arreglo.
    }//for

    printf("\n");

    //Como Recorrer El Arrefglo Usando ap
    for(int i = 0; i < 20; i++){
        printf("%d ", *(ap + i));
        //ap imprime la dirección de memoria de arreglo.
        //* da el contenido de la dirección de memoria de ap.
    }//for

    return 0;
}//main