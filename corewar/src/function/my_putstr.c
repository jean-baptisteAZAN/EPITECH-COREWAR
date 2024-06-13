/*
** EPITECH PROJECT, 2022
** pustr
** File description:
** putsr
*/

#include <unistd.h>

int my_strlen(char const *str);
void my_putchar(char c);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
