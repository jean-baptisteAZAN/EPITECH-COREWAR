/*
** EPITECH PROJECT, 2022
** isalpha
** File description:
** alpha
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        for (;(str[i] < 65 || str[i] > 90) &&
        (str[i] < 97 || str[i] > 122) ; i++)
        return 0;
    }
    return 1;
}
