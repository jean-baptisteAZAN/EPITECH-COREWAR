/*
** EPITECH PROJECT, 2022
** strncpy
** File description:
** task02
*/

#include <unistd.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int i_dest = 0;
    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i_dest++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
