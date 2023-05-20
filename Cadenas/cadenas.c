#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"


char* mi_strchr(const char * cad, int c)
{
    while(*cad && *cad != c)
    {
        cad++;
    }

    if(*cad) /// o *cad == '\0'
        return (char *)cad;

    return NULL;
}


int mi_strcmp(const char * cad1, const char * cad2)
{
    int res;

    while(*cad1 && *cad2)
    {
        res = *cad1 - *cad2;

        if(res != 0)
        {
            return res;
        }
        cad1++;
        cad2++;
    }
    if(!*cad1 && !*cad2 ) /// o *cad1 == '\0' && *cad2 == '\0'
        return 0;

    return *cad1 - *cad2;
}


char aMayuscula(char car) /// tiene que estar en minuscula
{
    if(car > 'a' && car < 'z')
        return car - ('a' - 'A'); /// las mayusculas estan primero - distancia 32 - resto letras para no aprender distacia de memoria, estan todas a la misma distancia de su mayuscula

    return car;
}


char aMinuscula(char car) /// tiene que estar en mayuscula
{
    if(car > 'A' && car < 'Z')
        return car + ('a' - 'A');

    return car;
}

int es_letra(char car)
{
    return (car >= 'a' && car <= 'z') || (car >= 'A' && car <= 'Z'); /// los parectesis no son necesarios pero los pongo para sacar el warning, el && tiene prcedencia sobre el ||
}
