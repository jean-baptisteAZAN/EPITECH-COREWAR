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
    for (int i = 0; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return 0;
    }
    return (1);
}
