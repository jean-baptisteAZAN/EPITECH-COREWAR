/*
** EPITECH PROJECT, 2023
** error
** File description:
** erros
*/

#include "my.h"
#include "asm.h"
#include "op.h"

void check_numbers_of_args(char *str)
{
    char **tab_cmd = my_str_to_word_array(str, ' ');
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(op_tab[i].mnemonique, tab_cmd[0]) == 0 &&
        op_tab[i].nbr_args != get_size_tab(tab_cmd)) {
                exit(84);
        }
    }
}

void is_not_write_param(char **tab_cmd, int i)
{
    for (int j = 1; j <= op_tab[i].nbr_args; j++) {
        int arg_type = get_arg_type(tab_cmd[j]);
        if ((arg_type & op_tab[i].type[j - 1]) == 0)
            exit(84);
    }
}

void check_args_type(char *str)
{
    char **tab_cmd = my_str_to_word_array(str, ' ');

    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(op_tab[i].mnemonique, tab_cmd[0]) == 0)
            is_not_write_param(tab_cmd, i);
    }
}

void error_tab_file(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        check_numbers_of_args(tab[i]);
        check_args_type(tab[i]);
    }
}
