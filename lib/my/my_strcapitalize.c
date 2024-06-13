/*
** EPITECH PROJECT, 2022
** capitalize
** File description:
** capita
*/

void strlowcase(char *str)
{
    int i = 0;
    for (;str[i] != '\0'; i++) {
        if (str[i] > 64 && str[i] <= 90)
            str[i] += 32;
    }
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    strlowcase(str);
    for (; str[i] != '\0'; i++) {
        if ((str[i - 1] < 49 || str[i - 1] > 59) &&
            (str[i - 1] < 65 || str[i - 1] > 90) &&
            (str[i - 1] < 95 || str[i - 1] > 122) &&
            (str[i] <= 122 && str[i] >= 97))
            str[i] -= 32;
    }
    return (str);
}
