/*
** EPITECH PROJECT, 2022
** basic case
** File description:
** basic
*/

#include <unistd.h>
#include <stdarg.h>
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);
int my_putnbr_base(unsigned int nbr, char const *base);

int sws1(va_list list, int *i, int *cpt, char const *format)
{
    int cas_base = format[*i + 1];
    switch (cas_base) {
    case 'd':
    case 'i':
        (*cpt) += my_put_nbr(va_arg(list, int));
        (*i) += 1;
        break;
    case 's':
        (*cpt) +=   my_putstr(va_arg(list, char *));
        (*i) += 1;
        break;
    case 'c':
        my_putchar(va_arg(list, int));
        (*cpt) ++;
        (*i) += 1;
        break;
    default:
        break;
    }
    return (0);
}

int sws2(va_list list, int *i, int *cpt, char const *format)
{
    int cas_base2 = format[*i + 1];
    switch (cas_base2) {
    case 'p':
        (*cpt) += my_put_nbr(va_arg(list, int));
        (*i) += 1;
        break;
    case 'n':
        int *b = va_arg(list, int*);
        (*b) = *cpt;
        *i = *i + 2;
        break;
    case 'x':
        (*cpt) += my_putnbr_base(va_arg(list, int), "0123456789abcdef");
        (*i)++;
    default:
        break;
    }
    return (0);
}

int sws3(va_list list, int *i, int *cpt, char const *format)
{
    int cas_base3 = format[*i + 1];
    switch (cas_base3) {
    case 'X':
        (*cpt) += my_putnbr_base(va_arg(list, int), "0123456789ABCDEF");
        (*i)++;
        break;
    case '%':
        my_putchar('%');
        (*cpt)++;
        (*i)++;
    default:
        break;
    }
    return (0);
}
