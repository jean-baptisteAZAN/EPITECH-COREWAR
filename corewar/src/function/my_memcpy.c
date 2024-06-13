/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** memcpy
*/

#include <stdbool.h>
#include <stdio.h>

void my_memcpy(void *dest, const void *src, size_t n)
{
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    for (size_t i = 0; i < n; i++)
        cdest[i] = csrc[i];
}
