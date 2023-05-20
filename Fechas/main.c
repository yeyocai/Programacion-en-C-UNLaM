#include <stdio.h>
#include <stdlib.h>
#include "fechas.h"

int main()
{
    t_fecha f,f1,f2;
    int cd;
    f = ingresarFecha();

    printf("La fecha %d/%d/%d es correcta.",f.d,f.m,f.a);
    f = DiaSiguienteDeFecha(f);
    printf("\n\nLa fecha correspondiente al dia siguiente es %d/%d/%d",f.d,f.m,f.a);

    f = ingresarFecha();
    cd = ingresarDias();
    f = sumarDiasAFecha(f,cd);
    printf("SUMA: La fecha resultante es %d/%d/%d",f.d,f.m,f.a);

    f = ingresarFecha();
    cd = ingresarDias();
    f = restarDiasAFecha(f,cd);
    printf("RESTA: La fecha resultante es %d/%d/%d",f.d,f.m,f.a);

    puts("\n\nCANTIDAD DE DIAS ENTRE DOS FECHAS.\nPor favor, ingrese primero la fecha menor y luego la fecha mayor.");
    puts("Fecha menor");
    f1 = ingresarFecha();
    puts("Fecha mayor");
    f2 = ingresarFecha();
    cd = cantidadDiasEntreDosFechas(f1,f2);
    printf("La cantidad de dias entre esas dos fechas es: %d",cd);

    puts("\n\nDIA DE LA SEMANA");
    f = ingresarFecha();
    switch(diaDeLaSemana(f))
    {
        case 0: puts("La fecha corresponde al dia Lunes.");
                break;
        case 1: puts("La fecha corresponde al dia Martes.");
                break;
        case 2: puts("La fecha corresponde al dia Miercoles.");
                break;
        case 3: puts("La fecha corresponde al dia Jueves.");
                break;
        case 4: puts("La fecha corresponde al dia Viernes.");
                break;
        case 5: puts("La fecha corresponde al dia Sabado.");
                break;
        case 6: puts("La fecha corresponde al dia Domingo.");
                break;
    }

    return 0;
}
