#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 100

int main()
{
    char texto[TAM] = "puntero a puntero es forma punteros encadenamiento123456 de punteros.";

    char texto2[TAM] = "Esta es la materia Programacion";
    char texto3[TAM] = " $. hOLa $.#	qUe$.#	taL&.#";
    char primera[TAM];

    int apariciones;
    int cant_palabras;
    int long_palabra;

    primera_palabra(texto,primera);
    apariciones=cuantas_veces_aparece(texto,primera);
    cant_palabras=cuantas_palabras_tiene_el_texto(texto);
    long_palabra=longitud_de_la_palabra_mas_larga(texto);

    invertir_in_situ(texto2);

    printf("LA PRIMERA PALABRA ES:                   %s\n\n",primera);
    printf("LA PRIMERA PALABRA APARECE:              %d veces\n\n",apariciones);
    printf("CANTIDAD DE PALABRAS:                    %d \n\n",cant_palabras);
    printf("LONGITUD DE LA PALABRA MAS LARGA:        %d caracteres\n\n",long_palabra);

    printf("TEXTO INVERTIDO:                         %s\n\n", texto2);
    printf("TEXTO NORMALIZADO:                       %s\n\n", normalizar(texto3));

    return 0;
}
