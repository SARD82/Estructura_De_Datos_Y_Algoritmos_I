// Durán Rendón Santiago.
// 15 de febrero de 2025.
// Estructura de Datos y Algoritmos I.
// Ejercicio 1 Práctica 1: Leer una frase en una variable string, contar cuantas vocales contiene la frase y mostrar el número.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*La biblioteca <string.h> en C proporciona funciones útiles para manipular cadenas de caracteres (arrays de tipo char). En nuestro código, la usamos para:

Obtener la longitud de la cadena con strlen(frase)

strlen() nos dice cuántos caracteres tiene una cadena antes del \0 (carácter nulo que indica el final de la cadena).
Así evitamos recorrer más caracteres de los que realmente tiene la cadena.
Otras funciones útiles de <string.h>

strcpy(destino, origen); → Copia una cadena en otra.
strcat(destino, origen); → Une dos cadenas.
strcmp(cad1, cad2); → Compara dos cadenas (devuelve 0 si son iguales).
strchr(cadena, 'a'); → Busca la primera aparición de un carácter en la cadena.*/

#define MAX 25 //Promedio de palabras que tienen las frases.

void ingresar_frase();

int main(){
    
    printf("\nPrograma que a partir de una frase, cuanta las vocales y te dice cuantas tiene\n");
    ingresar_frase();

    return 0;
}//main

void ingresar_frase(){
    char frase[MAX]; //Cadena para almacenar la frase.
    int contador_vocales = 0;

    printf("Ingrese la frase (numero maximo de caracteres %d)\n ", MAX - 1);//-1 por el \0
    fgets(frase, MAX, stdin); //fgets(destino, tamaño, fuente(stdin = entrada estándar, es decir, el teclado));   // fgets se usa para leer una linea completa
    //fgets sirve para leer tipo scanf

    for(int j = 0; j < strlen(frase); j++){
        //scanf("%s", &frase[j]);//%s cadenas e texto. %c solo una letra
        char c = frase[j]; //Para obtener el caracter actual.
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            contador_vocales++;
        }//if
    }//for

    printf("\n===========================================================\n");
    printf("Calculando vocales...\n");
    printf("El total de vocales es: %d ", contador_vocales);

}//void