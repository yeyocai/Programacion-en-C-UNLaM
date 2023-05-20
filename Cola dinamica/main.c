#include <stdio.h>
#include <stdlib.h>
#include "colaDinamica.h"

int main()
{
    int elem = 1, i;
    tCola cola_ent; /// pila de enteros
    crearCola(&cola_ent); /// inicializa la estructura para ser usada

    for(i=0; i<40; i++) /// si pongo 26 me da pila llena, de ahi para adelante un mensaje para cada num de mas
    {
        int r;
        r = ponerEnCola(&cola_ent, &i, sizeof(i)); /// me devuelve si pudo o no
        if(!r)
        {
            printf("Cola llena!");
        }
        ///printf("-%d-", i);
    }
    while(!colaVacia(&cola_ent))
    {
        sacarDeCola(&cola_ent, &elem, sizeof(elem));
        printf("-%d", elem);
    }

    return 0;
}
