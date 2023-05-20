#include <string.h>
#include "funciones.h"
#include "cadenas.h"

void primera_palabra(const char * texto, char * primera)
{
    while(*texto != ' ')
    {
        *primera = *texto;
        primera++;
        texto++;
    }
    *primera = '\0';
}


int cuantas_veces_aparece(const char * texto, const char * palabra)
{
    char aux[TAM],
         * paux = aux;

    int cant = 0,
        i;

    while(*texto != '.') /// o *texto != '\0'
    {
        i = 0;
        while(*texto != '.' && *texto != ' ')
        {
            *paux = *texto;
            i++;

            paux++;
            texto++;
        }
        *paux = '\0';
        paux -= i*sizeof(char);

        if(mi_strcmp(paux, palabra) == 0)
            cant++;

        if(*texto != '.')
            texto++;
    }
    return cant;
}


int cuantas_palabras_tiene_el_texto(const char * texto)
{
    int cant = 0;

    while(*texto != '.') /// o *texto != '\0'
    {
        while(*texto != '.' && *texto != ' ')
        {
            texto++;
        }
        cant++;

        if(*texto != '.')
            texto++;
    }
    return cant;
}


int longitud_de_la_palabra_mas_larga(const char * texto)
{
    int cant_letras_pal_act;
    int cant_letras_pal_mas_larga = 0;

    while(*texto != '.') /// o *texto != '\0'
    {
        cant_letras_pal_act = 0;
        while(*texto != '.' && *texto != ' ')
        {
            cant_letras_pal_act++;
            texto++;
        }
        if(cant_letras_pal_act > cant_letras_pal_mas_larga)
            cant_letras_pal_mas_larga = cant_letras_pal_act;

        if(*texto != '.')
            texto++;
    }
    return cant_letras_pal_mas_larga;
}


/// $. hOLa $.#	qUe$.#	taL&.#
char* normalizar(char * cad)
{
    char * lect = cad,
         * esc = cad;

    int primeraLetraPalabra;

    while(*lect)
    {
        while(!es_letra(*lect) && *lect)
            lect++;

        if(*lect)
        {
            primeraLetraPalabra = 1;
            while(*lect && es_letra(*lect))
            {
                *esc = primeraLetraPalabra ? aMayuscula(*lect) : aMinuscula(*lect);
                primeraLetraPalabra = 0;
                lect++;
                esc++;
            }
            *esc = ' ';
            esc++;
        }
    }
    esc--;
    *esc = '\0';
    return cad;
}


/// "Esta es la materia Programacion";
void invertir_in_situ(char * cad)
{
    char * ini,
         * fin,
         aux;

    while(*cad)
    {
        ini = cad;

        while(*cad != ' ' && *cad != '\0')
        {
            cad++;
        }
        cad--;
        fin = cad;
        while(ini < fin)
        {
            aux = *ini;
            *ini = *fin;
            *fin = aux;

            ini++;
            fin--;
        }
        cad++;

        if(*cad)
            cad++;
    }
}
