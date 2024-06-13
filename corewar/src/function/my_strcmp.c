/*
** EPITECH PROJECT, 2022
** strncmp
** File description:
** strncmp
*/

#include <unistd.h>

int size_str(char *str)
{
    int n = 0;
    for (; str[n] != '\0'; n++);
    return n;
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    if (size_str(s1) != size_str(s2))
        return 1;
    for (;((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')); i++);
    return (s1[i] - s2[i]);
}
