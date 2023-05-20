#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

typedef struct
{
    int dni;
    char apyn[30];
    char sexo;
}tPersona;

int cmp_ent(const void* v1, const void* v2);
int cmp_pers_dni(const void* v1, const void* v2);
int cmp_pers_apyn(const void* v1, const void* v2);


int main()
{
    tLista lista_ent, lista_per;
    int vec[] = {2, 8, 4, 6, 5, 9, 7, 4, 1, 3},
        i;
    tPersona vPer[] = { {2, "Persona 1", 'X'},
                        {8, "Persona 2", 'X'},
                        {4, "Persona 3", 'X'},
                        {6, "Persona 4", 'X'},
                        {5, "Persona 5", 'X'},
                        {9, "Persona 6", 'X'},
                        {7, "Persona 7", 'X'},
                        {4, "Persona 8", 'X'},
                        {1, "Persona 9", 'X'},
                        {3, "Persona 10", 'X'} };

    crear_lista(&lista_ent);
    for(i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        poner_orden_lista(&lista_ent, vec+i, sizeof(int), cmp_ent);
        //poner_primero_lista(&lista_ent, vec+i, sizeof(int));
        printf("\n\n");
        mostrar_lista(&lista_ent);
    }

    for(i=0; i<sizeof(vec)/sizeof(int); i++)
    {
        sacar_elem_ord_lista(&lista_ent, vec+i, sizeof(int), cmp_ent); /// vec+i: elemento que quiero sacar
        printf("\n\n");
        mostrar_lista(&lista_ent);
    }


    crear_lista(&lista_per);

    printf("\n\n*****Prueba Ordenar Seleccion**********\n\n");

    for(i=0; i<sizeof(vPer)/sizeof(tPersona); i++)
    {
        //poner_orden_lista(&lista_per, vPer+i, sizeof(tPersona), cmp_pers_dni);
        poner_ultimo_lista(&lista_per, vPer+i, sizeof(tPersona)); /// para que queden desordenados
    }

    ordenar_sel_lista(&lista_per, cmp_pers_dni); /// aca los ordeno por dni, los podria haber ordenado por apellido y nombre

    for(i=0; i<sizeof(vPer)/sizeof(tPersona); i++) /// los voy sacando y los voy mostrando
    {
        tPersona p1;
        p1.dni = vPer[i].dni;
        strcpy(p1.apyn, "xxxxxxx"); /// esta de mas, solo es para ver como funciona

        sacar_primero_lista(&lista_per, &p1, sizeof(tPersona));
        printf("\n");
        printf("  -%d %s", p1.dni, p1.apyn);
    }

    printf("\n\n*****Prueba insertar ordenado**********\n\n");

    for(i=0; i<sizeof(vPer)/sizeof(tPersona); i++)
    {
        poner_orden_lista(&lista_per, vPer+i, sizeof(tPersona), cmp_pers_dni);
    }

    for(i=0; i<sizeof(vPer)/sizeof(tPersona); i++)
    {
        tPersona p1;
        p1.dni = vPer[i].dni;
        strcpy(p1.apyn, "xxxxxxx");

        sacar_elem_ord_lista(&lista_per, &p1, sizeof(tPersona), cmp_pers_dni);
        printf("\n");
        printf("  -%d %s", p1.dni, p1.apyn);
    }

    return 0;
}


int cmp_ent(const void* v1, const void* v2)
{
    int* e1 = (int*)v1;
    int* e2 = (int*)v2;
    return *e1 - *e2;
}


int cmp_pers_dni(const void* v1, const void* v2)
{
    tPersona *p1 = (tPersona*)v1,
             *p2 = (tPersona*)v2;

    return p1->dni - p2->dni;
}


int cmp_pers_apyn(const void* v1, const void* v2)
{
    tPersona *p1 = (tPersona*)v1,
             *p2 = (tPersona*)v2;

    return strcmpi(p1->apyn, p2->apyn);
}
