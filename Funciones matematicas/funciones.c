#include "funciones.h"

double factorial(int n) /// 1
{
    double res = 1;
    if(n==0)
        return 1;
    else
    {
        while(n>1)
        {
             res = res*(double)n;
             n--;
        }
        return res;
    }
}


double numero_combinatorio(int m,int n) /// 2
{
    return (factorial(m))/(factorial(n)*factorial(m-n)); /// factorial devuelve double
}


double valor_abs_double(double num)
{
    return num<0?-1*num:num;
}


double elevar_numero_e(int x,float tol) /// 3  usando termino ya calculado
{
    int den=0;
    double tant,tsig=1,res=0;
    while((valor_abs_double(tsig))>=((double)tol))
    {
        res = res+tsig;
        den++;
        tant = tsig;
        tsig = tant*(((double)x)/((double)den));
    }
    return res;
}


float raiz_cuadrada(float x,float tol) /// 4
{
    float tant,tsig=1;
    do
    {
        tant = tsig;
        tsig = (0.5)*(tant+(x/tant));
    } while((fabs(tant-tsig))>=tol);
    return tant;
}


int pertenece_a_fibonacci(int n) /// 5
{
    int tact=1,tsig=1,nue;
    if(n==1)
        return VERDADERO;
    nue = tact+tsig;
    while(n>nue)
    {
        tact = tsig;
        tsig = nue;
        nue = tact+tsig;
    }
    return n==nue?VERDADERO:FALSO;
}


float seno(float x,float tol) /// 6 (x en radianes)
{
    float tant,tsig=x,res=0;
    int dact=1,den=1;
    while((fabs(tsig))>tol)
    {
        res = res + tsig;
        tant = tsig;
        dact =(den+1)*(den+2);
        tsig = (-1)*tant*((x*x)/((float)dact));
        den+=2;
    }
    return res;
}


int clasif_num_nat(int n) /// 7
{
    int i,res=0;
    for(i=1;i<n;i++)
    {
        if((n%i)==0) /// o if(!(n%i))
            res = res + i; /// o res+=i;
    }
    if(res==n)
        return 3;
    if(res<n)
        return 4;
    return 5;
}


int producto_num_nat(int a,int b)  /// 8
{
    int i,res=0;
    if(a==0 || b==0)
        return 0;
    for(i=1;i<=a;i++)
    {
        res = res+b;
    }
    return res;
}


void cociente_resto(int a, int b,int* c,int* r) /// 9
{
    *c = a/b;
    *r = a%b;
}


int suma_prim_num_nat(int n) /// 10
{
    int i,res=0;
    for(i=1;i<=n;i++)
    {
        res=res+i;
    }
    return res;
}


int suma_prim_num_pares(int n) /// 11
{
    int i,sum=0;
    for(i=1;i<=n;i++)
    {
        sum = sum + (2*i);
    }
    return sum;
}


int suma_prim_num_pares_menores_a_n(int n) /// 12
{
    int i=1,sum=0;
    while((2*i)<n)
    {
        sum = sum + (2*i);
        i++;
    }
    return sum;
}


int es_primo(int n) /// 13  un numero es primo cuando solo es divisible por uno y por si mismo, cuento la cantidad de divisores y deben ser dos
{
    int i,div=0;
    for(i=1; i<=n; i++)
    {
        if((n%i) == 0)
            div++;
    }
    if(div==2)
        return VERDADERO;
    else
        return FALSO;
}


int es_impar(int n)
{
    return (!(n%2))?FALSO:VERDADERO;
}

int multiplicacion_rusa(int a,int b) /// 20
{
    int div=a,mult=b,sum=0;
    while(div >= 1)
    {
        if(es_impar(div))
        {
            sum = sum+mult;
        }
        div = div/2;
        mult = mult*2;
    }
    return sum;
}


int parte_entera(float num) /// 21
{
    int ent = num/1;
    return ent;
}
