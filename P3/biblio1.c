#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int año;
} Fecha;

typedef struct {
    char nombre[50];
    char apellidos[50];
    char pais[50];
    Fecha fecha_nacimiento;
} Autor;


typedef struct {
    char titulo[100];
    char editorial[50];
    char genero[50];
    int paginas;
    Fecha fecha_publicacion;
    int num_autores;  
    Autor autores[3];
} Libro;


void ingresarLibro(Libro *libro) {
    printf("\nIngrese el título del libro: ");
    scanf(" %[^\n]", libro->titulo);

    printf("Ingrese la editorial: ");
    scanf(" %[^\n]", libro->editorial);

    printf("Ingrese el género: ");
    scanf(" %[^\n]", libro->genero);

    printf("Ingrese el número de páginas: ");
    scanf("%d", &libro->paginas);

    printf("Ingrese la fecha de publicación (DD MM AAAA): ");
    scanf("%d %d %d", &libro->fecha_publicacion.dia, &libro->fecha_publicacion.mes, &libro->fecha_publicacion.año);


    do {
        printf("Ingrese el número de autores (1-3): ");
        scanf("%d", &libro->num_autores);
    } while (libro->num_autores < 1 || libro->num_autores > 3);


    for (int i = 0; i < libro->num_autores; i++) {
        printf("\nIngrese los datos del autor %d:\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", libro->autores[i].nombre);
        
        printf("Apellidos: ");
        scanf(" %[^\n]", libro->autores[i].apellidos);
        
        printf("País: ");
        scanf(" %[^\n]", libro->autores[i].pais);
        
        printf("Fecha de nacimiento (DD MM AAAA): ");
        scanf("%d %d %d", &libro->autores[i].fecha_nacimiento.dia,
              &libro->autores[i].fecha_nacimiento.mes,
              &libro->autores[i].fecha_nacimiento.año);
    }
}

void mostrarLibro(Libro libro) {
    printf("\n=============================\n");
    printf("Título: %s\n", libro.titulo);
    printf("Editorial: %s\n", libro.editorial);
    printf("Género: %s\n", libro.genero);
    printf("Páginas: %d\n", libro.paginas);
    printf("Fecha de publicación: %02d/%02d/%04d\n", libro.fecha_publicacion.dia,
           libro.fecha_publicacion.mes, libro.fecha_publicacion.año);
    
    printf("\n--- Autores (%d) ---\n", libro.num_autores);
    for (int i = 0; i < libro.num_autores; i++) {
        printf("Autor %d:\n", i + 1);
        printf("  Nombre: %s %s\n", libro.autores[i].nombre, libro.autores[i].apellidos);
        printf("  País: %s\n", libro.autores[i].pais);
        printf("  Fecha de nacimiento: %02d/%02d/%04d\n", libro.autores[i].fecha_nacimiento.dia,
               libro.autores[i].fecha_nacimiento.mes, libro.autores[i].fecha_nacimiento.año);
    }
    printf("=============================\n");
}

int main() {
    Libro libros[5];
    
    for (int i = 0; i < 5; i++) {
        printf("\nIngresando datos del libro %d:\n", i + 1);
        ingresarLibro(&libros[i]);
    }

    int opcion;
    do {
        printf("\nIngrese el número del libro que desea ver (1-5): ");
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 5);
    
    mostrarLibro(libros[opcion - 1]);

    return 0;
}