/*
** EPITECH PROJECT, 2022
** modifier
** File description:
** modifier
*/

#include <unistd.h>
#include <stdarg.h>
#include <wchar.h>
int my_put_nbr(int nb);

int swm1(va_list list, int *i, int *cpt, char const *format)
{
    int modif_case = format[*i + 1];
    switch (modif_case) {
    case 'h':
        if (format[*i + 2] == 'h') {
            (*cpt) = my_put_nbr((char)va_arg(list, int));
            (*i) += 3;
        } else {
            my_put_nbr((short)va_arg(list, int));
            (*i) += 3;
        }
        break;
    default:
        break;
    }
    return (0);
}

int swm2(va_list list, int *i, int *cpt, char const *format)
{
    int modif_case2 = format[*i + 1];
    switch (modif_case2) {
    case 'l':
        if (format[*i + 2] == 'c') {
            (*cpt) = my_put_nbr((wint_t)va_arg(list, int));
        }
        break;
    default:
        break;
    }
    return (0);
}
