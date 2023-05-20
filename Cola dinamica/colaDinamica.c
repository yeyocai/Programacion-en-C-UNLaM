#include "colaDinamica.h"
#include <stdlib.h>
#include <string.h>

void crearCola(tCola* pc)
{
    pc->pri = pc->ult = NULL;
}


int ponerEnCola(tCola* pc, const void* pd, unsigned tamDato) /// pongo a lo ultimo (caso especial si pongo el primero)
{
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
    {
        return 0; /// cola llena
    }
    nue->info = malloc(tamDato);
    if(!nue->info)
    {
        free(nue);
        return 0; /// cola llena
    }
    memcpy(nue->info, pd, tamDato);
    nue->tamInfo = tamDato;
    nue->sig = NULL; /// este va a ser mi nuevo ultimo

    if(pc->ult) /// si existe un ultimo (si la cola no esta vacia), modifico el campo sig del ultimo
    {
        pc->ult->sig = nue;
    }
    else /// si no (si la cola esta vacia) modifico pri
    {
        pc->pri = nue;
    }
    pc->ult = nue; /// y siempre modifico ult

    return 1; /// OK
}


int sacarDeCola(tCola* pc, void* pd, unsigned tamDato) /// saco el primero (caso especial sacar el ultimo)
{
    tNodo* elim = pc->pri;
    if(!elim)
    {
        return 0; /// cola vacia
    }
    memcpy(pd, elim->info, MINIMO(elim->tamInfo,tamDato));
    pc->pri = elim->sig;
    if(!pc->pri)
    {
        pc->ult = NULL;
    }
    free(elim->info);
    free(elim);

    return 1; /// OK
}


int frenteDeCola(const tCola* pc, void* pd, unsigned tamDato) /// solo verlo
{
    if(!pc->pri)
    {
        return 0; /// cola vacia
    }
    memcpy(pd, pc->pri->info, MINIMO(pc->pri->tamInfo,tamDato));
    return 1;
}


int colaLlena(const tCola* pc, unsigned tamDato)
{
    void* nodo = malloc(sizeof(tNodo));
    void* info = malloc(tamDato);
    free(nodo);
    free(info);
    return !nodo || !info;
}


int colaVacia(const tCola* pc)
{
    return !pc->pri;
}


void vaciarCola(tCola* pc)
{
    tNodo* aux;
    while(pc->pri)
    {
        aux = pc->pri;
        pc->pri = aux->sig;
        free(aux->info);
        free(aux);
    }
    pc->ult = NULL;
}
