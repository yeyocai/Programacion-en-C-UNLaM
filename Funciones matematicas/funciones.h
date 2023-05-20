#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define VERDADERO 1
#define FALSO 0

double factorial(int n);
double numero_combinatorio(int m,int n);
double valor_abs_double(double num);
double elevar_numero_e(int x,float tol);
float raiz_cuadrada(float x,float tol);
int pertenece_a_fibonacci(int n);
float seno(float x,float tol);
int clasif_num_nat(int n);
int producto_num_nat(int a,int b);
void cociente_resto(int a, int b,int* c,int* r);
int suma_prim_num_nat(int n);
int suma_prim_num_pares(int n);
int suma_prim_num_pares_menores_a_n(int n);
int es_primo(int n);
int es_impar(int n);
int multiplicacion_rusa(int a,int b);
int parte_entera(float num);




#endif // FUNCIONES_H_INCLUDED
