/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// INCLUDE ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <stdarg.h>

#pragma once

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// LIBRARIES ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    void my_puterror(char const *str);
    void my_putchar1(char c);
    char *my_strdup(char const *src);
    char **my_chardup(char **str, char **src);
    int my_strlen4(char const *str);
    int my_show_word_array(char * const *tab);
    int my_strlen3(char const *str);
    int my_strlen7(char const *str);
    int sub_my_strstr(char *str, char const *to_find, int i, int v);
    void my_putchar(char c);
    char *my_strstr(char *str, char const *to_find);
    int my_isneg(int nb);
    int my_strcmp(char const *s1, char *s2);
    int my_strncmp(char const *s1, char *s2, int n);
    void my_swap(int *a, int *b);
    char *my_strupcase(char *str);
    int my_putstr(char const *str);
    char *my_strlowcase(char *str);
    int my_strlen(char const *str);
    char *my_strcapitalize(char *str);
    int my_getnbr(char const *str);
    int my_str_isalpha(char const *str);
    int my_sort_int_array(int *tab, int size);
    int my_str_isnum(char const *str);
    int my_compute_power_rec(int nb, int power);
    int my_str_islower(char const *str);
    int my_compute_square_root(int nb);
    int my_str_isupper(char const *str);
    int my_is_prime(int nb);
    int my_str_isprintable(char const *str);
    int my_find_prime_sup(int nb);
    int my_showstr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    int my_showmem(char const *str, int size);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strcat(char const *dest, char const *src);
    char *my_revstr(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    int my_show_word_array(char *const *tab);
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
    char *my_put_nbr(float number);
    char *my_put_nbr_int(int nb);
    int intlen(int n);
    int my_getnbr(char const *str);
    int my_putnbr_base(unsigned int nbr, char const *base);
    char **my_str_to_word_array(char const *str, char separateur);
    int my_printf(const char *format, ...);
    char *int_to_char(int nbr);
