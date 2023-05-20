#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))

typedef struct sNodoD
{
    void * info;
    unsigned tamInfo;
    struct sNodoD * sig,
                  * ant;
}tNodoD;

typedef tNodoD * tListaD;



void crearListaD(tListaD* pl);

int ponerOrdListaD(tListaD* pl, const void* pd, unsigned tamDato,
                   int (*cmp)(const void*, const void*));

int sacarOrdListaD(tListaD* pl, void* pd, unsigned tamDato,
                   int (*cmp)(const void*, const void*));

int listaVaciaD(const tListaD* pl);

int listaLlenaD(const tListaD* pl, unsigned tamDato);

int vaciarListaD(tListaD* pl);



#endif // LISTADOBLE_H_INCLUDED
