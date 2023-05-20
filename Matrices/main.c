#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"
#define TAM 50

int main()
{
    int mat7[][TAM]= {{5, 2, 3, 8, 5, 6, 7},
                     {2, 6, 7, 8, 9, 5, 0},
                     {1, 3, 9, 5, 7, 8, 6},
                     {8, 9, 7, 6, 4, 1, 2},
                     {1, 8, 7, 9, 9, 3, 4},
                     {2, 6, 7, 2, 9, 5, 0},
                     {1, 3, 9, 5, 7, 8, 6}};


    printf("Matriz original: \n\n");
    mostrar_matriz_cuadrada(mat7, 7);

    printf("\n\n");
    mostrar_elem_arriba_diag_ppal(mat7, 7);

    printf("\n");
    mostrar_elem_abajo_diag_ppal(mat7, 7);

    printf("\n\n");
    mostrar_elem_arriba_diag_sec(mat7, 7);

    printf("\n\n");
    mostrar_elem_abajo_diag_sec(mat7, 7);

    printf("\n\n");
    mostrar_triangulo_sup(mat7, 7);

    printf("\n\n");
    mostrar_triangulo_der(mat7, 7);

    printf("\n\n");
    mostrar_triangulo_inf(mat7, 7);

    printf("\n\n");
    mostrar_triangulo_izq(mat7, 7);


    return 0;
}
