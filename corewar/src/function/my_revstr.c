/*
** EPITECH PROJECT, 2022
** evstr
** File description:
** str
*/

#include <unistd.h>

int my_strlen4(char const *str)
{
    int compt = 0;
    int i = 0;
    while (str[i] != '\0') {
        compt++;
        i++;
    }
    return (compt);
}

char *my_revstr(char *str)
{
    int i = 0;
    int garde = str[i];
    while (i != my_strlen4(str) / 2) {
        garde = str[i];
        str[i] = str[my_strlen4(str) -1 -i];
        str[my_strlen4(str) - 1 -i] = garde;
        i++;
    }
    return (str);
}
