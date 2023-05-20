#include "fechas.h"

t_fecha ingresarFecha() /// 14
{
    t_fecha fecha;
    puts("\n\nIngrese una fecha (dd/mm/aaaa): ");
    fflush(stdin);
    scanf("%d/%d/%d",&fecha.d,&fecha.m,&fecha.a);
    while(!esFechaValida(fecha))
    {
        puts("FECHA INVALIDA. Por favor, ingrese una fecha valida: ");
        fflush(stdin);
        scanf("%d/%d/%d",&fecha.d,&fecha.m,&fecha.a);
    }
    return fecha;
}


int esFechaValida(t_fecha f)
{
    if(f.a >= 1600)
        if(f.m >= 1 && f.m <= 12)
            if(f.d >= 1 && f.d <= cantDiasMes(f.m,f.a))
                return VERDADERO;
    return FALSO;
}


int cantDiasMes(int m,int a)
{
    static int cdm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2 && esBisiesto(a))
        return 29;
    return cdm[m-1];
}


int esBisiesto(int a)
{
    return (a%4==0 && a%100!=0)||a%400==0;
}


t_fecha DiaSiguienteDeFecha(t_fecha f) /// 15
{
    int cdma = cantDiasMes(f.m,f.a);
    f.d++;
    if(f.d > cdma)
    {
        f.d = 1;
        f.m++;
        if(f.m > 12)
        {
            f.m = 1;
            f.a++;
        }
    }
    return f;
}


int ingresarDias()
{
    int cd;
    puts("Ingrese la cantidad de dias: ");
    fflush(stdin);
    scanf("%d",&cd);
    while(cd<0)
    {
        puts("Por favor, ingrese un numero positivo: ");
        fflush(stdin);
        scanf("%d",&cd);
    }
    return cd;
}


t_fecha sumarDiasAFecha(t_fecha f,int cd) /// 16
{
    int cdma = cantDiasMes(f.m,f.a); /// cdma - cantidad de dias del mes actual
    int cdhmp = cdma - f.d + 1;      /// cdhmp - cantidad de dias hasta el mes proximo, me paro en el primer dia del mes proximo
    while(cd >= cdhmp)
    {
        cd-=cdhmp;
        f.d = 1;
        f = incrementarMes(f);
        cdhmp = cantDiasMes(f.m,f.a);
    }
    f.d+=cd;
    return f;
}


t_fecha incrementarMes(t_fecha f)
{
    f.m++;
    if(f.m > 12)
    {
        f.m = 1;
        f.a++;
    }
    return f;
}

 t_fecha restarDiasAFecha(t_fecha f,int cd) /// 17
 {
     int cdhma = f.d; /// cdhma - cantidad de dias hasta el mes anterior
     while(cd >= cdhma)
     {
         cd-=cdhma;
         f = decrementarMes(f);
         cdhma = cantDiasMes(f.m,f.a);
         f.d = cdhma;
     }
     f.d-=cd;
     return f;
 }

 t_fecha decrementarMes(t_fecha f)
 {
     f.m--;
     if(f.m < 1)
     {
         f.m = 12;
         f.a--;
     }
     return f;
 }


 int cantidadDiasEntreDosFechas(t_fecha f1,t_fecha f2) /// 18
{
    int cd=0,cdma,cdhfm;
    if(f1.m == f2.m && f1.a == f2.a)
        return f2.d - f1.d;
    cdma = cantDiasMes(f1.m,f1.a);    /// cdma - cantidad de dias del mes actual
    cdhfm = cdma - f1.d;              /// cdhfm - cantidad de dias hasta fin de mes

    while(compararMes(f1.m,f1.a,f2.m,f2.a) < 0)
    {
        cd+=cdhfm;
        f1 = incrementarMes(f1);
        cdhfm = cantDiasMes(f1.m,f1.a);
    }
    cd+=f2.d;
    return cd;
}

int compararMes(int m1,int a1,int m2,int a2)
{
    int comp = a1 - a2;
    if(comp != 0)
        return comp;
    return m1-m2;
}


int diaDeLaSemana(t_fecha f) /// 19
{
    t_fecha f1 = {1,1,1601}; /// parto de que el 1/1/1601 fue Lunes - le asigno el cero a Lunes
    return cantidadDiasEntreDosFechas(f1,f)%7;
}
