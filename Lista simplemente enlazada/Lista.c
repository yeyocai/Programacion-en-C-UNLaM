#include "Lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void crear_lista(tLista* pl)
{
    *pl = NULL;
}


int poner_primero_lista(tLista* pl, const void* pd, unsigned tamDato) /// como poner en pila
{
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
    {
        return 0; /// lista llena
    }
    nue->info = malloc(tamDato);
    if(!nue->info)
    {
      free(nue);
      return 0; /// lista llena
    }
    nue->tamInfo = tamDato;
    memcpy(nue->info, pd, tamDato);
    nue->sig = *pl;

    *pl = nue;

    return 1; /// OK
}


int sacar_primero_lista(tLista* pl, void* pd, unsigned tamDato) /// como sacar de pila
{
    tNodo* elim = *pl;
    if(!*pl)
    {
        return 0; /// lista vacia
    }
    memcpy(pd, elim->info, MINIMO(elim->tamInfo, tamDato));
    *pl = elim->sig;

    free(elim->info);
    free(elim);

    return 1; /// OK
}


int poner_ultimo_lista(tLista* pl, const void* pd, unsigned tamDato)
{
    while(*pl)
    {
        pl = &(*pl)->sig;
    }

    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
    {
        return 0; /// lista llena
    }
    nue->info = malloc(tamDato);
    if(!nue->info)
    {
      free(nue);
      return 0; /// lista llena
    }

    nue->tamInfo = tamDato;
    memcpy(nue->info, pd, tamDato);
    nue->sig = *pl; /// porque es el ultimo

    *pl = nue;

    return 1; /// OK
}


int poner_pos_lista(tLista* pl, const void* pd, unsigned tamDato, unsigned pos) /// poner nodo en una posicion determinada
{
    tNodo* nue;

    while(*pl && pos > 1)
    {
        pl = &(*pl)->sig;
        pos--;
    }

    if(pos != 1) /// sali porque encontre *pl = null antes de encontrar la posicion
    {
        return 0; /// Posicion invalida
    }


    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
    {
        return 0; /// LISTA_LLENA
    }

    nue->info = malloc(tamDato);
    if(!nue->info)
    {
        free(nue);
        return 0; /// LISTA_LLENA
    }

    memcpy(nue->info, pd, tamDato);
    nue->tamInfo = tamDato;
    nue->sig = *pl;

    *pl = nue;

    return 1; /// OK
}


int poner_orden_lista(tLista* pl, const void* pd, unsigned tamDato, int (*cmp) (const void*, const void*)) /// de menor a mayor
{
    tNodo* nue;
    int rc; /// resultado de comparacion

    while(*pl && (rc = cmp(pd, (*pl)->info)) > 0)
    {
        pl = &(*pl)->sig;
    }

    if(*pl && !rc) /// sali porque rc = 0
    {
        return 0; /// DUPLICADO
    }

    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
    {
        return 0; /// LISTA_LLENA
    }

    nue->info = malloc(tamDato);
    if(!nue->info)
    {
        free(nue);
        return 0; /// LISTA_LLENA
    }

    memcpy(nue->info, pd, tamDato);
    nue->tamInfo = tamDato;
    nue->sig = *pl;

    *pl = nue;

    return 1; /// OK
}


int sacar_elem_ord_lista(tLista* pl, void* pd, unsigned tamDato, int (*cmp) (const void*, const void*)) /// sacar un elemento de una lista ordenada
{                                                                                                       /// busco el elemento que me pasan y lo saco
    tNodo* elim;
    int rc;

    while(*pl && (rc = cmp(pd, (*pl)->info)) > 0)
    {
        pl = &(*pl)->sig;
    }

    if(!*pl || rc) /// rc negativo
    {
        return 0; /// NO_EXISTE
    }

    elim = *pl;
    memcpy(pd, elim->info, MINIMO(elim->tamInfo, tamDato));
    *pl = elim->sig;

    free(elim->info);
    free(elim);

    return 1; /// OK
}


void reinsertar_nodo_menor(tLista* pl, tLista* men)
{
    tNodo* aux = *men;
    *men = aux->sig;

    aux->sig = *pl;
    *pl = aux;
}


tNodo** buscar_menor_nodo_lista(const tLista* pl, int (*cmp)(const void*, const void*)) /// tLista* y tNodo** es lo mismo
{
    const tLista* men = pl;

    if(!*pl)
        return NULL;

    pl = &(*pl)->sig;

    while(*pl)
    {
        if(cmp((*pl)->info, (*men)->info) < 0)
        {
            men = pl;
        }
        pl = &(*pl)->sig;
    }
    return (tNodo**)men;
}


void ordenar_sel_lista(tLista* pl, int (*cmp)(const void*, const void*))
{
    tNodo** men;

    if(!*pl)
        return;

    while((*pl)->sig)
    {
        men = buscar_menor_nodo_lista(pl, cmp);
        if(pl != men)
        {
            //intercambio_info_nodos(pl, men);
            reinsertar_nodo_menor(pl, men);
        }
        pl = &(*pl)->sig;
    }
}


/// SOLO PARA TESTING
void mostrar_lista(tLista *pl)
{
    while(*pl)
    {
        printf("-%d-", *(int*)((*pl)->info));
        pl = &(*pl)->sig;
    }
}

