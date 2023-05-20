#include <stdio.h>
#include <stdlib.h>
#include "colaEstatica.h"

int main()
{
    int r;
    int elem = 1, i;
    tCola cola_ent;
    crearCola(&cola_ent);

    for(i=0; i<20; i++)
    {
        r = ponerEnCola(&cola_ent, &i, sizeof(i));
        if(!r)
        {
            printf("Cola llena!");
        }
        printf("-%d-", i);
    }

    frenteDeCola(&cola_ent, &elem, sizeof(elem));
    printf("\nFrente: %d\n", elem);

    while(!colaVacia(&cola_ent))
    {
        sacarDeCola(&cola_ent, &elem, sizeof(elem));
        printf("-%d", elem);
    }

    vaciarCola(&cola_ent);

    r = frenteDeCola(&cola_ent, &elem, sizeof(elem));
    if(!r)
        printf("\nCola vacia!");

    return 0;
}

