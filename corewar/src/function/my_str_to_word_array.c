/*
** EPITECH PROJECT, 2022
** str
** File description:
** str
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void* my_malloc(size_t size);

void my_putchar(char c);
int my_putstr(char const *str);
char *my_strncpy(char *dest, char const *src, int n);

int cpt_mots(char const *str, char separateur)
{
    int cpt = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separateur) {
            cpt++;
        }
    }
    return (cpt + 1);
}

int cpt_lettres(char const *str, int i, char separateur)
{
    int cpt = 0;
    for (; str[i] != separateur && str[i] != '\0'; cpt++, i++);
    return cpt;
}

char **my_str_to_word_array(char const *str, char separateur)
{
    int len_mots = cpt_mots(str, separateur);
    int x = 0;
    int y = 0;
    char **arr = my_malloc(sizeof(char*) * (len_mots + 1));
    if (arr == NULL)
        return NULL;
    for (int i = 0; i < len_mots; i++) {
        x = cpt_lettres(str, y, separateur);
        arr[i] = my_malloc(sizeof(char) * (x + 1));
        for (int cpt = 0; cpt < x; cpt++, y++)
            arr[i][cpt] = str[y];
        arr[i][x] = '\0';
        y++;
    }
    arr[len_mots] = NULL;
    return arr;
}
