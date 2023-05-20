#include <stdio.h>
#include <stdlib.h>
#include "pilaDinamica.h"

int main()
{
    int elem = 1, i;
    tPila pila_ent; /// pila de enteros
    crear_pila(&pila_ent); /// inicializa la estructura para ser usada

    for(i=0; i<10; i++)
    {
        int r;
        r = poner_en_pila(&pila_ent, &i, sizeof(i)); /// me devuelve si pudo o no
        if(!r)
        {
            printf("Pila llena!");
        }
    }
    while(!pila_vacia(&pila_ent))
    {
        sacar_de_pila(&pila_ent, &elem, sizeof(elem));
        printf("-%d", elem);
    }

    return 0;
}
