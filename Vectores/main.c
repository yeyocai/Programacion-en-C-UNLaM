#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define TAM 8

int main()
{
    int vec[TAM] = {1,3,5,7}; /// 22
    int ce=4,i,elem,pos;
    printf("VECTOR:");
    for(i=0;i<ce;i++)
    {
        printf("\n%d",vec[i]);
    }
    printf("\nCantidad de elementos: %d",ce);
    puts("\n\nIngrese elemento a insertar: ");
    fflush(stdin);
    scanf("%d",&elem);
    puts("\nIngrese posicion: ");
    fflush(stdin);
    scanf("%d",&pos);
    ce = insertarElementoEnPosicion(vec,elem,ce,pos,TAM);
    if(ce == -1)
    {
        puts("VECTOR LLENO. No se puede insertar el elemento.");
    }
    else
    {
        printf("\nNUEVO VECTOR:");
        for(i=0;i<ce;i++)
        {
            printf("\n%d",vec[i]);
        }
        printf("\nCantidad de elementos: %d\n",ce);
    }


/// Voy descomentando el ejercicio que quiero ejecutar:

    /*int vec[TAM] = {1,3,5,7}; /// 23
    int ce=4,i,elem;
    printf("VECTOR:");
    for(i=0;i<ce;i++)
    {
        printf("\n%d",vec[i]);
    }
    printf("\nCantidad de elementos: %d",ce);
    puts("\n\nIngrese elemento a insertar: ");
    fflush(stdin);
    scanf("%d",&elem);
    ce = insertarElementoEnOrdenAscendente(vec,elem,ce,TAM);
    switch(ce)
    {
        case -1:
            puts("VECTOR LLENO. No se puede insertar el elemento.");
            break;
        case -2:
            puts("ELEMENTO DUPLICADO. No se puede insertar el elemento.");
            break;
        default:
            printf("\nNUEVO VECTOR:");
            for(i=0; i<ce; i++)
            {
                printf("\n%d",vec[i]);
            }
            printf("\nCantidad de elementos: %d\n",ce);
    }*/



    /*int vec[TAM] = {1,3,5,7}; /// 24
    int ce=4,i,pos;
    printf("VECTOR:");
    for(i=0;i<ce;i++)
    {
        printf("\n%d",vec[i]);
    }
    printf("\nCantidad de elementos: %d",ce);
    puts("\nIngrese posicion a eliminar: ");
    fflush(stdin);
    scanf("%d",&pos);
    ce = eliminarElementoPorPosicion(vec,ce,pos);
    printf("\nNUEVO VECTOR:");
    for(i=0;i<ce;i++)
    {
        printf("\n%d",vec[i]);
    }
    printf("\nCantidad de elementos: %d\n",ce);*/



    /*int vec[TAM] = {1,5,3,5}; /// 25
    int ce=4,i,elem;
    puts("ELIMINAR LA PRIMERA APARICION DE UN ELEMENTO");
    printf("VECTOR:");
    for(i=0;i<ce;i++)
    {
        printf("\n%d",vec[i]);
    }
    printf("\nCantidad de elementos: %d",ce);
    puts("\nIngrese elemento a eliminar: ");
    fflush(stdin);
    scanf("%d",&elem);
    ce = eliminarPrimerAparicionDeElemento(vec,ce,elem);
    printf("\nNUEVO VECTOR:");
    for(i=0;i<ce;i++)
    {
        printf("\n%d",vec[i]);
    }
    printf("\nCantidad de elementos: %d\n",ce);*/



    /*int vec[TAM] = {3,1,3,3,5,3}; /// 26
    int ce=6,i,elem;
    puts("ELIMINAR TODAS LAS APARICIONES DE UN ELEMENTO");
    printf("VECTOR:");
    for(i=0;i<ce;i++)
    {
        printf("\n%d",vec[i]);
    }
    printf("\nCantidad de elementos: %d",ce);
    puts("\n\nIngrese elemento a eliminar: ");
    fflush(stdin);
    scanf("%d",&elem);
    ce = eliminarTodasLasAparicionDeUnElemento(vec,ce,elem);
    printf("\nNUEVO VECTOR:");
    for(i=0;i<ce;i++)
    {
        printf("\n%d",vec[i]);
    }
    printf("\nCantidad de elementos: %d\n",ce);*/


    return 0;
}


