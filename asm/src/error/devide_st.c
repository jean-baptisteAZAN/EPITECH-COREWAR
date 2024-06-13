/*
** EPITECH PROJECT, 2023
** divide
** File description:
** st
*/

#include "my.h"
#include "asm.h"
#include "op.h"

char **one_str_in_tab(char *str)
{
    char **tab = my_malloc(sizeof(char*) + 1);

    tab[1] = NULL;
    tab[0] = my_malloc(sizeof(char) * my_strlen(str) + 1);
    my_strcpy(tab[0], str);
    tab[0][my_strlen(str)] = '\0';
    return tab;
}

int how_many_until_c(char *str, char s)
{
    if (str == NULL)
        return 0;
    int i = 0;
    for (; str[i] && str[i] != s && str[i] != '\0'; i++);
    return (i);
}

char *get_name_file(char *file_name)
{
    int i = 0;
    int a = 0;
    if (my_strlen(file_name) < 2) {
        my_puterror("Incorect file extension. \".s\" needed.\n");
        exit(84);
    } for (; file_name[a]; a++);
    if (file_name[a - 2] != '.' || file_name[a - 1] != 's') {
        my_puterror("Incorect file extension. \".s\" needed.\n");
        exit(84);
    }
    char *new_file = my_malloc(sizeof(char) * (my_strlen(file_name) + 4));
    my_strncpy(new_file, file_name, my_strlen(file_name) - 2);
    new_file = my_strcat(new_file, ".cor");
    return (reformat_name_file(new_file));
}

char **divide_in_2_str(char *str, char c)
{
    int there_is = 0;
    char **tab = NULL;
    if (str == NULL)
        return NULL;
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            there_is = 1;
    if (there_is == 0)
        tab = one_str_in_tab(str);
    else {
        tab = my_malloc(2 * sizeof(char*) + 1);
        int sep = how_many_until_c(str, c);
        tab[0] = my_malloc((sep * sizeof(char)) + 2);
        tab[1] = my_malloc((my_strlen(str - sep) * sizeof(char)) + 2);
        my_strncpy(tab[0], str, sep);
        tab[0][sep + 1] = '\0';
        my_strcpy(tab[1], &str[sep + 1]);
        tab[1][my_strlen(&str[sep + 1])] = '\0';
    }
    return tab;
}
