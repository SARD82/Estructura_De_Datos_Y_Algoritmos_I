// Durán Rendón Santiago

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

Nodo* tope = NULL;

int estaVacia() {
    return tope == NULL;
}

void push(int valor) {
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return;
    }
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = tope;
    tope = nuevoNodo;
    printf("Se insertó %d en la pila.\n", valor);
}

int pop() {
    if (estaVacia()) {
        printf("La pila está vacía. No se puede hacer pop.\n");
        return -1;
    }
    Nodo* nodoAEliminar = tope;
    int valor = nodoAEliminar->valor;
    tope = tope->siguiente;
    free(nodoAEliminar);
    printf("Se eliminó %d de la pila.\n", valor);
    return valor;
}

void mostrar() {
    if (estaVacia()) {
        printf("La pila está vacía.\n");
        return;
    }
    Nodo* actual = tope;
    printf("Elementos de la pila (tope a base):\n");
    while (actual != NULL) {
        printf("%d\n", actual->valor);
        actual = actual->siguiente;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    mostrar();

    pop();
    mostrar();

    pop();
    pop();
    pop(); //pop cuando ya esta vacia

    return 0;
}
