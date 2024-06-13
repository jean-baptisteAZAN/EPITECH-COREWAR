/*
** EPITECH PROJECT, 2022
** my_show_word
** File description:
** my_show_word
*/

void my_putchar(char c);

int my_putstr(char const *str);

void my_show_word_array(char * const *tab)
{
    int len = 0;
    for (; tab[len] != 0 ; len++){
        my_putstr(tab[len]);
        my_putchar('\n');
    }
}
