/*
** EPITECH PROJECT, 2022
** pustr
** File description:
** putsr
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);
void my_putchar(char c);
void* my_malloc(size_t size_malloc);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

char *int_to_char(int nbr)
{
    int i = 0;
    char tmp;
    char *str = my_malloc(sizeof(char) * 20);

    if (nbr == 0) {
        str[i++] = '0';
    } else {
        while (nbr > 0) {
            str[i++] = (nbr % 10) + '0';
            nbr /= 10;
        }
    }
    str[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        tmp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = tmp;
    }
    return str;
}
