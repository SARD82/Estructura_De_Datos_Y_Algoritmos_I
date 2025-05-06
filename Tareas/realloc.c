#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(3 * sizeof(int)); // Reservar memoria para 3 enteros
    if (ptr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        ptr[i] = i + 1; // Inicializamos valores
    }

    // Redimensionar para almacenar 5 enteros
    ptr = (int *)realloc(ptr, 5 * sizeof(int));
    if (ptr == NULL) {
        printf("Error al redimensionar memoria.\n");
        return 1;
    }

    // Asignar valores a las nuevas posiciones
    for (int i = 3; i < 5; i++) {
        ptr[i] = i + 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }

    free(ptr); // Liberar memoria
    return 0;
}