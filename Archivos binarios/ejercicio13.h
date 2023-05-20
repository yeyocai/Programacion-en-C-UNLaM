#ifndef EJERCICIO13_H_INCLUDED
#define EJERCICIO13_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dni;
    char apellido[50];
    char nombre[50];
    double sueldo;
}t_empleado;

typedef struct
{
    int dni;
    char apellido[50];
    char nombre[50];
    float promedio;
}t_estudiante;

int cargar_archivo_emp(char * path);
int cargar_archivo_est(char * path);
int comparar_emp_y_est(t_empleado * emp, t_estudiante * est);


#endif // EJERCICIO13_H_INCLUDED
