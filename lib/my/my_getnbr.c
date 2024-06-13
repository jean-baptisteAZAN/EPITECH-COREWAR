/*
** EPITECH PROJECT, 2022
** yes
** File description:
** yes
*/

int	my_getnbr(char const *str)
{
    int stop = 0;
    long nbr = 0;
    int negative = 1;
    for (int i = 0; str[i] != '\0' && stop == 0; i++) {
        if (str[i] == 45)
            negative *= (-1);
        if (str[i] >= 48 && str[i] <= 57)
            nbr = nbr * 10 + (str[i] - 48);
        nbr *= negative;
        if (nbr < -2147483648 || nbr > 2147483647)
            return (0);
        nbr *= negative;
    }
    return (nbr * negative);
}
