/// Normalizar el texto que se encuentra en el archivo "ANormalizar.txt" y guardarlo en el archivo "Normalizado.txt"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ARG_ARCH_ENT 1
#define ARG_ARCH_SAL 2

#define TAM_LINEA 501

#define TODO_OK 0
#define ERROR_ARCH 1

#define VERDADERO 1
#define FALSO 0

typedef struct
{
    char* cursor;
    int finSecuencia;
}
SecuenciaPal;

typedef struct
{
    char* ini;
    char* fin;
}
Palabra;


char* normalizar(const char* aNormalizar, char* normalizada);
void crearSecuencia(SecuenciaPal* sec, char* cad);
Palabra* leerPalabra(SecuenciaPal* sec, Palabra* palabra);
Palabra* escribirPalabra(SecuenciaPal* sec, Palabra* palabra, Palabra* palabraDest);
void formatearPalabra(Palabra* palabra);
int finSecuencia(const SecuenciaPal* sec);
void escribirCaracter(SecuenciaPal* sec, char car);
void reposicionarCursor(SecuenciaPal* sec, int offset);
char aMayuscula(char car);
char aMinuscula(char car);
int esLetra(char car);


/// Parametros: clase15_05 ANormalizar.txt Normalizado.txt
int main(int argc, char* argv[])
{
    FILE* aNormalizarA = fopen(argv[ARG_ARCH_ENT], "rt");
    if(!aNormalizarA)
    {
        puts("Error abriendo archivo entrada.");
        return ERROR_ARCH;
    }


    FILE* normalizadoA = fopen(argv[ARG_ARCH_SAL], "wt");
    if(!normalizadoA)
    {
        puts("Error abriendo archivo salida.");
        return ERROR_ARCH;
    }

    char linea[TAM_LINEA];
    char lineaNorm[TAM_LINEA];

    while(fgets(linea, TAM_LINEA, aNormalizarA)); /// si puede leer, devuelve la direccion del vector que le pasé, sino devuelve null
    {
        normalizar(linea, lineaNorm);
        fputs(lineaNorm, normalizadoA); /// graba en archivo pero no pone \n al final
        fputc('\n', normalizadoA); /// solo graba un caracter
    }
    fclose(aNormalizarA);
    fclose(normalizadoA);

    return 0;
}



char* normalizar(const char* aNormalizar, char* normalizada)
{
    SecuenciaPal secOrig, secDest;

    crearSecuencia(&secOrig, (char*)aNormalizar); /// el parametro que paso lo recibi como const, deberia pasarlo tambien como const, pero despues lo voy a modificar, asi que lo casteo a no const
    crearSecuencia(&secDest, normalizada);

    Palabra palabra, palabraDest;

    leerPalabra(&secOrig, &palabra);

    while(!finSecuencia(&secOrig))
    {
        escribirPalabra(&secDest, &palabra, &palabraDest);
        formatearPalabra(&palabraDest); /// me la formatea en la cadena destino, no toco la original, para eso uso palabraDest
        escribirCaracter(&secDest, ' ');
        leerPalabra(&secOrig, &palabra);
    }
    reposicionarCursor(&secDest, -1); /// desde donde estoy vuelvo una posicion para atras, para sacar el ultimo espacio que puse, que estaria de mas
    escribirCaracter(&secDest, '\0');

    return normalizada;
}


void crearSecuencia(SecuenciaPal* sec, char* cad)
{
    sec->cursor = cad;
    sec->finSecuencia = FALSO;
}


Palabra* leerPalabra(SecuenciaPal* sec, Palabra* palabra)
{
    while(*sec->cursor && !esLetra(*sec->cursor)) /// o *sec->cursor != '\0', el codigo ascii del \0 es cero
        sec->cursor++;

    if(!*sec->cursor)
    {
        sec->finSecuencia = VERDADERO;
        return NULL;
    }

    palabra->ini = sec->cursor;

    while(*sec->cursor && esLetra(*sec->cursor))
        sec->cursor++;

    palabra->fin = sec->cursor - 1;

    return palabra;
}


Palabra* escribirPalabra(SecuenciaPal* sec, Palabra* palabra, Palabra* palabraDest)
{
    char* act;
    palabraDest->ini = sec->cursor;

    for(act = palabra->ini; act <= palabra->fin; act++, sec->cursor++) /// en el for puedo incrementar varias sentencias
        *sec->cursor = *act; /// copio letras

    palabraDest->fin = sec->cursor - 1;

    return palabraDest;
}


void formatearPalabra(Palabra* palabra)
{
    *palabra->ini = aMayuscula(*palabra->ini); /// como toUpper()
    char* act;

    for(act = palabra->ini + 1; act <= palabra->fin; act++)
        *act = aMinuscula(*act);
}


int finSecuencia(const SecuenciaPal* sec)
{
    return sec->finSecuencia;
}


void escribirCaracter(SecuenciaPal* sec, char car)
{
    *sec->cursor = car;
    sec->cursor++; /// deberia verificar que no me pase del limite del vector
}


void reposicionarCursor(SecuenciaPal* sec, int offset)
{
    sec->cursor += offset; /// habria que validar que no se pase del vector - tendria que guardar inicio y fin en estructura de secuencia y verificar que no se pase de los limites con el offset
}


char aMayuscula(char car) /// tiene que estar en minuscula
{
    if(car > 'a' && car < 'z')
        return car - ('a' - 'A'); /// las mayusculas estan primero - distancia 32 - resto letras para no aprender distacia de memoria, estan todas a la misma distancia de su mayuscula

    return car;
}


char aMinuscula(char car) /// tiene que estar en mayuscula
{
    if(car > 'A' && car < 'Z')
        return car + ('a' - 'A');

    return car;
}

int esLetra(char car)
{
    return (car >= 'a' && car <= 'z') || (car >= 'A' && car <= 'Z'); /// los parentesis no son necesarios pero los pongo para sacar el warning, el && tiene prcedencia sobre el ||
}
