/* Codigo
Estrada Tsubaki Lea Artemisa 
Garduño Bautista Rodrigo
Durán Rendón Santiago
Miranda Sanchez Luis Edaurdo
García Jiménez Joel David*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estructura para el nodo de la lista doblemente ligada
struct Nodo {
    int valor;
    struct Nodo* siguiente;
    struct Nodo* anterior;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->valor = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

// Función para imprimir la lista
void imprimirLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d ", actual->valor);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función para intercambiar dos nodos
void intercambiarNodos(struct Nodo* nodo1, struct Nodo* nodo2) {
    int temp = nodo1->valor;
    nodo1->valor = nodo2->valor;
    nodo2->valor = temp;
}

// Función para ordenar la lista usando Bubble Sort
void bubbleSort(struct Nodo* cabeza) {
    int intercambiado;
    struct Nodo* ptr1;
    struct Nodo* lptr = NULL;
    
    if (cabeza == NULL)
        return;

    do {
        intercambiado = 0;
        ptr1 = cabeza;

        while (ptr1->siguiente != lptr) {
            if (ptr1->valor > ptr1->siguiente->valor) {
                intercambiarNodos(ptr1, ptr1->siguiente);
                intercambiado = 1;
            }
            ptr1 = ptr1->siguiente;
        }
        lptr = ptr1;
    } while (intercambiado);
}

int main() {
    // Inicializar generador de números aleatorios
    srand(time(NULL));
    
    // Crear la lista con 30 nodos
    struct Nodo* cabeza = crearNodo(rand() % 100 + 1);
    struct Nodo* actual = cabeza;
    
    // Generar los 29 nodos restantes
    for (int i = 1; i < 30; i++) {
        struct Nodo* nuevo = crearNodo(rand() % 100 + 1);
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
        actual = nuevo;
    }
    
    // Imprimir lista original
    printf("Lista original:\n");
    imprimirLista(cabeza);
    
    // Ordenar la lista
    bubbleSort(cabeza);
    
    // Imprimir lista ordenada
    printf("\nLista ordenada:\n");
    imprimirLista(cabeza);
    
    // Liberar memoria
    actual = cabeza;
    while (actual != NULL) {
        struct Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    
    return 0;
}