/*Santiago Durán Rendón*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct persona{
    char nombre[20];
    struct persona * siguiente;
    struct persona * anterior;
};

struct persona * head;
struct persona * tail;

void encolar(char nom[]){
    struct persona * nuevo;

    nuevo = (struct persona *) malloc(sizeof(struct persona));
    strcpy((*nuevo).nombre, nom);
    (*nuevo).siguiente = NULL;
    (*nuevo).anterior = NULL;
    
    if(head == NULL){
        head = nuevo;
    }
    
    if(tail != NULL){
        (*tail).siguiente = nuevo;
        (*nuevo).anterior = tail;
    }
    tail = nuevo;
}

void imprimir_cola_ascendente(){
   struct persona * ap;
   
   ap = head;
   
   printf("\nOrden ascendente:");
   while(ap != NULL){
       printf(" %s ->", (*ap).nombre);
       ap = (*ap).siguiente;
   }
   printf(" NULL\n");
}

void imprimir_cola_descendente(){
    struct persona * ap;
    
    ap = tail;
    
    printf("\nOrden descendente:");
    while(ap != NULL){
        printf(" %s ->", (*ap).nombre);
        ap = (*ap).anterior;
    }
    printf(" NULL\n");
}

int contar_nodos(){
    struct persona * ap;
    int contador = 0;
    
    ap = head;
    while(ap != NULL){
        contador++;
        ap = (*ap).siguiente;
    }
    return contador;
}

void desencolar(){
    struct persona * ap;

    if(head != NULL){
        ap = head;
        head = (*head).siguiente;
        
        if(head != NULL){
            (*head).anterior = NULL;
        } else {
            tail = NULL;
        }
        
        printf("\nEstamos atendiendo a %s \n", (*ap).nombre);
        
        free(ap);
    }    
}

int main()
{
    struct persona * nuevo;
    head = NULL;
    tail = NULL;
    
    printf("Cola Doblemente Ligada\n");
    
    encolar("Luisa");
    encolar("Juan");
    encolar("Ana");
    encolar("Arturo");    
    encolar("Elizabeth");
    
    printf("\nNúmero de nodos en la cola: %d", contar_nodos());
    
    imprimir_cola_ascendente();
    imprimir_cola_descendente();
    
    desencolar();
    
    printf("\nDespués de desencolar:");
    imprimir_cola_ascendente();
    imprimir_cola_descendente();
    
    printf("\nNúmero de nodos en la cola: %d\n", contar_nodos());
    
    return 0;
}