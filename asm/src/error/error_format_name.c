/*
** EPITECH PROJECT, 2023
** fom
** File description:
** format
*/

#include "my.h"
#include "asm.h"
#include "op.h"

char *my_cleanstr(char *str)
{
    int i = 0;
    int j = 0;

    for (; str[i] == ' ' || str[i] == '\t'; i++);
    for (; str[i]; i++) {
        if ((str[i] == ' ' || str[i] == '\t') &&
        (str[i + 1] == ' ' || str[i + 1] == '\t'))
            continue;
        if ((str[i] == ' ' || str[i] == '\t'))
            str[j++] = ' ';
        else
            str[j++] = str[i];
    }
    str[my_strlen(str) > 0 && str[j - 1] == ' ' ? j - 1 : j] = '\0';
    return (str);
}

bool no_slash(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '/')
            return (true);
    }
    return (false);
}

char *get_name_format(char* filename)
{
    size_t len = my_strlen(filename);
    size_t slash_pos = len;
    while (slash_pos > 0 && filename[slash_pos - 1] != '/') {
        slash_pos--;
    }
    if (slash_pos == 0)
        return my_strdup(filename);
    else {
        char* name = my_malloc(len - slash_pos + 1);
        if (name == NULL)
            exit(1);
        size_t i;
        for (i = slash_pos; i <= len; i++)
            name[i - slash_pos] = filename[i];
        return name;
    }
    return (NULL);
}
