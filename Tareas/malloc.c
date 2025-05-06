#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(5 * sizeof(int)); // Reservar memoria para 5 enteros
    if (ptr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        ptr[i] = i + 1; // Inicializamos los valores manualmente
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }

    free(ptr); // Liberamos la memoria
    return 0;
}