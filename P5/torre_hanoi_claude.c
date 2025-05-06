//Durán Rendón Santiago

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

// Estructura para representar un disco en la pila
typedef struct Disco {
    int tamaño;             // Tamaño del disco
    char color[MAX];         // Color del disco
    struct Disco* siguiente; // Puntero al siguiente disco
} Disco;

// Estructura para representar una torre (pila)
typedef struct {
    Disco* tope;    // Puntero al disco superior
    char nombre;    // Nombre de la torre (A, B, C)
} Torre;

// Prototipos de funciones
Disco* crearDisco(int tamaño, const char* color);
void push(Torre* torre, int tamaño, const char* color);
Disco* pop(Torre* torre);
void inicializarTorre(Torre* torre, char nombre);
int estaVacia(Torre* torre);
void mostrarTorre(Torre torre);
void mostrarTorres(Torre* torreA, Torre* torreB, Torre* torreC);

// Función para crear un nuevo disco
Disco* crearDisco(int tamaño, const char* color) {
    // Reservamos memoria para el nuevo disco
    Disco* nuevoDisco = (Disco*)malloc(sizeof(Disco));
    
    // Verificamos si se pudo reservar memoria
    if (nuevoDisco == NULL) {
        printf("\nError: No se pudo reservar memoria para el disco\n");
        return NULL;
    }
    
    // Inicializamos los valores del disco
    nuevoDisco->tamaño = tamaño;
    strncpy(nuevoDisco->color, color, MAX - 1);  // Copiamos el color de forma segura
    nuevoDisco->color[MAX - 1] = '\0';           // Nos aseguramos de que termine en null
    nuevoDisco->siguiente = NULL;                // El disco nuevo no apunta a ningún otro
    
    return nuevoDisco;
}

// Función para inicializar una torre
void inicializarTorre(Torre* torre, char nombre) {
    torre->tope = NULL;     // La torre comienza sin discos
    torre->nombre = nombre; // Asignamos el nombre de la torre (A, B o C)
}

// Función para verificar si una torre está vacía
int estaVacia(Torre* torre) {

    return (torre->tope == NULL);
}

// Función para agregar un disco a una torre
void push(Torre* torre, int tamaño, const char* color) {
    // Primero verificamos si podemos colocar el disco
    // (el disco nuevo debe ser más pequeño que el que está en el tope)
    if (!estaVacia(torre) && torre->tope->tamaño < tamaño) {
        printf("\nError: No se puede colocar un disco más grande sobre uno más pequeño\n");
        return;
    }
    
    // Creamos el nuevo disco
    Disco* nuevoDisco = crearDisco(tamaño, color);
    if (nuevoDisco == NULL) {
        return; // Si hubo error al crear el disco, terminamos
    }
    
    // Conectamos el nuevo disco a la torre
    nuevoDisco->siguiente = torre->tope;  // El nuevo disco apunta al que estaba en el tope
    torre->tope = nuevoDisco;            // El nuevo disco se convierte en el tope
    
    printf("\nSe colocó un disco de tamaño %d y color %s en la torre %c\n", 
           tamaño, color, torre->nombre);
}

// Función para quitar y devolver el disco del tope de una torre
Disco* pop(Torre* torre) {
    // Verificamos si la torre está vacía
    if (estaVacia(torre)) {
        printf("\nError: No se puede quitar un disco de una torre vacía\n");
        return NULL;
    }
    
    // Guardamos el disco que vamos a quitar
    Disco* discoQuitado = torre->tope;
    
    // El tope ahora apunta al siguiente disco
    torre->tope = torre->tope->siguiente;
    
    // El disco quitado ya no apunta a ningún otro
    discoQuitado->siguiente = NULL;
    
    printf("\nSe quitó un disco de tamaño %d y color %s de la torre %c\n", 
           discoQuitado->tamaño, discoQuitado->color, torre->nombre);
    
    return discoQuitado;
}

// Función para mostrar el estado de una torre
void mostrarTorre(Torre torre) {
    printf("\nTorre %c:", torre.nombre);
    
    if (estaVacia(&torre)) {
        printf("\n   (vacía)\n");
        return;
    }
    
    printf("\n");
    Disco* actual = torre.tope;
    int nivel = 0;
    
    // Primero contamos cuántos discos hay para poder alinearlos bien
    Disco* temp = torre.tope;
    int totalDiscos = 0;
    while (temp != NULL) {
        totalDiscos++;
        temp = temp->siguiente;
    }
    
    // Mostramos los discos
    while (actual != NULL) {
        // Imprimimos espacios para alinear los discos
        for (int i = 0; i < nivel; i++) {
            printf("   ");
        }
        
        // Imprimimos el disco con su tamaño y color
        printf("   |");
        for (int i = 0; i < actual->tamaño; i++) {
            printf("=");
        }
        printf("| (%s)\n", actual->color);
        
        actual = actual->siguiente;
        nivel++;
    }
    
    // Imprimimos la base de la torre
    printf("   ");
    for (int i = 0; i < totalDiscos; i++) {
        printf("   ");
    }
    printf("===\n");
}

// Función para mostrar todas las torres
void mostrarTorres(Torre* torreA, Torre* torreB, Torre* torreC) {
    mostrarTorre(*torreA);
    mostrarTorre(*torreB);
    mostrarTorre(*torreC);
}

int main() {
    Torre torreA, torreB, torreC;
    int opcion, tamaño;
    char origen, destino;
    char color[MAX];
    
    // Inicializamos las torres
    inicializarTorre(&torreA, 'A');
    inicializarTorre(&torreB, 'B');
    inicializarTorre(&torreC, 'C');
    
    // Colocamos los discos iniciales en la torre A
    push(&torreA, 3, "azul");
    push(&torreA, 2, "verde");
    push(&torreA, 1, "rojo");
    
    do {
        printf("\n=== TORRES DE HANOI ===\n");
        printf("1. Mostrar torres\n");
        printf("2. Mover disco\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                mostrarTorres(&torreA, &torreB, &torreC);
                break;
                
            case 2:
                printf("\nTorre de origen (A/B/C): ");
                scanf(" %c", &origen);
                printf("Torre de destino (A/B/C): ");
                scanf(" %c", &destino);
                
                // Seleccionamos las torres según la entrada
                Torre *torreOrigen = NULL, *torreDestino = NULL;
                
                if (origen == 'A') torreOrigen = &torreA;
                else if (origen == 'B') torreOrigen = &torreB;
                else if (origen == 'C') torreOrigen = &torreC;
                
                if (destino == 'A') torreDestino = &torreA;
                else if (destino == 'B') torreDestino = &torreB;
                else if (destino == 'C') torreDestino = &torreC;
                
                if (torreOrigen && torreDestino) {
                    // Intentamos mover el disco
                    Disco* disco = pop(torreOrigen);
                    if (disco != NULL) {
                        push(torreDestino, disco->tamaño, disco->color);
                        free(disco); // Liberamos la memoria del disco movido
                    }
                } else {
                    printf("\nError: Torres inválidas\n");
                }
                break;
                
            case 3:
                printf("\n¡Gracias por jugar!\n");
                break;
                
            default:
                printf("\nOpción inválida\n");
        }
    } while (opcion != 3);
    
    // Aquí deberíamos liberar la memoria de todos los discos restantes
    // pero lo dejamos como ejercicio para mantener el código simple
    
    return 0;
}
