#include <stdio.h>

#define MAX 50

typedef struct{
    int dia;
    int mes;
    int año;
} fecha;

typedef struct  {
    char nombre[MAX];
    char apellidos[MAX];
    char pais[MAX];
    fecha fecha_nacimiento;
} autores; 

typedef struct {
    char titulo[MAX];
    char editorial[MAX];
    char genero[MAX];
    int paginas;
    int numero_autores;
    fecha fecha_publicacion; 
    autores autores[3];
} libros;

void ingresar_libro(libros *libro){

    printf("\n======================================================\n");

    printf("\nIngrese el titulo del libro: ");
    scanf("%s", libro -> titulo); 
    printf("\nIngrese la editorial: ");
    scanf("%s", libro -> editorial);
    printf("\nIngrese el genero del libro: ");
    scanf("%s", libro -> genero);
    printf("\nIngrese las paginas del libro: ");
    scanf("%d", &libro -> paginas);
    printf("Ingrese la fecha de publicacion: (DD MM AAAA) ");
    scanf("%d %d %d", &libro -> fecha_publicacion.dia, &libro -> fecha_publicacion.mes, &libro -> fecha_publicacion.año);

    do{ 
        printf("\nIngrese el numero de autores (1 a 3): ");
        scanf("%d", libro -> numero_autores); 
    } while (libro -> numero_autores < 1 || libro -> numero_autores > 3);

    for(int i = 0; i < libro -> numero_autores; i++){
        printf("\nIngrese los datos del autor o autores: ");
        printf("\nIngrese el nombre del autor %d: ", i++);
        scanf("%s", libros -> autores[i].nombre);
        printf("\nIngrese los apellidos del autor %d: ", i++);
        scanf("%s", libros -> autores[i].apellidos);
        printf("\nIngrese el pais del autor %d: ", i++);
        scanf("%s", libros -> autores[i].pais);
        printf("\nIngrese la fecha de nacimiento del autor %d: (DD MM AAAA) ", &libros -> autores[i].fecha_nacimiento.dia, &libros -> autores[i].fecha_nacimiento.mes, &libros -> autores[i].fecha_nacimiento.año);

    }//for
    
    printf("\n========================================================\n");

}//void

void mostrar_libro(libros libro){
    
    printf("\n========================================================\n");

    printf("\nTitulo: %s", libro.titulo);
    printf("\nEditorial: %s", libro.editorial);
    printf("\nGenero: %s", libro.genero);
    printf("\nPaginas: %d", libro.paginas);
    printf("\nNumero de autores: %d", libro.numero_autores);
    printf("\nFecha de publicacion: %02d/%02d/%04d", libro.fecha_publicacion.dia, libro.fecha_publicacion.mes, libro.fecha_publicacion.año); //02 y 04 para que sean solo dos o cuatro numeros respectivamente.
    printf("\nAutor o autores:");

    for(int i = 0; i < libro.autores; i++){
        printf("\nAutor numero %d", 1++)
        printf("\nNombre autor: %s %s", libro.autores[i].nombre, libro.autores[i].apellidos);
        printf("\nPais del autor: %s", libro.autores[i].pais);
        printf("\nFecha de nacimiento: %02d/%02d/%04d", libro.autores[i].fecha_nacimiento.dia, libro.autores[i].fecha_nacimiento.mes, libro.autores[i].fecha_nacimiento.año);
        
    }//for

    printf("\n========================================================\n");
}//void

int main(){
    libros libros[5];

    for(int i = 0; i < 5; i++){
        printf("\nIngrese datos del libro: %d", i++);
        ingresar_libro(&libros[i]);

    }//for

    int opcion;
    do{
        printf("\nIngrese el numero del libro que desea ver su informacion (1 a 5): ");
        scanf("%d", &opcion);
    }while(opcion < 1 || opcion > 5);

    mostrar_libro(libros[opcion - 1]);
    
}//main