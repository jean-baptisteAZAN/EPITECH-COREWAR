/*
** EPITECH PROJECT, 2023
** utils
** File description:
** utils
*/

#include "my.h"
#include "op.h"
#include "asm.h"

int transform_binary_to_decimal(const char *binary)
{
    int length = my_strlen(binary);
    int decimal = 0;
    int power = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }

    return decimal;
}

int get_size_tab(char **tab)
{
    int i = 1;
    for (; tab[i]; i++);
    return (i - 1);
}

bool is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}
