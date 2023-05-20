#include "listaDoble.h"
#include <stdlib.h>
#include <string.h>

void crearListaD(tListaD* pl)
{
    *pl = NULL;
}


int ponerOrdListaD(tListaD* pl, const void* pd, unsigned tamDato, int (*cmp)(const void*, const void*)) /// poner ordenado en lista doble
{
    tNodoD *auxSig = *pl,
           *auxAnt = auxSig? auxSig->ant : NULL, /// si la lista esta vacia empiezo con auxAnt y auxSig en NULL
           *nue;

    while(auxSig && cmp(pd, auxSig->info) > 0) /// si entra a este while no entra al de abajo y viceversa, porque la lista esta ordenada
    {
        auxAnt = auxSig;
        auxSig = auxSig->sig;
    }

    while(auxAnt && cmp(pd, auxAnt->info) < 0)
    {
        auxSig = auxAnt;
        auxAnt = auxAnt->ant;
    }

    if((auxSig && cmp(pd, auxSig->info) == 0)
       || (auxAnt && cmp(pd, auxAnt->info) == 0))
    {
        return 0; /// duplicado
    }

    if((nue = (tNodoD*)malloc(sizeof(tNodoD))) == NULL
       || (nue->info = malloc(tamDato)) == NULL)
    {
        free(nue);
        return 0; /// sin memoria
    }

    memcpy(nue->info, pd, tamDato);
    nue->tamInfo = tamDato;

    nue->sig = auxSig;
    nue->ant = auxAnt;
    if(auxSig)
        auxSig->ant = nue;
    if(auxAnt)
        auxAnt->sig = nue;

    *pl = nue;

    return 1;
}


int sacarOrdListaD(tListaD* pl, void* pd, unsigned tamDato, int (*cmp)(const void*, const void*))
{
    tNodoD * elim = *pl;

    if(!*pl)
        return 0; /// lista vacia

    while(elim->sig && cmp(pd, elim->info) > 0)
    {
        elim = elim->sig;
    }

    while(elim->ant && cmp(pd, elim->info) < 0)
    {
        elim = elim->ant;
    }

    if(cmp(pd, elim->info) == 0) /// lo encontro
    {
        if(elim->ant)
            elim->ant->sig = elim->sig;
        if(elim->sig)
            elim->sig->ant = elim->ant;
        *pl = elim->sig ? elim->sig : elim->ant;

        memcpy(pd, elim->info, MINIMO(elim->tamInfo, tamDato));
        free(elim->info);
        free(elim);

        return 1;
    }
    return 0; /// no lo encontro
}


int listaVaciaD(const tListaD* pl)
{
    return !*pl;
}



int listaLlenaD(const tListaD* pl, unsigned tamDato)
{
    tNodoD* aux = (tNodoD*)malloc(sizeof(tNodoD));
    void* info = malloc(tamDato);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}


int vaciarListaD(tListaD* pl)
{
    int cant = 0;
    tNodoD * act = *pl,
           * aux;

    if(act)
    {
        while(act->ant) /// me voy al principio
            act = act->ant;
        while(act)
        {
            aux = act->sig;
            free(act->info);
            free(act);
            act = aux;
            cant++;
        }
        *pl = NULL;
    }
    return cant;
}
