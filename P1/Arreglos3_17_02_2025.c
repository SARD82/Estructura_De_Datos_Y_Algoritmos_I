//Durán Rendón Santiago
//18_02_2025
//Estructura de Datos y Algoritmos I
//Tarea - Imprimir con apuntadores un arreglo de 3 dimensiones
#include <stdio.h>

int main(){
    //Declarar arreglo tridimensional
    int array_tridimensional[4][3][3] = {
        {{1, 9, 2}, {0, -4, 8}, {10, 100, -56}}, // =9
        {{12, 34, 55}, {24, 12, 43}, {-10, -58, -98}}, // =18
        {{82, 90, 23}, {20, -19, 89}, {-89, -90, -23}}, // =27
        {{1, 9, 2}, {0, -4, 8}, {10, 100, -56}} // =36
    }; //Filas, Columnas, Profundidad.

    //Declarar apuntador
    int *ap;

    //Declarar a que apunta el apuntador
    ap = &array_tridimensional[0][0][0]; //Obtiene la dirección de memoria del primer elemento del arreglo tridimensional.
    //ap = array_tridimensional[0][0][0]; //Obtiene el valor del primer elemento del arreglo tridimensional.

    printf("Arreglos con apuntadores\n");

    //Como Recorrer La Matriz.
    for(int f = 0; f < 4; f++){ //Recorre las filas.
        for(int c = 0; c < 3; c++){ //Recorre las columnas.
            for(int p = 0; p < 3; p++){ //Recorre la profundidad.
                printf("%d ", array_tridimensional[f][c][p]);
            }//for
            printf("\n");
        }//for
        printf("\n\n");
    }//for

    printf("\n=======================================\n");

    //Como Recorrer La Matriz Usando Formula.
    for(int f = 0; f < 4; f++){ //Recorre las filas.
        for(int c = 0; c < 3; c++){ //Recorre las columnas.
            for(int p = 0; p < 3; p++){ //Recorre la profundidad.
                printf("%d ", *(ap + (f * 3 * 3) + (c * 3) + p)); //(fila actual * número de columnas * número de profundidad) + (columna actual * número de profundidad) + profundidad actual.
            }//for
            printf("\n");
        }//for
        printf("\n\n");
    }//for

    return 0;
}//main