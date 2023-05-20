#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define TAM 8
#define VECTOR_LLENO -1
#define DUPLICADO -2

int insertarElementoEnPosicion(int v[],int elem,int ce,int pos,int cap);
int insertarElementoEnOrdenAscendente(int v[],int elem,int ce,int cap);
int eliminarElementoPorPosicion(int v[],int ce,int pos);
int eliminarPrimerAparicionDeElemento(int v[],int ce,int elem);
int eliminarTodasLasAparicionDeUnElemento(int v[],int ce,int elem);


#endif // VECTORES_H_INCLUDED
