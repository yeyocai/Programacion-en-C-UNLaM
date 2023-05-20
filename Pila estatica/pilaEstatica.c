#include "pilaEstatica.h"

#include <string.h>

void crear_pila(tPila * pp) /// tope siempre esta a un lugar mas de donde se guarda
{
    pp->tope = TAM_PILA; /// pone el tope al final, eso me indica que la pila esta vacia (tope es un numero)
}


int poner_en_pila(tPila * pp, const void * pd, unsigned tamDato) /// pd: void* porque no se que dato es, tamDato: puede ser unsigned o size_t
{
    if(pp->tope < (tamDato + sizeof(unsigned))) /// veo si hay lugar (si tope = 8, tengo del 0 al 7 para copiar (8 en total))
    {
        return 0; /// pila llena
    }
    pp->tope -= tamDato;                                        /// me muevo para atras la cantidad de posic del tamaño del dato y copio el elem (pd)
    memcpy(pp->pila + pp->tope, pd, tamDato); /// uso memcpy pq no puedo desref punt a void
    pp->tope -= sizeof(unsigned);                               /// me muevo para atras para poner el tamaño del dato y lo copio
    memcpy(pp->pila + pp->tope, &tamDato, sizeof(unsigned));
    return 1; /// OK
}


int sacar_de_pila(tPila * pp, void * pd, unsigned tamDato) /// pd: var donde quiero guardar el dato, tamDato: tamaño del dato que el usuario espera recibir
{                                                          /// por ahi tamDato no coincide con el que esta guardado en la pila, por eso lo valido
    unsigned tamDatoPila;
    if(pp->tope == TAM_PILA)
        return 0; /// pila vacia
    memcpy(&tamDatoPila, pp->pila + pp->tope, sizeof(unsigned));
    pp->tope += sizeof(unsigned);
    memcpy(pd, pp->pila + pp->tope, MINIMO(tamDatoPila,tamDato)); /// agarro el minimo para no pisarle memoria al usuario (si tamDatoPila es mas grande)
    pp->tope += tamDatoPila;                                         /// o para no copiar bytes de mas de la pila (si tamDato es mas grande)
    return 1; /// OK
}


int ver_tope_pila(const tPila * pp, void * pd, unsigned tamDato) /// como sacar pero sin cambiar tope
{
    unsigned tamDatoPila;
    if(pp->tope == TAM_PILA)
        return 0; /// pila vacia
    memcpy(&tamDatoPila, pp->pila + pp->tope, sizeof(unsigned));
    memcpy(pd, pp->pila + pp->tope + sizeof(unsigned), MINIMO(tamDatoPila,tamDato));
    return 1; /// OK

}


int pila_vacia(const tPila * pp)
{
    return pp->tope == TAM_PILA;
}


int pila_llena(const tPila * pp, unsigned tamDato)
{
    return pp->tope < (tamDato + sizeof(unsigned));
}


void vaciar_pila(tPila * pp)
{
    pp->tope = TAM_PILA;
}
