#include "matrices.h"
#define TAM 50
#define MAYOR(X,Y) ((X)>(Y)?(X):(Y))
#define MENOR(X,Y) ((X)<(Y)?(X):(Y))


void mostrar_matriz_cuadrada(int mat[][TAM], int ord)
{
    int i,
        j;

    for(i=0; i<ord; i++)
    {
        for(j=0; j<ord; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}


void mostrar_elem_arriba_diag_ppal(int mat[][TAM], int ord)
{
    int i,
        j;

    for(i=0; i<ord-1; i++)
    {
        printf("%*s", i*3, "");
        for(j=i+1; j<ord; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}


void mostrar_elem_abajo_diag_ppal(int mat[][TAM], int ord)
{
    int i,
        j;

    for(i=1; i<ord; i++)
    {
        for(j=0; j<i; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}


void mostrar_elem_arriba_diag_sec(int mat[][TAM], int ord)
{
    int i,
        j;

    for(i=0; i<ord-1; i++)
    {
        for(j=0; j<ord-i-1; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}


void mostrar_elem_abajo_diag_sec(int mat[][TAM], int ord)
{
    int i,
        j,
        inij;

    for(i=1; i<ord; i++)
    {
        inij = ord-i;
        printf("%*s", inij*3, "");
        for(j=inij; j<ord; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}


void mostrar_triangulo_sup(int mat[][TAM], int ord)
{
    int i,
        j;

    for(i=0; i<ord/2; i++)
    {
        printf("%*s", i*3, "");
        for(j=i+1; j<ord-1-i; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}


void mostrar_triangulo_der(int mat[][TAM], int ord)
{
    int i,
        j,
        inij;

    for(i=1; i<ord-1; i++)
    {
        inij = MAYOR(ord-i, i+1);
        printf("%*s", 3*inij, "");
        for(j=inij; j<ord; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}


void mostrar_triangulo_inf(int mat[][TAM], int ord)
{
    int i,
        j,
        inij;

    for(i=(ord/2)+1; i<ord; i++)
    {
        inij = ord-i;
        printf("%*s", 3*inij, "");
        for(j=inij; j<i; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}


void mostrar_triangulo_izq(int mat[][TAM], int ord)
{
    int i,
        j,
        finj;

    for(i=1; i<ord-1; i++)
    {
        finj = MENOR(ord-i-1, i);
        for(j=0; j<finj; j++) /// o for(j=0; j<i && j<(ord-i-1))
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}
