#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))
#define TAM_COLA 300

typedef struct
{
    char cola[TAM_COLA];
    unsigned pri, /// subindice
             ult, /// subindice
             tamDisp; /// para saber si el que quiero poner entra (lo podria calcular con pri y ult pero con muchas cuentas)
}tCola;

void crearCola(tCola* pc);

int ponerEnCola(tCola* pc, const void* pd, unsigned tamDato);
int sacarDeCola(tCola* pc, void* pd, unsigned tamDato);

int frenteDeCola(const tCola* pc, void* pd, unsigned tamDato);

int colaVacia(const tCola* pc);
int colaLlena(const tCola* pc, unsigned tamDato);

void vaciarCola(tCola* pc);


#endif // COLAESTATICA_H_INCLUDED
