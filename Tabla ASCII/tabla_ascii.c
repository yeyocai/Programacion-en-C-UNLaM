#include <stdio.h>
#include <stdlib.h>
#include "tabla_ascii.h"

void imprimirAscii()
{
    int i;
    char bin[9];
    puts("Decimal\tHexadecimal\tOctal\tBinario\tCaracter");
    for(i = 33; i <= 126; i++)
    {
        itoa(i, bin, 2);
        printf("\n%d\t%x\t\t%o\t%s\t%c", i, i, i, bin, i);
    }
}
