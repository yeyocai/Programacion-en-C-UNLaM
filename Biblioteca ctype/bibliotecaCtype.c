#include "bibliotecaCtype.h"

int mi_isalnum(int car)
{
    if((car >= 48 && car <= 57) || (car >= 65 && car <= 90) || (car >= 97 && car <= 122))
        return 1;
    return 0;
}


int mi_isalpha(int car)
{
    if((car >= 65 && car <= 90) || (car >= 97 && car <= 122))
        return 1;
    return 0;
}


int mi_isascii(int car)
{
    if(car >= 0 && car <= 127)
        return 1;
    return 0;
}


int mi_iscntrl(int car)
{
    if((car >= 0 && car <= 31) || car == 127)
        return 1;
    return 0;
}


int mi_isdigit(int car)
{
    if(car >= 48 && car <= 57)
        return 1;
    return 0;
}


int mi_isgraph(int car)
{
    if(car >= 33 && car <= 126)
        return 1;
    return 0;
}


int mi_islower(int car)
{
    if(car >= 97 && car <= 122)
        return 1;
    return 0;
}


int mi_isprint(int car)
{
    if(car >= 32 && car <= 126)
        return 1;
    return 0;
}


int mi_ispunct(int car)
{
    if((car >= 33 && car <= 47) || (car >= 58 && car <= 64) || (car >= 91 && car <= 96) || (car >= 123 && car <= 126))
        return 1;
    return 0;
}


int mi_isspace(int car)
{
    if((car >= 9 && car <= 13) || car == 32)
        return 1;
    return 0;
}


int mi_isupper(int car)
{
    if(car >= 65 && car <= 90)
        return 1;
    return 0;
}


int mi_isxdigit(int car)
{
    if((car >= 48 && car <= 57) || (car >= 65 && car <= 70) || (car >= 97 && car <= 102))
        return 1;
    return 0;
}


