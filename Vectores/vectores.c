#include "vectores.h"

int insertarElementoEnPosicion(int v[],int elem,int ce,int pos,int cap) /// 22
{
    int i;
    if(ce == cap)
        return VECTOR_LLENO;
    if(pos<0 || pos>ce)
        return -3;
    for(i=ce-1;i>=pos;i--)
        v[i+1] = v[i];
    v[pos] = elem;
    return ce+1;
}


int insertarElementoEnOrdenAscendente(int v[],int elem,int ce,int cap) /// 23 sin duplicados
{
    int i=0,j;
    if(ce == cap)
        return VECTOR_LLENO;
    while(i<ce && v[i]<elem)
        i++;
    if(v[i] == elem)
        return DUPLICADO;
    for(j=ce-1;j>=i;j--)
    {
        v[j+1]=v[j];
    }
    v[i]=elem;
    return ce+1;
}


int eliminarElementoPorPosicion(int v[],int ce,int pos) /// 24
{
    int i;
    for(i=pos;i<ce-1;i++)
        v[i] = v[i+1];
    return ce-1;
}


int eliminarPrimerAparicionDeElemento(int v[],int ce,int elem) /// 25
{
    int i=0,j;
    while(v[i] != elem)
        i++;
    for(j=i;j<ce-1;j++)
        v[j] = v[j+1];
    return ce-1;
}


int eliminarTodasLasAparicionDeUnElemento(int v[],int ce,int elem) /// 26
{
    int i,j;
    for(i=0;i<ce;i++)
    {
        if(elem == v[i])
        {
            for(j=i;j<ce-1;j++)
            {
                v[j] = v[j+1];
            }
            ce--;
            i--;
        }
    }
    return ce;
}

