/*
** EPITECH PROJECT, 2022
** task01
** File description:
** task01
*/
#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int i_dest = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i_dest++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
