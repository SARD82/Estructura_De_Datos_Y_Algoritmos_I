#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    autores *autores;
} libros;

void ingresar_libro(libros *libro){

    printf("\n======================================================\n");

    printf("\nIngrese el titulo del libro: ");
    fgets(libro -> titulo, MAX, stdin); //fgets(variable, tamaño, stdin); stdin es entrada por teclado.
    libro -> titulo[strcspn(libro -> titulo, "\n")] = '\0'; //para eliminar el salto de línea el '\n' al final.

    printf("\nIngrese la editorial: ");
    fgets(libro -> editorial, MAX, stdin);
    libro -> editorial[strcspn(libro -> editorial, "\n")] = '\0';

    printf("\nIngrese el genero del libro: ");
    fgets(libro -> genero, MAX, stdin);
    libro -> genero[strcspn(libro -> genero, "\n")] = '\0';

    printf("\nIngrese las paginas del libro: ");
    scanf("%d", &libro -> paginas);
    getchar(); //limpiar el '\n' restante en el buffer.

    printf("\nIngrese la fecha de publicacion: (DD MM AAAA) ");
    scanf("%d %d %d", &libro -> fecha_publicacion.dia, 
        &libro -> fecha_publicacion.mes, 
        &libro -> fecha_publicacion.año);
    getchar();

    printf("\n======================================================\n");

    do{ 
        printf("\nIngrese el numero de autores (al menos 1): ");
        scanf("%d", &libro -> numero_autores);
        getchar();
    } while (libro -> numero_autores < 1);

    libro -> autores = (autores *)malloc(libro -> numero_autores * sizeof(autores));
    if(libro -> autores == NULL){
        printf("\nError al asignar los autores.");
        exit(1);

    }//if

    printf("\n======================================================\n");

    for(int i = 0; i < libro -> numero_autores; i++){
        printf("\nIngrese los datos del autor o autores: \n");
        printf("\nIngrese el nombre del autor %d: ", i + 1);
        fgets(libro -> autores[i].nombre, MAX, stdin);
        libro -> autores[i].nombre[strcspn(libro -> autores[i].nombre, "\n")] = '\0';

        printf("\nIngrese los apellidos del autor %d: ", i + 1);
        fgets(libro -> autores[i].apellidos, MAX, stdin);
        libro -> autores[i].apellidos[strcspn(libro -> autores[i].apellidos, "\n")] = '\0';

        printf("\nIngrese el pais del autor %d: ", i + 1);
        fgets(libro -> autores[i].pais, MAX, stdin);
        libro -> autores[i].pais[strcspn(libro -> autores[i].pais, "\n")] = '\0';

        printf("\nIngrese la fecha de nacimiento del autor %d: (DD MM AAAA) ", i + 1);
        scanf("%d %d %d",&libro -> autores[i].fecha_nacimiento.dia, 
            &libro -> autores[i].fecha_nacimiento.mes, 
            &libro -> autores[i].fecha_nacimiento.año);
        getchar();

    }//for
    
    printf("\n========================================================\n");

}//void

void mostrar_libro(libros libro){
    
    printf("\n========================================================\n");

    printf("\n---------------------------------------------------------\n");
    printf("\nMostrando informacion\n");
    printf("\n---------------------------------------------------------\n");

    printf("\nTitulo: %s", libro.titulo);
    printf("\nEditorial: %s", libro.editorial);
    printf("\nGenero: %s", libro.genero);
    printf("\nPaginas: %d", libro.paginas);
    printf("\nNumero de autores: %d", libro.numero_autores);
    printf("\nFecha de publicacion: %02d/%02d/%04d\n", libro.fecha_publicacion.dia, libro.fecha_publicacion.mes, libro.fecha_publicacion.año); //02 y 04 para que sean solo dos o cuatro numeros respectivamente.
    
    printf("\n---------------------------------------------------------\n");
    
    printf("\nAutor o autores: \n");

    for(int i = 0; i < libro.numero_autores; i++){
        printf("\nAutor numero %d", i + 1);
        printf("\nNombre autor: %s %s", libro.autores[i].nombre, libro.autores[i].apellidos);
        printf("\nPais del autor: %s", libro.autores[i].pais);
        printf("\nFecha de nacimiento: %02d/%02d/%04d\n ", libro.autores[i].fecha_nacimiento.dia, libro.autores[i].fecha_nacimiento.mes, libro.autores[i].fecha_nacimiento.año);
        
    }//for

    printf("\n========================================================\n");
}//void

int main(){
    
    int num_libros;
    printf("\nIngrese la cantidad de libros a crear: ");
    scanf("%d", &num_libros);
    getchar();

    libros *libr = (libros *) malloc(num_libros * sizeof(libros));
    if (libr == NULL){
        printf("\nError: No se puede asignar la memoria para los libros");
        return 1;

    }//if

    for(int i = 0; i < num_libros; i++){
        printf("\nIngrese datos del libro: %d", i + 1);
        ingresar_libro(&libr[i]);

    }//for

    int opcion;
    do{
        printf("\nIngrese el numero del libro que desea ver su informacion (1 a %d): ", num_libros);
        scanf("%d", &opcion);
    }while(opcion < 1 || opcion > num_libros);

    mostrar_libro(libr[opcion - 1]);

    for(int i = 0; i < num_libros; i++){
        free(libr[i].autores);

    }//for

    free(libr);
    return 0;

}//main