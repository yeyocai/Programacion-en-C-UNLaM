#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;


void crear_lista(tLista* pl);

int poner_primero_lista(tLista* pl, const void* pd, unsigned tamDato);
int sacar_primero_lista(tLista* pl, void* pd, unsigned tamDato);

int poner_ultimo_lista(tLista* pl, const void* pd, unsigned tamDato);

int poner_pos_lista(tLista* pl, const void* pd, unsigned tamDato, unsigned pos);
int poner_orden_lista(tLista* pl, const void* pd, unsigned tamDato, int (*cmp) (const void*, const void*));

int sacar_elem_lista(tLista* pl, void* pd, unsigned tamDato, int (*cmp)(const void*, const void*));
int sacar_elem_ord_lista(tLista* pl, void* pd, unsigned tamDato, int (*cmp) (const void*, const void*));

void reinsertar_nodo_menor(tLista* pl, tLista* men);
tNodo** buscar_menor_nodo_lista(const tLista* pl, int (*cmp)(const void*, const void*));
void ordenar_sel_lista(tLista* pl, int (*cmp) (const void*, const void*));

/// SOLO PARA TESTING
void mostrar_lista(tLista* pl);

#endif // LISTA_H_INCLUDED
