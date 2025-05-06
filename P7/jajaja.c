/*Santiago Duran Rendon, Miranda Sanche  z Luis */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Nodo {
    char premio[50];
    struct Nodo* siguiente;
} Nodo;


Nodo* crearNodo(const char* premio) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuevo->premio, premio);
    nuevo->siguiente = NULL;
    return nuevo;
}

void insertarNodo(Nodo** cabeza, const char* premio) {
    Nodo* nuevo = crearNodo(premio);
    
    if (*cabeza == NULL) {
        *cabeza = nuevo;
        nuevo->siguiente = nuevo;
    } else {
        Nodo* actual = *cabeza;
        while (actual->siguiente != *cabeza) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
        nuevo->siguiente = *cabeza;
    }
}

void inicializarRuleta(Nodo** cabeza) {
    insertarNodo(cabeza, "¡$20,000!");
    insertarNodo(cabeza, "¡$10,000!");
    insertarNodo(cabeza, "¡$5,000!");
    insertarNodo(cabeza, "¡$2,500!");
    insertarNodo(cabeza, "¡$1,000!");
    insertarNodo(cabeza, "¡$500!");
    insertarNodo(cabeza, "¡$250!");
    insertarNodo(cabeza, "¡$100!");
    insertarNodo(cabeza, "¡$50!");
    insertarNodo(cabeza, "¡$25!");
}