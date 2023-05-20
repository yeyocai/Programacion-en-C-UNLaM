#ifndef TXTLONGFIJAABIN_H_INCLUDED
#define TXTLONGFIJAABIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int d,
        m,
        a;
}t_fecha;

typedef struct
{
    int dni;
    char apyn[30];
    char sexo;
    float promedio;
    t_fecha f_ing;
    char estado;
}t_alumno;

int cargar_archivo_de_texto_long_fija(char * path);
void sacar_espacios(char * texto);


#endif // TXTLONGFIJAABIN_H_INCLUDED
