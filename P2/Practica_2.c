#include <stdio.h>

#define PRACTICA2 10


struct Alumno{
    char nombre[50];
    char apellido[50];
    int edad;
    int numero_cuenta;
    char carrera[50];
    int semestre;
    float promedio;
};


void Entran(struct Alumno *alu) {
    printf("Ingrese nombre: ");
    scanf("%s", alu->nombre);
    printf("Ingrese apellido: ");
    scanf("%s", alu->apellido);
    printf("Ingrese edad: ");
    scanf("%d", &alu->edad);
    printf("Ingrese número de cuenta: ");
    scanf("%d", &alu->numero_cuenta);
    printf("Ingrese carrera: ");
    scanf("%s", alu->carrera);
    printf("Ingrese semestre: ");
    scanf("%d", &alu->semestre);
    printf("Ingrese promedio: ");
    scanf("%f", &alu->promedio);
}


void Salen(struct Alumno *alu) {
    printf("\nNombre: %s\n", alu->nombre);
    printf("Apellido: %s\n", alu->apellido);
    printf("Edad: %d\n", alu->edad);
    printf("Número de cuenta: %d\n", alu->numero_cuenta);
    printf("Carrera: %s\n", alu->carrera);
    printf("Semestre: %d\n", alu->semestre);
    printf("Promedio: %.2f\n", alu->promedio);
}



int main() {
    struct Alumno alu[PRACTICA2];
    struct Alumno *ptr_alumno;


    for (int i = 0; i < PRACTICA2; i++) {
        printf("\nIngresando datos del alumno %d:\n", i + 1);
        Entran(&alu[i]);
    }


    printf("\nDatos de los alumnos:\n");
    for (int i = 0; i < PRACTICA2; i++) {
        ptr_alumno = &alu[i];
        Salen(ptr_alumno);
    }
    
    return 0;
}