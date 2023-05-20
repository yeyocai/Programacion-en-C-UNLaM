#include <stdio.h>
#include <stdlib.h>
#include "ejercicio13.h"

int main()
{
    FILE * pemp,
         * pest;

    t_empleado emp;
    t_estudiante est;

    int comp;

    if(!cargar_archivo_emp("empleados.dat"))
    {
        puts("No se pudo cargar el archivo de empleados.");
        return 1;
    }

    if(!cargar_archivo_est("estudiantes.dat"))
    {
        puts("No se pudo cargar el archivo de estudiantes.");
        return 1;
    }


    pemp = fopen("empleados.dat", "r+b");
    if(!pemp)
    {
        puts("No se pudo abrir el archivo de empleados.");
        return 1;
    }

    pest = fopen("estudiantes.dat", "rb");
    if(!pest)
    {
        puts("No se pudo abrir el archivo de estudiantes.");
        fclose(pemp);
        return 1;
    }

    fread(&emp, sizeof(t_empleado), 1, pemp);
    fread(&est, sizeof(t_estudiante), 1 , pest);

    while(!feof(pemp) && !feof(pest))
    {
        comp = comparar_emp_y_est(&emp, &est);
        if(comp == 0)
        {
            if(est.promedio > 7)
            {
                emp.sueldo += ((emp.sueldo * 7.28) / 100);
                fseek(pemp, (long)-sizeof(t_empleado), SEEK_CUR);
                fwrite(&emp, sizeof(t_empleado), 1, pemp);
                fseek(pemp, 0L, SEEK_CUR);
            }
            fread(&emp, sizeof(t_empleado), 1, pemp);
            fread(&est, sizeof(t_estudiante), 1 , pest);
        }
        else if (comp > 0)
        {
            fread(&est, sizeof(t_estudiante), 1 , pest);
        }
        else /// si comp < 0
        {
            fread(&emp, sizeof(t_empleado), 1, pemp);
        }
    }
    fclose(pemp);
    fclose(pest);

    pemp = fopen("empleados.dat", "rb");
    if(!pemp)
    {
        puts("No se pudo abrir el archivo de empleados.");
        return 1;
    }

    fread(&emp, sizeof(t_empleado), 1, pemp);
    while(!feof(pemp))
    {
        printf("\n%d        %s          %s          %.2f"
               , emp.dni, emp.apellido, emp.nombre, emp.sueldo);
        fread(&emp, sizeof(t_empleado), 1, pemp);
    }

    fclose(pemp);

    return 0;
}
