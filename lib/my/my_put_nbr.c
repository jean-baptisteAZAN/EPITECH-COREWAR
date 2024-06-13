/*
** EPITECH PROJECT, 2022
** put bnr
** File description:
** nbr
*/

#include <stdlib.h>
#include <math.h>

void my_putchar(char c);
int my_putstr(char const *str);
void* my_malloc(size_t size_malloc);

int my_nblen(int n)
{
    int cptnb = 0;
    for (; n > 1; cptnb++, n /= 10);
    return cptnb;
}

char *my_put_nbr(float number)
{
    int integer_part = (int)number;
    int buffer_size = 64;
    char *buffer = (char *)my_malloc(buffer_size * sizeof(char));
    int index = 0;
    if (number < 0) {
        buffer[index++] = '-';
        integer_part = -integer_part;
    }
    int divisor = 1;
    while (integer_part / divisor >= 10)
        divisor *= 10;
    while (divisor > 0) {
        buffer[index++] = (integer_part / divisor) % 10 + '0';
        divisor /= 10;
    }
    buffer[index++] = '.';
    buffer[index++] = '0';
    buffer[index] = '\0';
    return buffer;
}

char *my_put_nbr_int(int nb)
{
    int len = my_nblen(nb);
    char *str = my_malloc(sizeof(char) * len + 1);
    int i = 0;
    if (nb == 0)
        return "0";
    if (nb == 1)
        return "1";
    if (nb > 0) {
        str[i] = (nb % 10) + 48;
        nb /= 10;
        i++;
    }
    str[len] = '\0';
    return str;
}
