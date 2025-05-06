#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char nombre[MAX];
    int edad;
    float promedio;
}Estudiante;

void mostrarEstudiante();

int main(){
    Estudiante estudiantes[3];

    printf("\n================================================\n");
    printf("\nIngrese los datos de los estudiantes: ");

    for(int i = 0; i < 3; i++){
        Estudiante *ptr = &estudiantes[i];
        printf("Alumno numero %d: \n", i + 1);

        printf("Nombre: ");
        fgets(ptr -> nombre, MAX, stdin);
        ptr -> nombre[strcspn(ptr -> nombre, "\n")] = '\0';

        printf("\nEdad: ");
        scanf("%d", &ptr -> edad);
        getchar();

        printf("\nPromedio: ");
        scanf("%f", &ptr -> promedio);
        getchar();

    }//for

    printf("\n================================================\n");

    printf("\nInformacion de los estudiantes: ");
    for(int i = 0; i < 3; i++){
        printf("\n--------------------------------\n");

        mostrarEstudiante(&estudiantes[i]);
        printf("\n--------------------------------\n");

    }//for

    printf("\n================================================\n");

    return 0;

}//main

void mostrarEstudiante(Estudiante *ptr1){
    printf("\nNombre: %s", ptr1 -> nombre);
    printf("\nEdad: %02d", ptr1 -> edad);
    printf("\nPromedio : %.2f", ptr1 -> promedio);
}//void