#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(5 * sizeof(int)); // Reservar memoria
    if (ptr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    free(ptr); // Liberar memoria
    ptr = NULL; // Buena práctica: apuntar a NULL tras liberar
    return 0;
}