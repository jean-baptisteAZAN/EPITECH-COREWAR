/*
** EPITECH PROJECT, 2022
** task low
** File description:
** low
*/

char *my_strlowcase(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] > 64 && str[i] <= 90)
            str[i] += 32;
    }
    return (str);
}
