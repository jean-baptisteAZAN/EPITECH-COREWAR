/*
** EPITECH PROJECT, 2022
** modifiers
** File description:
** jb et thép
*/

#include <unistd.h>
#include <stdarg.h>
void my_putchar(char c);
int my_put_nbr(int nb);
int intlen(int n);
int my_getnbr(char const *str);
int my_putnbr_base(unsigned int nbr, char const *base);

void modifier(va_list list, int *i, int *cpt, char const *format)
{

    int modif = format[*i] == '%' ? format[*i + 1] : 0;
    switch (modif) {
    case '+':
        int nbr = va_arg(list, int);
        if (nbr > 0) {
            my_putchar('+');
            (*cpt) += my_put_nbr(nbr);
        } else
            my_put_nbr(nbr);

        while (format[*i] != ' ' && format[*i] != '-' &&
        format[*i] != '#' && format[*i] != '\n' && format[*i] != '\0') {
            (*i)++;
        }
        (*i)--;
        break;
    }
}

void modifier2(va_list list, int *i, int *cpt, char const *format)
{
    int modif2 = format[*i] == '%' ? format[*i + 1] : 0;
    switch (modif2) {
    case ' ':
        int nbr = va_arg(list, int);
        if (nbr > 0) {
            my_putchar(' ');
            (*cpt) += my_put_nbr(nbr);
        } else
            my_put_nbr(nbr);
        (*i) += 2;
        break;
    }
}

void modifier3(va_list list, int *i, int *cpt, char const *format)
{
    int modif3 = format[*i] == '%' ? format[*i + 1] : 0;
    int premodif = my_getnbr(&format[(*i) + 2]);
    int nbr_0 = 0;
    switch (modif3) {
        case '-':
            int nbr = va_arg(list, int);
            nbr_0 = (premodif) - intlen(nbr);
            (*cpt) += my_put_nbr(nbr);
            while (nbr_0 > 0) {
                my_putchar(' ');
                nbr_0--;
            }
            while (format[*i] != ' ' && format[*i] != '+' &&
            format[*i] != '#' && format[*i] != '\n' && format[*i] != '\0')
                (*i)++;
            break;
    }
}

void modifier4(va_list list, int *i, int *cpt, char const *format)
{
    int modif4 = format[*i] == '%' ? format[*i + 1] : 0;
    int premodif = my_getnbr(&format[(*i) + 2]);
    int nbr_0 = 0;
    switch (modif4) {
    case '0':
        int nbr = va_arg(list, int);
        nbr_0 = (premodif) - intlen(nbr);
        while (nbr_0 > 0) {
            my_put_nbr(0);
            nbr_0--;
        }
        (*cpt) += my_put_nbr(nbr);
        while (format[*i] != ' ' && format[*i] != '-' && format[*i] != '+' &&
        format[*i] != '#' && format[*i] != '\n' && format[*i] != '\0')
            (*i)++;
        (*i)--;
        break;
    }
}

void modifier5(va_list list, int *i, int *cpt, char const *format)
{
    int modif5 = format[*i] == '%' ? format[*i + 1] : 0;
    int nbr_suiv = format[*i + 2];
    switch (modif5) {
        case '#':
            int nbr = va_arg(list, int);
            if (nbr_suiv == 'x' || nbr_suiv == 'X') {
                my_put_nbr(0);
                my_putchar(nbr_suiv);
                nbr = my_putnbr_base(nbr , "0123456789abcdef");
                my_putchar(format[*i + 3]);
            }
            if (nbr_suiv == 'o') {
                my_put_nbr(0);
                nbr = my_putnbr_base(nbr , "01234567");
            }
            (*cpt) ++;
            (*i) += 2;
            break;
    }
}
