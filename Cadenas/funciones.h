#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAM 100

void primera_palabra(const char *texto, char *primera);
int cuantas_veces_aparece(const char *texto, const char *palabra);
int cuantas_palabras_tiene_el_texto(const char * texto);
int longitud_de_la_palabra_mas_larga(const char * texto);

void invertir_in_situ(char * cad);
char* normalizar(char * cad);

#endif // FUNCIONES_H_INCLUDED
