/*
** EPITECH PROJECT, 2022
** caps
** File description:
** caps
*/

char *my_strupcase(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] > 96 && str[i] <= 122)
            str[i] += 32;
    }
    return (str);
}
