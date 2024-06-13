/*
** EPITECH PROJECT, 2023
** dir
** File description:
** dir
*/
#include "my.h"
#include "op.h"
#include "asm.h"

bool check_numb(char *str)
{
    for (int i = 1; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}

int get_space_label(int current, int index, cmd_infos *cmd, int i)
{
    int size = 0;
    if (current > index) {
        for (int i = current - 1; i >= index; i--)
            size -= get_size_line(cmd->tab_file[i]);
    } else {
        for (int i = current; i < index; i++)
            size += get_size_line(cmd->tab_file[current]);
    }
    return (size);
}

void write_t_dir(int index_tab, char *str, cmd_infos *cmd, char **tab)
{
    int dir = 0;
    short ind = 0;
    int index = 0;
    if (check_numb(str) == true) {
        dir = convert_big_endian(my_getnbr(str));
        ind = convert_short_endian(my_getnbr(str));
    } else {
        index = get_label_nbr(str, cmd);
        dir = convert_big_endian(get_space_label(index_tab, index,
        cmd, cmd->i));
        ind = get_space_label(index_tab, index, cmd, cmd->i);
        ind = convert_short_endian(ind);
    } for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(op_tab[i].mnemonique, tab[0]) == 0 && (op_tab[i].code == 9
        || op_tab[i].code == 12 || op_tab[i].code == 11 || op_tab[i].code == 10
        || op_tab[i].code == 14)) {
            write(cmd->fd_file, &ind, IND_SIZE);
            return;
        }
    } write(cmd->fd_file, &dir, DIR_SIZE);
}
