/// Pasar un archivo de texto de longitud fija a un archivo binario.
/// Pasar ese archivo binario a un archivo de texto de longitud variable

#include <stdio.h>
#include <stdlib.h>
#include "TxtLongFijaABin.h"

int main()
{

    FILE * ptxt_fij,
         * pbin,
         * ptxt_var;

    int res;
    t_alumno alu;

    if(!cargar_archivo_de_texto_long_fija("alumnosLongFija.txt"))
    {
        puts("No se pudo cargar el archivo de texto de longitud fija.");
        return 1;
    }

    ptxt_fij = fopen("alumnosLongFija.txt","rt");
    if(!ptxt_fij)
    {
        puts("No se pudo abrir el archivo de texto para lectura.");
        return 2;
    }

    pbin = fopen("alumnos.dat","wb");
    if(!pbin)
    {
        puts("No se pudo abrir el archivo binario para escritura.");
        fclose(ptxt_fij);
        return 3;
    }

    res = fscanf(ptxt_fij, "%8d%29[^\n]%c%5f%2d%2d%4d%c\n",
                &alu.dni,
                alu.apyn,
                &alu.sexo,
                &alu.promedio,
                &alu.f_ing.d,
                &alu.f_ing.m,
                &alu.f_ing.a,
                &alu.estado);

    while(res != EOF)
    {
        sacar_espacios(alu.apyn);
        fwrite(&alu, sizeof(t_alumno), 1, pbin);

        res = fscanf(ptxt_fij, "%8d%29[^\n]%c%5f%2d%2d%4d%c\n",
                &alu.dni,
                alu.apyn,
                &alu.sexo,
                &alu.promedio,
                &alu.f_ing.d,
                &alu.f_ing.m,
                &alu.f_ing.a,
                &alu.estado);
    }

    fclose(ptxt_fij);
    fclose(pbin);


    pbin = fopen("alumnos.dat","rb"); /// muestro archivo binario
    if(!pbin)
    {
        puts("No se pudo abrir el archivo binario para lectura.");
        return 5;
    }

    fread(&alu, sizeof(t_alumno), 1, pbin);
    while(!feof(pbin))
    {
        printf("\n%d %s %c %.2f %02d/%02d/%d %c\n", alu.dni, alu.apyn,
               alu.sexo, alu.promedio, alu.f_ing.d, alu.f_ing.m,
               alu.f_ing.a, alu.estado);
        fread(&alu, sizeof(t_alumno), 1, pbin);
    }

    fclose(pbin);


    pbin = fopen("alumnos.dat","rb");
    if(!pbin)
    {
        puts("No se pudo abrir el archivo binario para lectura.");
        return 5;
    }

    ptxt_var = fopen("alumnosLongVar.txt", "wt");
    if(!ptxt_var)
    {
        puts("No se pudo abrir el archivo de texto para escritura.");
        fclose(pbin);
        return 6;
    }

    fread(&alu, sizeof(t_alumno), 1, pbin);
    while(!feof(pbin))
    {
        fprintf(ptxt_var, "%d|%s|%c|%.2f|%02d/%02d/%d|%c\n",
                alu.dni,
                alu.apyn,
                alu.sexo,
                alu.promedio,
                alu.f_ing.d,
                alu.f_ing.m,
                alu.f_ing.a,
                alu.estado);

        fread(&alu, sizeof(t_alumno), 1, pbin);
    }

    fclose(pbin);
    fclose(ptxt_var);


    return 0;
}
