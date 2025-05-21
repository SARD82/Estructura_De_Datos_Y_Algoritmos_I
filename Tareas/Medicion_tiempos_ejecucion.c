#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio, fin;
    double tiempo;

    inicio = clock();
    // Código a medir
    fin = clock();

    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", tiempo);
    return 0;
}