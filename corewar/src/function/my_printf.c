/*
** EPITECH PROJECT, 2022
** my_printf jb theo
** File description:
** jb et theo
*/
#include <unistd.h>
#include <stdarg.h>
void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int sws1(va_list list, int *i, int *cpt, char const *format);
int sws2(va_list list, int *i, int *cpt, char const *format);
int sws3(va_list list, int *i, int *cpt, char const *format);
int swm1(va_list list, int *i, int *cpt, char const *format);
int swc1(va_list list, int *i, int *cpt, char const *format);
int modifier(va_list list, int *i, int *cpt, char const *format);
int modifier2(va_list list, int *i, int *cpt, char const *format);
int modifier3(va_list list, int *i, int *cpt, char const *format);
int modifier4(va_list list, int *i, int *cpt, char const *format);
int modifier5(va_list list, int *i, int *cpt, char const *format);

void handdlemodif(va_list list, int *i, int *cpt, char const *format)
{
    modifier(list, i, cpt, format);
    modifier2(list, i, cpt, format);
    modifier3(list, i, cpt, format);
    modifier4(list, i, cpt, format);
    modifier5(list, i, cpt, format);
}

int my_printf(const char *format, ...)
{
    va_list list;
    int cpt = 0;
    va_start(list, format);
    int len = my_strlen(format);
    for (int i = 0; i < len; i++) {
        if (format[i] == '%') {
            sws1(list, &i, &cpt, format);
            sws2(list, &i, &cpt, format);
            sws3(list, &i, &cpt, format);
            swc1(list, &i, &cpt, format);
            handdlemodif(list, &i, &cpt, format);
        } else {
            my_putchar(format[i]);
            cpt++;
        }
    }
    return cpt;
}
