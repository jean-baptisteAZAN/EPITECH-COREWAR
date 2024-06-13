/*
** EPITECH PROJECT, 2022
** isnum
** File description:
** num
*/
#include <unistd.h>
    int my_strlen(char const *str);

int my_str_isnum(char const *str)
{
    int a = 0;
    for (int i = 0; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            a = 1;
    }
    if (a == 1 || my_strlen(str) == 0)
        return (1);
    else
        return (0);
}
