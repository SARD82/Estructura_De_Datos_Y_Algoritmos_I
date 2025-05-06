/*Santiago Duran Rendon.
Estrada Tsubaki Lea Artemisa. 
Garduño Bautista Rodrigo.
Miranda Sanchez Luis Eduardo.
García Jiménez Joel David.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int semilla = 0;

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

int numeroAleatorio(int min, int max) {
    semilla++;
    return min + (semilla % (max - min + 1));
}

void delaySimple(int iteraciones) {
    for(int i = 0; i < iteraciones; i++) {
        //Bucle vacío para crear delay
    }
}

void girarRuleta(Nodo* cabeza) {
    int pasos = numeroAleatorio(15, 150);
    Nodo* actual = cabeza;
    
    printf("\nGirando la ruleta...\n");
    
    for (int i = 0; i < pasos; i++) {
        printf("\033[2J\033[H"); //Código ANSI para limpiar pantalla
        printf("\nPremio actual: %s\n", actual->premio);
        
        // Calcular delay basado en la posición
        int delay_iter = 10000 + (i * 1000); //Aumenta el delay a medida que avanza
        delaySimple(delay_iter);
        
        actual = actual->siguiente;
    }
    
    printf("\n¡Premio final: %s!\n", actual->premio);
}

int main() {
    Nodo* cabeza = NULL;
    char respuesta[3];
    
    // Inicializar la ruleta
    inicializarRuleta(&cabeza);
    
    do {
        printf("\n¿Desea girar la ruleta? (SI/NO): ");
        scanf("%s", respuesta);
        
        if (strcmp(respuesta, "SI") == 0) {
            girarRuleta(cabeza);
        }
    } while (strcmp(respuesta, "NO") != 0);
    
    Nodo* actual = cabeza;
    Nodo* siguiente;
    do {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    } while (actual != cabeza);
    
    return 0;
}
