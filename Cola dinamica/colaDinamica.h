#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
}tNodo;

typedef struct
{
    tNodo* pri;
    tNodo* ult;
}tCola;


void crearCola(tCola* pc);

int ponerEnCola(tCola* pc, const void* pd, unsigned tamDato);
int sacarDeCola(tCola* pc, void* pd, unsigned tamDato);

int frenteDeCola(const tCola* pc, void* pd, unsigned tamDato);

int colaVacia(const tCola* pc);
int colaLlena(const tCola* pc, unsigned tamDato);

void vaciarCola(tCola* pc);



#endif // COLADINAMICA_H_INCLUDED
