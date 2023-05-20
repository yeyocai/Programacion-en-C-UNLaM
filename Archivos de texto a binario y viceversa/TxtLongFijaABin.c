#include "TxtLongFijaABin.h"

int cargar_archivo_de_texto_long_fija(char * path)
{
    FILE * pf;
    int i;

    t_alumno alu_vec[] = {{90, "Sa, Lia", 'F', 7.5,{1,2,2005}, 'A'},
                          {98, "Jose Perez", 'M', 8, {1,2,1999}, 'A'},
                          {110, "Alumno uno", 'F', 7.5, {1,2,2005}, 'I'},
                          {120, "Alumno dos", 'M', 7.5, {1,2,2015}, 'A'},
                          {130, "Alumno tres", 'M', 8, {1,2,2000}, 'A'},
                          {140, "Alumno cuatro", 'F', 7.5, {1,2,1998}, 'A'},
                          {150, "Alumno cinco", 'F', 4, {1,2,1997}, 'A'}};

    pf = fopen(path, "wt");
    if(!pf)
    {
        puts("No se pudo abrir el archivo de texto para escritura.");
        return 0;
    }

    for(i=0; i<7; i++)
    {
        fprintf(pf, "%08d%-29s%c%05.2f%02d%02d%4d%c\n",
                alu_vec[i].dni,
                alu_vec[i].apyn,
                alu_vec[i].sexo,
                alu_vec[i].promedio,
                alu_vec[i].f_ing.d,
                alu_vec[i].f_ing.m,
                alu_vec[i].f_ing.a,
                alu_vec[i].estado);
    }

    fclose(pf);
    return 1;
}


void sacar_espacios(char * texto)
{
    int esp = 0;

    while(*texto != ' ' || esp < 1)
    {
        if(*texto == ' ')
            esp++;

        texto++;
    }
    *texto = '\0';
}
