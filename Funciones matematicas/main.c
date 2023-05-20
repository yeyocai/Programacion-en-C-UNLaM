#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int n,m,x,coc,res;
    float a,tol;
    puts("FACTORIAL (n>=0)");
    puts("Ingrese un numero entero n para calcular su factorial: ");
    fflush(stdin);
    scanf("%d",&n);
    if(n<0)
    {
        puts("No se puede calcular el factorial de un numero negativo.");
    }
    else
    {
        printf("El factorial de %d es: %.0f",n,factorial(n));
    }


    puts("\n\nNUMERO COMBINATORIO (m>=n y n>=0)");
    puts("Ingrese un numero entero m: ");
    fflush(stdin);
    scanf("%d",&m);
    puts("Ingrese un numero entero n: ");
    fflush(stdin);
    scanf("%d",&n);
    if(m>=n && n>=0)
    {
        printf("El numero combinatorio de %d sobre %d es: %.0f",m,n,numero_combinatorio(m,n));
    }
    else
    {
        puts("No se puede calcular el numero combinatorio con los valores ingresados.");
    }


    puts("\n\nCALCULO DE e^x con tolerancia TOL");
    puts("Ingrese un numero entero x: ");
    fflush(stdin);
    scanf("%d",&x);
    puts("Ingrese tolerancia TOL: ");
    fflush(stdin);
    scanf("%f",&tol);
    printf("e elevado a la %d es: %f",x,elevar_numero_e(x,tol));


    puts("\n\nRAIZ CUADRADA de x (x>0) con tolerancia TOL");
    puts("Ingrese un numero positivo x: ");
    fflush(stdin);
    scanf("%f",&a);
    puts("Ingrese tolerancia TOL: ");
    fflush(stdin);
    scanf("%f",&tol);
    if(a>=0)
    {
        printf("La raiz cuadrada de %.2f es: %.2f",a,raiz_cuadrada(a,tol));
    }
    else
    {
        puts("No se puede calcular la raiz cuadrada de un numero negativo.");
    }


    puts("\n\nPERTENENCIA DE x (x>0) A SERIE DE FIBONACCI");
    puts("Ingrese un numero positivo x: ");
    fflush(stdin);
    scanf("%d",&x);
    if(x>0)
    {
        if(pertenece_a_fibonacci(x))
            printf("El numero %d pertenece a la serie de Fibonacci.",x);
        else
            printf("El numero %d NO pertenece a la serie de Fibonacci.",x);
    }
    else
    {
        puts("No se ingreso un numero positivo.");
    }


    puts("\n\nCALCULO DE sen(x) con tolerancia TOL");
    puts("Ingrese un numero x (en radianes): ");
    fflush(stdin);
    scanf("%f",&a);
    puts("Ingrese tolerancia TOL: ");
    fflush(stdin);
    scanf("%f",&tol);
    printf("El seno de %f es: %f",a,seno(a,tol));


    puts("\n\nCLASIFICACION DE UN NUMERO NATURAL (n>0)");
    puts("Ingrese un numero natural n: ");
    fflush(stdin);
    scanf("%d",&n);
    if(n>0)
    {
        switch(clasif_num_nat(n))
        {
            case 3:
                printf("El numero %d es PERFECTO",n);
                break;
            case 4:
                printf("El numero %d es DEFICIENTE",n);
                break;
            case 5:
                printf("El numero %d es ABUNDANTE",n);
                break;
        }
    }
    else
    {
        puts("El numero ingresado no es natural.");
    }


    puts("\n\nPRODUCTO POR SUMAS SUCESIVAS (n y m mayores o iguales que cero)");
    puts("Ingrese un numero natural n: ");
    fflush(stdin);
    scanf("%d",&n);
    puts("Ingrese un numero natural m: ");
    fflush(stdin);
    scanf("%d",&m);
    if(n<0 || m<0)
    {
        puts("El/los numeros ingresados son negativos.");
    }
    else
    {
        printf("El producto de ambos es: %d",producto_num_nat(n,m));
    }


    puts("\n\nCOCIENTE ENTERO Y RESTO DE A/B (A>=0 y B>0)"); /// como necesito que me devuelva dos valores use punteros
    puts("Ingrese un numero natural A: ");
    fflush(stdin);
    scanf("%d",&n);
    puts("Ingrese un numero natural B: ");
    fflush(stdin);
    scanf("%d",&m);
    if(n>=0 && m>0)
    {
        cociente_resto(n,m,&coc,&res);
        printf("El cociente entero de %d/%d es %d y su resto es %d",n,m,coc,res);
    }
    else
    {
        puts("No se puede realizar la operacion con los valores ingresados.");
    }


    puts("\n\nCALCULO DE LA SUMA DE LOS PRIMEROS N NUMEROS NATURALES (N>0)");
    puts("Ingrese un numero natural N: ");
    fflush(stdin);
    scanf("%d",&n);
    if(n>0)
    {
        printf("La suma de los primeros %d numeros naturales es: %d",n,suma_prim_num_nat(n));
    }
    else
    {
        puts("No se ingreso un numero natural.");
    }


    puts("\n\nCALCULO DE LA SUMA DE LOS PRIMEROS N NUMEROS PARES (N>0)");
    puts("Ingrese un numero natural N: ");
    fflush(stdin);
    scanf("%d",&n);
    if(n>0)
    {
        printf("La suma de los primeros %d numeros pares es: %d",n,suma_prim_num_pares(n));
    }
    else
    {
        puts("No se ingreso un numero natural.");
    }


    puts("\n\nCALCULO DE LA SUMA DE LOS NUMEROS PARES MENORES QUE N (N>0)");
    puts("Ingrese un numero natural N: ");
    fflush(stdin);
    scanf("%d",&n);
    if(n>0)
    {
        printf("La suma de los numeros pares menores que %d es: %d",n,suma_prim_num_pares_menores_a_n(n));
    }
    else
    {
        puts("No se ingreso un numero natural.");
    }


    puts("\n\nVER SI UN NUMERO NATURAL ES PRIMO (n>0)");
    puts("Ingrese un numero natural n: ");
    fflush(stdin);
    scanf("%d",&n);
    if(n>0)
    {
        if(es_primo(n))
            printf("El numero %d es PRIMO.",n);
        else
            printf("El numero %d NO es PRIMO.",n);
    }
    else
    {
        puts("No se ingreso un numero natural.");
    }


    puts("\n\nMETODO DE MULTIPLICACION RUSA (para 2 numeros naturales)");
    puts("Ingrese un numero natural n: ");
    fflush(stdin);
    scanf("%d",&n);
    puts("Ingrese un numero natural m: ");
    fflush(stdin);
    scanf("%d",&m);
    if(n>0 && m>0)
    {
        printf("%d x %d es: %d",n,m,multiplicacion_rusa(n,m));
    }
    else
    {
        puts("No se ingresaron numeros naturales.");
    }


    puts("\n\nOBTENER LA PARTE ENTERA DE UN NUMERO REAL");
    puts("Ingrese un numero real: ");
    fflush(stdin);
    scanf("%f",&a);
    printf("Su parte entera es: %d",parte_entera(a));


    return 0;
}
