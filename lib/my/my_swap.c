/*
** EPITECH PROJECT, 2022
** swap
** File description:
** swap
*/

#include <unistd.h>

void my_swap(int *a, int *b)
{
    int garde ;
    garde = *a;
    *a = *b;
    *b = garde;
}
