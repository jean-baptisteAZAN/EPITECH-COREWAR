/*
** EPITECH PROJECT, 2023
** args
** File description:
** file
*/

#include "my.h"
#include "op.h"
#include "asm.h"

int get_arg_type(char *arg)
{
    if (arg[0] == 'r' && arg[1] >= '0' && arg[1] <= '9')
        return T_REG;
    if (arg[0] == DIRECT_CHAR)
        return T_DIR;
    if (my_str_isnum(arg) == 1)
        return T_IND;
}

void write_coding_byte(cmd_infos *cmd, char **args, int nb_args, char code)
{
    if (code == 1 || code == 9 || code == 12 || code == 15) return;
    int i = 1;
    char *str = "";
    char codingByte = 0;
    for (; args[i] != NULL; i++) {
        switch (get_arg_type(args[i])) {
            case T_REG:
                str = my_strcat(str, "01");
                break;
            case T_DIR:
                str = my_strcat(str, "10");
                break;
            case T_IND:
                str = my_strcat(str, "11");
                break;
        }
    } for (; i < MAX_ARGS_NUMBER + 1; i++)
        str = my_strcat(str, "00");
    codingByte = transform_binary_to_decimal(str);
    write(cmd->fd_file, &codingByte, 1);
}

void write_arguments(char *str, cmd_infos *cmd, int index)
{
    char **tab = my_str_to_word_array(str, ' ');
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(op_tab[i].mnemonique, tab[0]) == 0) {
            write(cmd->fd_file, &op_tab[i].code, 1);
            write_coding_byte(cmd, tab, op_tab[i].nbr_args, op_tab[i].code);
            write_params(cmd, tab, index);
        }
    }
}

void write_args(cmd_infos *cmd)
{
    for (int i = 0; cmd->tab_file[i]; i++)
        write_arguments(cmd->tab_file[i], cmd, i);
}
