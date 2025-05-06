/******************************************************************************

 Concurso Pilas y Colas
 Estrada Tsubaki Lea Artemisa
 Duràn Rendòn Santiago

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREAS 100
#define MAX_DESC 50


typedef struct {
    char descripcion[MAX_DESC];
    char tipo; 
} Tarea;


typedef struct {
    Tarea tareas[MAX_TAREAS];
    int tope;
} Pila;


typedef struct {
    Tarea tareas[MAX_TAREAS];
    int frente;
    int final;
} Cola;


void inicializarPila(Pila* p) {
    p->tope = -1;
}

void inicializarCola(Cola* c) {
    c->frente = 0;
    c->final = -1;
}


int pilaVacia(Pila* p) {
    return p->tope == -1;
}

void push(Pila* p, char* desc) {
    if (p->tope < MAX_TAREAS - 1) {
        p->tope++;
        strcpy(p->tareas[p->tope].descripcion, desc);
        p->tareas[p->tope].tipo = 'U';
        printf("Tarea urgente agregada: %s\n", desc);
    } else {
        printf("Error: Pila de urgentes llena\n");
    }
}

Tarea pop(Pila* p) {
    Tarea t;
    if (!pilaVacia(p)) {
        t = p->tareas[p->tope];
        p->tope--;
        return t;
    }
    strcpy(t.descripcion, "VACIO");
    return t;
}


int colaVacia(Cola* c) {
    return c->final < c->frente;
}

void encolar(Cola* c, char* desc) {
    if (c->final < MAX_TAREAS - 1) {
        c->final++;
        strcpy(c->tareas[c->final].descripcion, desc);
        c->tareas[c->final].tipo = 'R';
        printf("Tarea rutinaria agregada: %s\n", desc);
    } else {
        printf("Error: Cola de rutinarias llena\n");
    }
}

Tarea desencolar(Cola* c) {
    Tarea t;
    if (!colaVacia(c)) {
        t = c->tareas[c->frente];
        c->frente++;
        return t;
    }
    strcpy(t.descripcion, "VACIO");
    return t;
}


void mostrarTareas(Pila* p, Cola* c) {
    printf("\nTareas urgentes pendientes:\n");
    if (pilaVacia(p)) {
        printf("Ninguna\n");
    } else {
        for (int i = p->tope; i >= 0; i--) {
            printf("- %s\n", p->tareas[i].descripcion);
        }
    }
    
    printf("\nTareas rutinarias pendientes:\n");
    if (colaVacia(c)) {
        printf("Ninguna\n");
    } else {
        for (int i = c->frente; i <= c->final; i++) {
            printf("- %s\n", c->tareas[i].descripcion);
        }
    }
    printf("\n");
}


void combinarSiNecesario(Pila* p, Cola* c) {
    if (p->tope >= 5 && !colaVacia(c)) {
        Tarea t = desencolar(c);
        push(p, t.descripcion);
        printf("Tarea rutinaria '%s' convertida a urgente\n", t.descripcion);
    }
}

int main() {
    Pila urgentes;
    Cola rutinarias;
    inicializarPila(&urgentes);
    inicializarCola(&rutinarias);
    
    int opcion;
    char descripcion[MAX_DESC];
    
    do {
        printf("\nHospital de la FI\n");
        printf("Sistema de gestiòn de tareas\n");
        printf("\n1. Agregar tarea urgente\n");
        printf("2. Agregar tarea rutinaria\n");
        printf("3. Atender tarea\n");
        printf("4. Mostrar tareas pendientes\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar();
        
        switch (opcion) {
            case 1:
                printf("Descripcion de la tarea urgente: ");
                fgets(descripcion, MAX_DESC, stdin);
                descripcion[strcspn(descripcion, "\n")] = 0;
                push(&urgentes, descripcion);
                break;
                
            case 2:
                printf("Descripcion de la tarea rutinaria: ");
                fgets(descripcion, MAX_DESC, stdin);
                descripcion[strcspn(descripcion, "\n")] = 0;
                encolar(&rutinarias, descripcion);
                break;
                
            case 3:
                if (!pilaVacia(&urgentes)) {
                    Tarea t = pop(&urgentes);
                    printf("Tarea urgente atendida: %s\n", t.descripcion);
                } else if (!colaVacia(&rutinarias)) {
                    Tarea t = desencolar(&rutinarias);
                    printf("Tarea rutinaria atendida: %s\n", t.descripcion);
                } else {
                    printf("Error: No hay tareas pendientes\n");
                }
                combinarSiNecesario(&urgentes, &rutinarias);
                break;
                
            case 4:
                mostrarTareas(&urgentes, &rutinarias);
                break;
                
            case 5:
                printf("Saliendo...\n");
                break;
                
            default:
                printf("Opcion invalida\n");
        }
    } while (opcion != 5);
    
    return 0;
}