/*
** EPITECH PROJECT, 2023
** utils_excute.c
** File description:
** Player the full champions
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

int get_size_tab(int *tab)
{
    int size = 0;
    for (int i = 0; tab[i]; i++)
        size++;
    return size;
}

int check_list(char *str, char **tab)
{
    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], str) == 0)
            return 1;
    }
    return 0;
}

short int short_big_endian(short int value)
{
    return ((value >> 8) & 0xFF) | ((value << 8) & 0xFF00);
}

void my_corecpy(void *dest, const void *src, size_t n)
{
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    for (size_t i = 0; i < n; i++)
        cdest[mod(i)] = csrc[mod(i)];
}
