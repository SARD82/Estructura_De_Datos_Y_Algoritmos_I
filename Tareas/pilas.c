/*APUNTE

basicamente se van apilando los nodos arriba de todo, el tope es la parte de hasta rriba y la liga la parte de abajo de cada nodo.
struct nodo {
    char valor;
    struct nodo *liga;

    MALLOC
    reserva memoria, hay que decirle cuantos bytes?
};
*/
#include <stdio.h>
#include <stdlib.h>

struct nodo{
    char valor;
    struct nodo *liga;

};

struct nodo *tope = NULL; //crear el tope, este no es un nodo. es el tope.

void apilar(char v){
    struct nodo *nuevo;
    nuevo = (struct nodo *)malloc(sizeof(struct nodo)); //malloc = nos da la dirección de memoria y se guarda en un apuntador, sizeof (devuelve cuantos bytes tiene la variable).
    (*nuevo).valor = v;
    (*nuevo).liga = tope;

    tope = nuevo;
}//void

void desapilar(){
    struct nodo *b;
    b = tope;
    tope = (*tope).liga;
    printf("\nBorrando en nodo %c: \n", (*b).valor);
    free (b);
}//void

void imprimir_pila(){
    printf("\n");
    struct nodo *p;
    p = tope;
    while(p != NULL){
        printf("%c", (*p).valor);
        printf("\n");
        p = (*p).liga;

    }//while
}//void

int main(){

    printf("\nPilas\n");
    
    //Primer nodo
    struct nodo n1;
    n1.valor = 'c';
    n1.liga = NULL;

    tope = &n1;

    //Segundo nodo.
    struct nodo n2;
    n2.valor = 'x';
    n2.liga = tope;// tope ya que es el que esta hasta arriba.
    tope = &n2;

    //tercer nodo.
    struct nodo p5;
    p5.valor = 's';
    p5.liga = tope; // tope es el de hasta arriba, por ello se asigna su dirección de memoria de tope.
    tope = &p5;// ahora tope tiene que ser el de hasta ariiba, para ello asignamos el valor de dirección de memoria a el nuevo que acaba de ingresar.mal y me lo

    //Nodo dinámico.
    struct nodo *nuevo;
    nuevo = (struct nodo *)malloc(sizeof(struct nodo)); //malloc = nos da la dirección de memoria y se guarda en un apuntador, sizeof = devuelve cuantos bytes tiene la variable.
    (*nuevo).valor = 'g';
    (*nuevo).liga = tope;

    tope = nuevo;

    //nodo dinamico 2.   
    nuevo = (struct nodo *)malloc(sizeof(struct nodo)); //malloc = nos da la dirección de memoria y se guarda en un apuntador, sizeof (devuelve cuantos bytes tiene la variable).
    (*nuevo).valor = 'm';
    (*nuevo).liga = tope;

    tope = nuevo;

    //nodo dinamico 3.
    apilar('f');
    apilar('o');
    apilar('d');


    struct nodo *p;
    p = tope;
    while(p != NULL){
        printf("%c", (*p).valor);
        printf("\n");
        p = (*p).liga;

    }//while

    printf("\n");
    void desapilar();

    p = tope;
    while(p != NULL){
        printf("%c", (*p).valor);
        printf("\n");
        p = (*p).liga;
    }//while

    imprimir_pila();
    desapilar();
    desapilar;
    imprimir_pila;

    return 0;

}//main