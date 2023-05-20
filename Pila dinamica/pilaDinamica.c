#include <string.h>
#include <stdlib.h>
#include "pilaDinamica.h"

void crear_pila(tPila* pp)
{
    *pp = NULL;
}


int poner_en_pila(tPila* pp, const void* pd, unsigned tamDato) /// el primer nodo de la lista es el tope
{
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo)); /// malloc devuelve void*
    if(!nue)
    {
        return 0; /// pila llena
    }
    nue->info = malloc(tamDato);
    if(!nue->info)
    {
        free(nue);
        return 0; /// pila llena
    }

    nue->tamInfo = tamDato;
    nue->sig = *pp;
    memcpy(nue->info, pd, tamDato);

    *pp = nue;
    return 1;
}


int sacar_de_pila(tPila* pp, void* pd, unsigned tamDato)
{
    tNodo* elim = *pp;
    if(!*pp)
    {
        return 0; /// pila vacia
    }

    memcpy(pd, elim->info, MINIMO(elim->tamInfo,tamDato));
    *pp = elim->sig;

    free(elim->info);
    free(elim);
    return 1; /// OK
}


int ver_tope_pila(const tPila* pp, void* pd, unsigned tamDato)
{
    if(!*pp)
    {
        return 0; /// pila vacia
    }

    memcpy(pd, (*pp)->info, MINIMO((*pp)->tamInfo,tamDato));
    return 1; /// OK
}


int pila_vacia(const tPila* pp)
{
    return *pp == NULL;
}


int pila_llena(const tPila* pp, unsigned tamDato) /// aca no tiene mucho sentido: por ahi hay mem cuando llamo a pila_llena pero deja de haber cuando llamo a poner_en_pila
{
    void* nodo = malloc(sizeof(tNodo));
    void* info = malloc(tamDato);
    free(nodo); /// el free no modifica el puntero en si, solo libera la memoria a la que apunta ese puntero
    free(info);
    return !nodo || !info; /// o nodo == NULL || info == NULL;
}


void vaciar_pila(tPila* pp)
{
    while(*pp)
    {
        tNodo* aux = *pp;
        *pp = aux->sig;

        free(aux->info);
        free(aux);
    }
}
