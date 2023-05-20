#include "ejercicio13.h"

int cargar_archivo_emp(char * path)
{
    FILE * pf;
    t_empleado emp_vec[] = {{11, "Alvarez", "Matias", 30000.52},
                            {66, "Alvarez", "Rosa", 40000.63},
                            {33, "Barreda", "Lucio", 45000.36},
                            {44, "Barreda", "Lucio", 55000.36},
                            {99, "Fernandez", "Jose", 70000.36},
                            {77, "Fernandez", "Zulma", 55000.01},
                            {55, "Saa", "Natalia", 30000.36}};

    pf = fopen(path, "wb");
    if(!pf) /// o if(pf == NULL)
    {
        return 0;
    }
    fwrite(emp_vec, sizeof(t_empleado), 7, pf);
    fclose(pf);

    return 1;
}

int cargar_archivo_est(char * path)
{
    FILE * pf;
    t_estudiante est_vec[] = {{10, "Abuin", "Jose", 6.5},
                              {66, "Alvarez", "Rosa", 8.3},
                              {23, "Aparicio", "Luis", 8.6},
                              {44, "Barreda", "Lucio", 6.3},
                              {88, "Diaz", "Claudio", 5.3},
                              {77, "Fernandez", "Zulma", 7.5},
                              {55, "Saa", "Natalia", 9.6}};
    pf = fopen(path, "wb");
    if(!pf)
    {
        return 0;
    }
    fwrite(est_vec, sizeof(t_estudiante), 6, pf);
    fclose(pf);

    return 1;
}


int comparar_emp_y_est(t_empleado * emp, t_estudiante * est)
{
    int res;
    if((res = strcmpi(emp->apellido, est->apellido)) == 0 &&
       (res = strcmpi(emp->nombre, est->nombre)) == 0)
    {
        return emp->dni - est->dni;
    }
    return res; /// queda el res correspondiente por lazy compare
 }
