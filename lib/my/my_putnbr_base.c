/*
** EPITECH PROJECT, 2022
** conv
** File description:
** binaire
*/

int my_strlen(char const *str);
void my_putchar(char c);

static void negative_situation(unsigned int *nb)
{
    if (*nb < 0) {
        my_putchar('-');
        *nb *= -1;
    }
}

int my_putnbr_base(unsigned int nbr, char const *base)
{
    negative_situation(&nbr);
    if (nbr >= my_strlen(base)) {
        my_putnbr_base(nbr / my_strlen(base), base);
        my_putnbr_base(nbr % my_strlen(base), base);
    } else {
        my_putchar(base[nbr]);
    }
}
