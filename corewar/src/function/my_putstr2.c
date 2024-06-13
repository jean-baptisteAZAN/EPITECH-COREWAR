/*
** EPITECH PROJECT, 2022
** putstr2
** File description:
** 2
*/

int my_strlen(char const *str);

void my_putchar(char c);

int my_putnbr_base(unsigned int nbr, char const *base);

int my_putstr2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 32 && str[i] < 127) {
            my_putchar(str[i]);
            i++;
        } else {
            my_putchar(92);
            my_putnbr_base(str[i], "01234567");
            i++;
        }
    }
    return my_strlen(str);
}
