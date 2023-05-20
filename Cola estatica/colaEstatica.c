#include "colaEstatica.h"
#include <string.h>

void crearCola(tCola* pc) /// solo necesito que pri y ult apunten al mismo lugar (puede ser cualquiera: al byte 0, al byte 100)
{
    pc->pri = TAM_COLA - 70; /// aca apunta al byte 230
    pc->ult = TAM_COLA - 70; /// el ultimo es el primero libre
    pc->tamDisp = TAM_COLA;
}


int ponerEnCola(tCola* pc, const void* pd, unsigned tamDato)
{
    int ini, fin; /// tamaños de las partes a copiar partidas

    if((sizeof(unsigned) + tamDato) > pc->tamDisp)
    {
        return 0; /// cola llena
    }

    if((ini = MINIMO(TAM_COLA - pc->ult, sizeof(unsigned))) > 0) /// > 0 porque si estoy parado a lo ultimo, pc->ult = TAM_COLA y la resta me da cero
    {
        memcpy(pc->cola + pc->ult, &tamDato, ini);
    }
    if((fin = sizeof(unsigned) - ini) != 0) /// si tamDato no entro justo al final del vector (si arriba ini = 4)
    {
        memcpy(pc->cola, ((char*)&tamDato) + ini, fin);
    }
    pc->ult = !fin ? pc->ult + sizeof(unsigned) : fin;


    if((ini = MINIMO(TAM_COLA - pc->ult, tamDato)) > 0) /// misma logica para el dato
    {
        memcpy(pc->cola + pc->ult, pd, ini);
    }
    if((fin = tamDato - ini) != 0)
    {
        memcpy(pc->cola, (char*)pd + ini, fin); /// aca no hace falta castear
    }
    pc->ult = !fin ? pc->ult + tamDato : fin;

    pc->tamDisp -= (sizeof(unsigned) + tamDato);

    return 1; /// OK
}


int sacarDeCola(tCola* pc, void* pd, unsigned tamDato)
{
    unsigned tamInfoCola;
    int ini, fin;

    if(pc->tamDisp == TAM_COLA)
        return 0; /// cola vacia
                                                                  /// TAM_COLA - pc->pri: cuantos lugares hay hasta el fin del vector de la cola
    if((ini = MINIMO(TAM_COLA - pc->pri, sizeof(unsigned))) != 0) /// != 0 Porque si estoy parado a lo ultimo, pc->pri = TAM_COLA y la resta me da cero, e ini = 0
    {                                                             /// y tengo que escribir todo el tamInfo entero desde el inicio del vector de cola en tamInfoCola sin trozarlo.
        memcpy(&tamInfoCola, pc->cola + pc->pri, ini);            /// Si tamInfo entra de sobra o justo al final, me da ini = 4, tampoco lo trozo y me salteo fin abajo.
    }
    if((fin = sizeof(unsigned) - ini) != 0) /// Si tamInfo no entro de sobra o justo al final (si arriba ini = 4), lo trozo: hago fin
    {
        memcpy(((char*)&tamInfoCola) + ini, pc->cola, fin);
    }
    pc->pri = fin ? fin : pc->pri + sizeof(unsigned); /// como mucho me queda pc->pri == TAM_COLA


    if((ini = MINIMO(TAM_COLA - pc->pri, tamInfoCola)) != 0) /// misma logica para el dato
    {
        memcpy(pd, pc->cola + pc->pri, MINIMO(ini, tamDato)); /// aca veo tamDato para no pasarme de pd y pisarle info a usuario, tamDato puede ser < que ini
    }
    if((fin = tamInfoCola - ini)!=0 && (tamDato - ini)>0) /// si (tamDato - ini)>0 hay lugar en pd para seguir poniendo cosas: me da cuanto lugar me quedo en pd
    {                                                     /// si (tamDato - ini)<0 no hay mas lugar en pd (encima entro cortado), si (tamDato - ini)=0 entro justo en pd
        memcpy((char*)pd + ini, pc->cola, MINIMO(fin, tamDato - ini));
    }
    pc->pri = fin ? fin : pc->pri + tamInfoCola; /// como mucho me queda pc->pri == TAM_COLA

    pc->tamDisp += (sizeof(unsigned) + tamInfoCola);

    return 1; /// OK
}


int frenteDeCola(const tCola* pc, void* pd, unsigned tamDato)
{
    unsigned tamInfoCola;
    int ini, fin;
    int pos = pc->pri;

    if(pc->tamDisp == TAM_COLA)
        return 0; /// cola vacia

    if((ini = MINIMO(TAM_COLA - pos, sizeof(unsigned))) != 0) /// != 0 porque si estoy parado a lo ultimo, pc->pri = TAM_COLA y la resta me da cero
    {
        memcpy(&tamInfoCola, pc->cola + pos, ini);
    }
    if((fin = sizeof(unsigned) - ini) != 0) /// si tamInfoCola no entro justo al final del vector (si arriba ini = 4)
    {
        memcpy(((char*)&tamInfoCola) + ini, pc->cola, fin);
    }
    pos = fin ? fin : pos + sizeof(unsigned); /// o : pos + ini

    tamInfoCola = MINIMO(tamInfoCola, tamDato);


    if((ini = MINIMO(TAM_COLA - pos, tamInfoCola)) != 0) /// misma logica para el dato
    {
        memcpy(pd, pc->cola + pos, ini); /// aca veo tamDato para no pasarme, tamDato puede ser < que ini
    }
    if((fin = tamInfoCola - ini) != 0) /// si (tam - ini) > 0 hay lugar para seguir poniendo cosas: me da cuanto lugar me quedo en tamDato
    {
        memcpy((char*)pd + ini, pc->cola, fin);
    }

    return 1; /// OK
}


int colaVacia(const tCola* pc)
{
    return pc->tamDisp == TAM_COLA;
}


int colaLlena(const tCola* pc, unsigned tamDato)
{
    return (sizeof(unsigned) + tamDato) > pc->tamDisp;
}


void vaciarCola(tCola* pc)
{
    pc->ult = pc->pri;
    pc->tamDisp = TAM_COLA;
}
