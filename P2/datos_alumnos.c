// Durán Rendón Santiago.
// 15 de febrero de 2025.
// Estructura de Datos y Algoritmos I.
/* Ejercicio Práctica 2: Crear una estructura para los datos de un alumno:
Nombre
Apellido
Edad
Número de Cuenta
Carrera
Semestre
Promedio

Crear un arreglo de 10 elementos de tipo struct que se creó para los datos de alumno.

Crear una función que reciba un parámetro por referencia de la struct de los datos de alumno, para leer toda la información.

Leer los datos de cada elemento del arreglo utilizando la función anterior.

Imprimir los datos de los 10 alumnos mediante un ciclo pero recorriendo el arreglo utilizando un apuntador de tipo struct.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para poder acceder a variables de tipo char ya que no se puede declarar usando "=" y es usando strcpy.

#define LONGITUD_MAXIMA_CADENA 50
#define CANTIDAD_ALUMNOS 2 

struct datos_alumnos{
    char nombre[LONGITUD_MAXIMA_CADENA];
    char apellido_paterno[LONGITUD_MAXIMA_CADENA];
    char apellido_materno[LONGITUD_MAXIMA_CADENA];
    int edad;
    int num_cuenta;
    char carrera[LONGITUD_MAXIMA_CADENA];
    int semestre;
    float promedio;
};

struct datos_alumnos alumnos[CANTIDAD_ALUMNOS];
struct datos_alumnos *b = alumnos; //puntero que tiene un struct datos_alumnos adentro que apunta a el elemento de CANTIDAD DE ALUMNOS.

void ingresar_datos(struct datos_alumnos *a){ //puntero a que tiene un struct datos_alumnos adentro.
    printf("\nIngrese los datos del alumno:\n");
    printf("\nNombre: ");
    scanf("%s", a -> nombre); // puntero -> campo 
    printf("\nApellido paterno: ");
    scanf("%s", a -> apellido_paterno);
    printf("\nApellido materno: ");
    scanf("%s", a -> apellido_materno);
    printf("\nEdad: ");
    scanf("%d", &a -> edad);
    printf("\nNumero de cuenta: ");
    scanf("%d", &a -> num_cuenta);
    printf("\nCarrera: ");
    scanf("%s", a -> carrera);
    printf("\nSemestre: ");
    scanf("%d", &a -> semestre);
    printf("\nPromedio: ");
    scanf("%f", &a -> promedio); //%f para floats
}//void

void imprimir_datos(){
    for(int i = 0; i < CANTIDAD_ALUMNOS; i++){
        printf("\n-------Datos del alumno %d------", i + 1);
        printf("\nNombre completo: %s %s\n", (b + i) -> nombre, (b + i) -> apellido_paterno, (b + i) -> apellido_materno);
        printf("\nNombre: %s\n", (b + i) -> nombre);
        printf("\nApellido paterno: %s\n", (b + i) -> apellido_paterno);
        printf("\nApellido materno: %s\n", (b + i) -> apellido_materno);
        printf("\nEdad: %d\n", (b + i) -> edad);
        printf("\nNumero de cuenta: %d\n", (b + i) -> num_cuenta);
        printf("\nCarrera: %s\n", (b + i) -> carrera);
        printf("\nSemestre: %d\n", (b + i) -> semestre);
        printf("\nPromedio: %.2f\n", (b + i) -> promedio); //.2 para solo dos decimales en el float.
    }//for
}//void

int main(){
    for(int i = 0; i < CANTIDAD_ALUMNOS; i++){
        ingresar_datos(&alumnos[i]);
    }//for

    imprimir_datos();

    return 0;

}//main