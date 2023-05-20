#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaCtype.h"

int main()
{
    int r;
    char c = 61;
    r = mi_isalnum(c);
    if(r == 1)
        printf("El caracter %c es alfanumerico", c);
    else
        printf("El caracter no es alfanumerico");


    /*int r;
    char c = 94;
    r = mi_isalpha(c);
    if(r == 1)
        printf("El caracter %c es alfabetico", c);
    else
        printf("El caracter no es alfabetico");*/


    /*int r;
    char c = 125;
    r = mi_isascii(c);
    if(r == 1)
        printf("El caracter es ASCII");
    else
        printf("El caracter no es ASCII");*/


    /*int r;
    char c = 55;
    r = mi_iscntrl(c);
    if(r == 1)
        printf("El caracter es de control");
    else
        printf("El caracter no es de control");*/


    /*int r;
    char c = 40;
    r = mi_isdigit(c);
    if(r == 1)
        printf("El caracter %c es un digito decimal", c);
    else
        printf("El caracter no es un digito decimal");*/


    /*int r;
    char c = 120;
    r = mi_isgraph(c);
    if(r == 1)
        printf("El caracter %c tiene representacion grafica", c);
    else
        printf("El caracter no tiene representacion grafica");*/


    /*int r;
    char c = 124;
    r = mi_islower(c);
    if(r == 1)
        printf("El caracter %c es una letra minuscula", c);
    else
        printf("El caracter no es una letra minuscula");*/


    /*int r;
    char c = 125;
    r = mi_isprint(c);
    if(r == 1)
        printf("El caracter %c es imprimible", c);
    else
        printf("El caracter no es imprimible");*/


    /*int r;
    char c = 113;
    r = mi_ispunct(c);
    if(r == 1)
        printf("El caracter %c es de puntuacion", c);
    else
        printf("El caracter no es de puntuacion");*/


    /*int r;
    char c = 10;
    r = mi_isspace(c);
    if(r == 1)
        printf("El caracter es de tipo espacio");
    else
        printf("El caracter no es de tipo espacio");*/


    /*int r;
    char c = 72;
    r = mi_isupper(c);
    if(r == 1)
        printf("El caracter %c es una letra mayuscula", c);
    else
        printf("El caracter no es una letra mayuscula");*/


    /*int r;
    char c = 69;
    r = mi_isxdigit(c);
    if(r == 1)
        printf("El caracter %c es un digito hexadecimal", c);
    else
        printf("El caracter no es un digito hexadecimal");*/


    return 0;
}
