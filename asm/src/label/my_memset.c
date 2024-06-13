/*
** EPITECH PROJECT, 2023
** lib
** File description:
** memset
*/

#include <stddef.h>

void *my_memset(void *ptr, int value, size_t num)
{
    unsigned char *p = ptr;

    while (num--)
        *p++ = (unsigned char)value;
    return ptr;
}
