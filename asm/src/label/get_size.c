/*
** EPITECH PROJECT, 2023
** lanbe
** File description:
** size
*/

#include "my.h"
#include "op.h"
#include "asm.h"

int check_coding_byte(int size, char *str)
{
    if (my_strcmp(str, "zjmp") == 0 || my_strcmp(str, "fork") == 0 ||
    my_strcmp(str, "lfork") == 0 || my_strcmp(str, "live") == 0)
        return 0;
    return 1;
}

int is_a_direct(int i, char **tab_size_line, int size, char *str)
{
    int len = 0;
    len = DIR_SIZE;
    if (my_strcmp(str, "zjmp") == 0 || my_strcmp(str, "fork") == 0 ||
    my_strcmp(str, "lfork") == 0 || my_strcmp(str, "sti") == 0 ||
    my_strcmp(str, "ldi") == 0 || my_strcmp(str, "lldi") == 0 )
        len = IND_SIZE;
    return (len);
}

bool check_is_instruc(char *str)
{
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(op_tab[i].mnemonique, str) == 0)
            return true;
    }
    return false;
}

int get_size_line(char *str)
{
    char **tab_size_line = my_str_to_word_array(str, ' ');
    char my_code;
    int size = 0;
    if (check_is_instruc(tab_size_line[0]) == true)
        size++;
    size += check_coding_byte(size, tab_size_line[0]);
    for (int i = 1; tab_size_line[i]; i++) {
        if (tab_size_line[i][0] == 'r' && tab_size_line[i][1] >= '0' &&
        tab_size_line[i][1] <= '9')
            size += 1;
        if (tab_size_line[i][0] >= '0' && tab_size_line[i][0] <= '9')
            size += IND_SIZE;
        if (tab_size_line[i][0] == DIRECT_CHAR) {
            size += is_a_direct(i, tab_size_line, size, tab_size_line[0]);
        }
    }
    return (size);
}

int get_size_file(char **tab)
{
    int size = 0;
    for (int i = 0; tab[i]; i++) {
        size += get_size_line(tab[i]);
    }
    return (size);
}
