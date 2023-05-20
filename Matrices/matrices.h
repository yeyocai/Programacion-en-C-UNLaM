#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAM 50

void mostrar_matriz_cuadrada(int mat[][TAM], int ord);
void mostrar_elem_arriba_diag_ppal(int mat[][TAM], int ord);
void mostrar_elem_abajo_diag_ppal(int mat[][TAM], int ord);
void mostrar_elem_arriba_diag_sec(int mat[][TAM], int ord);
void mostrar_elem_abajo_diag_sec(int mat[][TAM], int ord);
void mostrar_triangulo_sup(int mat[][TAM], int ord);
void mostrar_triangulo_der(int mat[][TAM], int ord);
void mostrar_triangulo_inf(int mat[][TAM], int ord);
void mostrar_triangulo_izq(int mat[][TAM], int ord);


#endif // MATRICES_H_INCLUDED
