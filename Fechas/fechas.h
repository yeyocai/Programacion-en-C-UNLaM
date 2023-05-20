#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define VERDADERO 1
#define FALSO 0

typedef struct
{
    int d;
    int m;
    int a;
}
t_fecha;

t_fecha ingresarFecha();
int esFechaValida(t_fecha f);
int cantDiasMes(int m,int a);
int esBisiesto(int a);
t_fecha DiaSiguienteDeFecha(t_fecha f);
int ingresarDias();
t_fecha sumarDiasAFecha(t_fecha f,int cd);
t_fecha incrementarMes(t_fecha f);
t_fecha restarDiasAFecha(t_fecha f,int cd);
t_fecha decrementarMes(t_fecha f);
int cantidadDiasEntreDosFechas(t_fecha f1,t_fecha f2);
int compararMes(int m1,int a1,int m2,int a2);
int diaDeLaSemana(t_fecha f);




#endif // FECHAS_H_INCLUDED
