#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))

typedef struct sNodo /// sNodo: nombre de la estructura - poner struct sNodo es equivalente a poner tNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tPila;


void crear_pila(tPila* pp);

int poner_en_pila(tPila* pp, const void* pd, unsigned tamDato);
int sacar_de_pila(tPila* pp, void* pd, unsigned tamDato);
int ver_tope_pila(const tPila* pp, void* pd, unsigned tamDato);

int pila_vacia(const tPila* pp);
int pila_llena(const tPila* pp, unsigned tamDato);

void vaciar_pila(tPila* pp);


#endif // PILADINAMICA_H_INCLUDED
