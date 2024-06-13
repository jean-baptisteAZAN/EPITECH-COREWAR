/*
** EPITECH PROJECT, 2022
** cat
** File description:
** cat
*/
#include <unistd.h>
#include <stdlib.h>

void* my_malloc(size_t size_malloc);


int my_strlen3(char const *str)
{
    int compt = 0;
    for (; str[compt]; compt++);
    return (compt);
}

char *my_strcat(char const *dest, char const *src)
{
    int i = 0;
    int dest_length = my_strlen3(dest);
    int src_length = my_strlen3(src);
    int total_length = dest_length + src_length;
    char *result = my_malloc(sizeof(char) * (total_length + 1));
    if (result == NULL)
        return NULL;
    for (i = 0; i < dest_length; i++)
        result[i] = dest[i];
    for (i = 0; i < src_length; i++)
        result[dest_length + i] = src[i];
    result[total_length] = '\0';
    return result;
}
