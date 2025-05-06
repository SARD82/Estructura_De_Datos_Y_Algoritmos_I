#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Disco {
    int tamano;
    char color[20];
    struct Disco *siguiente;
} Disco;

typedef struct Pila {
    Disco *tope;
    char nombre[10];
} Pila;

// Función para inicializar una pila
void inicializarPila(Pila *pila, const char *nombre) {
    pila->tope = NULL;
    strcpy(pila->nombre, nombre);
}

// Función para apilar (push) un disco
int push(Pila *pila, int tamano, const char *color) {
    if (pila->tope != NULL && pila->tope->tamano <= tamano) {
        printf("Movimiento inválido: Un disco mayor no puede ir sobre uno menor.\n");
        return 0;
    }

    Disco *nuevoDisco = (Disco *)malloc(sizeof(Disco));
    if (!nuevoDisco) {
        printf("Error de memoria.\n");
        return 0;
    }

    nuevoDisco->tamano = tamano;
    strcpy(nuevoDisco->color, color);
    nuevoDisco->siguiente = pila->tope;
    pila->tope = nuevoDisco;
    return 1;
}

// Función para desapilar (pop) un disco
Disco *pop(Pila *pila) {
    if (pila->tope == NULL) {
        printf("Pila vacía.\n");
        return NULL;
    }
    
    Disco *discoRemovido = pila->tope;
    pila->tope = pila->tope->siguiente;
    return discoRemovido;
}

// Función para mostrar el estado de las pilas
void mostrarPila(Pila *pila) {
    printf("%s: ", pila->nombre);
    Disco *actual = pila->tope;
    while (actual) {
        printf("[%d, %s] ", actual->tamano, actual->color);
        actual = actual->siguiente;
    }
    printf("\n");
}

void mostrarPilas(Pila *p1, Pila *p2, Pila *p3) {
    mostrarPila(p1);
    mostrarPila(p2);
    mostrarPila(p3);
    printf("--------------------------------\n");
}

// Función para mover un disco entre pilas
void moverDisco(Pila *origen, Pila *destino) {
    if (origen->tope == NULL) {
        printf("No hay discos en %s para mover.\n", origen->nombre);
        return;
    }
    if (destino->tope != NULL && destino->tope->tamano <= origen->tope->tamano) {
        printf("Movimiento inválido: No se puede mover un disco mayor sobre uno menor.\n");
        return;
    }
    
    Disco *movido = pop(origen);
    push(destino, movido->tamano, movido->color);
    printf("Moviendo disco [%d, %s] de %s a %s\n", movido->tamano, movido->color, origen->nombre, destino->nombre);
    free(movido);
}

int main() {
    Pila poste1, poste2, poste3;
    inicializarPila(&poste1, "Poste 1");
    inicializarPila(&poste2, "Poste 2");
    inicializarPila(&poste3, "Poste 3");

    // Insertar discos en el poste 1
    push(&poste1, 6, "Rojo");
    push(&poste1, 5, "Azul");
    push(&poste1, 4, "Verde");
    push(&poste1, 3, "Amarillo");
    push(&poste1, 2, "Naranja");
    push(&poste1, 1, "Morado");

    mostrarPilas(&poste1, &poste2, &poste3);

    // Solicitar movimientos al usuario
    int origen, destino;
    while (1) {
        printf("Ingrese el número del poste de origen y destino (1-3) o 0 0 para salir: ");
        scanf("%d %d", &origen, &destino);
        
        if (origen == 0 && destino == 0) break;
        
        Pila *pilaOrigen = (origen == 1) ? &poste1 : (origen == 2) ? &poste2 : &poste3;
        Pila *pilaDestino = (destino == 1) ? &poste1 : (destino == 2) ? &poste2 : &poste3;
        
        moverDisco(pilaOrigen, pilaDestino);
        mostrarPilas(&poste1, &poste2, &poste3);
    }

    return 0;
}