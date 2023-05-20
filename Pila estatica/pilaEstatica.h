#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))
#define TAM_PILA 400

typedef struct
{
    char pila[TAM_PILA]; /// pongo char porque ocupa 1 byte, despues guardo cualquier cosa (no puedo declarar array que no tenga tipo)
    unsigned tope; /// me dice donde esta el tope e indirectamente cuantos elementos hay
}tPila;

void crear_pila(tPila * pp);

int poner_en_pila(tPila * pp, const void * pd, unsigned tamDato);
int sacar_de_pila(tPila * pp, void * pd, unsigned tamDato);
int ver_tope_pila(const tPila * pp, void * pd, unsigned tamDato);

int pila_vacia(const tPila * pp);
int pila_llena(const tPila * pp, unsigned tamDato);

void vaciar_pila(tPila * pp);


#endif // PILAESTATICA_H_INCLUDED
