/*
** EPITECH PROJECT, 2023
** error
** File description:
** erro
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_puterror(char const *str)
{
    write(2, str, my_strlen(str));
}
