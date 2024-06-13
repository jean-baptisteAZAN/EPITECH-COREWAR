/*
** EPITECH PROJECT, 2022
** char
** File description:
** char**
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

void* my_malloc(size_t size_malloc);
char *my_strdup(char const *src);

char **my_chardup(char **str, char **src)
{
    int i = 0;
    int cpt = 0;
    for (; src[cpt]; cpt++);
    str = my_malloc(sizeof(char *) * (cpt + 1));
    for (; src[i]; i++) {
        str[i] = my_strdup(src[i]);
    }
    str[i] = NULL;
    return (str);
}
