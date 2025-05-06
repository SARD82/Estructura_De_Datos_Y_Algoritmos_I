#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Canal {
    char nombre[50];
    int numero;
} Canal;


typedef struct Nodo {
    Canal canal;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;


typedef struct Television {
    Nodo* primero;
    Nodo* ultimo;
    Nodo* actual;
    Nodo* anterior_salto;
    int total_canales;
} Television;


Television* crearTelevision() {
    Television* tv = (Television*)malloc(sizeof(Television));
    tv->primero = NULL;
    tv->ultimo = NULL;
    tv->actual = NULL;
    tv->anterior_salto = NULL;
    tv->total_canales = 0;
    return tv;
}


void agregarCanal(Television* tv, char* nombre, int numero) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuevo->canal.nombre, nombre);
    nuevo->canal.numero = numero;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    if (tv->primero == NULL) {
        tv->primero = nuevo;
        tv->ultimo = nuevo;
        tv->actual = nuevo;
    } else {
        nuevo->anterior = tv->ultimo;
        tv->ultimo->siguiente = nuevo;
        tv->ultimo = nuevo;
    }
    tv->total_canales++;
}


void siguienteCanal(Television* tv) {
    if (tv->actual != NULL) {
        tv->anterior_salto = NULL; 
        if (tv->actual->siguiente != NULL) {
            tv->actual = tv->actual->siguiente;
        } else {
            tv->actual = tv->primero;
        }
    }
}


void anteriorCanal(Television* tv) {
    if (tv->actual != NULL) {
        if (tv->anterior_salto != NULL) { 
            tv->actual = tv->anterior_salto;
            tv->anterior_salto = NULL;
            return;
        }
        if (tv->actual->anterior != NULL) {
            tv->actual = tv->actual->anterior;
        } else {
            tv->actual = tv->ultimo;
        }
    }
}




void mostrarCanalActual(Television* tv) {
    if (tv->actual != NULL) {
        printf("\nCanal Actual: %s (Número %d)\n", 
               tv->actual->canal.nombre, 
               tv->actual->canal.numero);
    } else {
        printf("\nNo hay canales disponibles\n");
    }
}

int main() {
    Television* tv = crearTelevision();
    char opcion;

    agregarCanal(tv, "Azteca Novelas", 1);
    agregarCanal(tv, "Noticias con Chumel", 2);
    agregarCanal(tv, "HBO", 3);
    agregarCanal(tv, "TUDN", 4);
    agregarCanal(tv, "Cartoon Network", 5);

    do {
        mostrarCanalActual(tv);
        printf("\nOpciones:\n");
        printf("1. Siguiente canal\n");
        printf("2. Anterior canal\n");;
        printf("s. Salir\n");
        printf("Seleccione una opción: ");
        scanf(" %c", &opcion);

        switch(opcion) {
            case '1':
                siguienteCanal(tv);
                break;
            case '2':
                anteriorCanal(tv);
                break;
            case '3':
                printf("Ingrese el número del canal: ");
                int numero;
                scanf("%d", &numero);
                break;
            case 's':
            case 'S':
                printf("Apagando televisión...\n");
                break;
            default:
                printf("Opción no válida\n");
        }

    } while (opcion != 's' && opcion != 'S');

    Nodo* actual = tv->primero;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    free(tv);

    return 0;
}