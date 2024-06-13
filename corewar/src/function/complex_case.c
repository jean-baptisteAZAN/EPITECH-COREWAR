/*
** EPITECH PROJECT, 2022
** complex
** File description:
** comple
*/

#include <unistd.h>
#include <stdarg.h>
int my_putstr(char const *str);
int my_putnbr_base(int nbr, char const *base);

int swc1(va_list list, int *i, int *cpt, char const *format)
{
    int complex = format[*i +1];
    switch (complex) {
    case 'b':
        (*cpt) = my_putnbr_base(va_arg(list, unsigned int), "01");
        (*i) += 1;
        break;
    case 'S':
        if (complex > 32 || complex < 127)
            (*cpt) = my_putstr(va_arg(list, char *));
        else
            (*cpt) = my_putnbr_base(va_arg(list, int), "07");
        (*i) += 1;
        break;
    default:
        break;
    }
    return (0);
}
