/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** isneg
*/


#include <unistd.h>

void my_putchar1(char c)
{
    write(1, &c, 1);
}

void my_isneg(int n )
{
    if ( n < 0)
        my_putchar1('N');
    else if ( n >= 0)
        my_putchar1('P');
}
