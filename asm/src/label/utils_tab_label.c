/*
** EPITECH PROJECT, 2023
** util_label.c
** File description:
** Function utils for label
*/

#include "my.h"
#include "op.h"
#include "asm.h"

char *cut_beg_string(char *str, int cut)
{
    cut++;
    if (cut < 0 || cut >= my_strlen(str)) {
        str[0] = '\0';
        return str;
    }
    for (int i = 0; i < my_strlen(str) - cut; i++)
        str[i] = str[i + cut];
    str[my_strlen(str) - cut] = '\0';
    return str;
}

void remove_first_two(char **strings)
{
    for (int i = 0; strings[i + 2] != NULL; i++)
        strings[i] = strings[i + 2];

    int length;
    for (length = 0; strings[length] != NULL; length++);
    strings[length - 2] = NULL;
    strings[length - 1] = NULL;
}

int check_cara_is_label(char str)
{
    char *verif = LABEL_CHARS;
    for (int n = 0; verif[n] != '\0'; n++) {
        if (str == verif[n])
            return 0;
    }
    return disp_error("Error label not good\n");
}
