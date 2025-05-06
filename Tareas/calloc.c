#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)calloc(5, sizeof(int)); // Reservar memoria para 5 enteros
    if (ptr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]); // Todos los valores están inicializados en 0
    }

    free(ptr); // Liberamos la memoria
    return 0;
}