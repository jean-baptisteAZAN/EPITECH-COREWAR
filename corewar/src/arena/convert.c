/*
** EPITECH PROJECT, 2023
** convert.c
** File description:
** Function for converting from hexadecimal to ...
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

int convert_str_to_int_hexa(char *str, int nb_bytes)
{
    int tmp = 0;
    for (int i = 0; i < nb_bytes; i++) {
        tmp <<= 8;
        tmp += (unsigned char)str[i];
    }

    if (nb_bytes == 2)
        return (short)tmp;
    else
        return tmp;
}

void my_arencpy(void *dest, const void *src, size_t n)
{
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    for (size_t i = 0; i < n; i++)
        cdest[mod(i)] = csrc[mod(i)];
}
