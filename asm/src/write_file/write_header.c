/*
** EPITECH PROJECT, 2023
** write
** File description:
** header
*/

#include "my.h"
#include "op.h"
#include "asm.h"

void write_t_reg(char nb, cmd_infos *cmd)
{
    write(cmd->fd_file, &nb, 1);
}

void write_t_ind(short nb, cmd_infos *cmd)
{
    nb = convert_short_endian(nb);
    write(cmd->fd_file, &nb, IND_SIZE);
}

int get_label_nbr(char *tab, cmd_infos *cmd)
{
    char str[my_strlen(tab) - 2];
    int index = 0;
    int a = 0;
    for (int i = 2; tab[i]; i++, a++) {
        str[a] = tab[i];
    }
    str[a] = '\0';
    for (int i = 0; cmd->tab_label[i]; i++) {
        if (strcmp(cmd->tab_label[i], str) == 0) {
            index = cmd->tab_pos_label[i];
            return index;
        }
    }
}

void write_params(cmd_infos *cmd, char **tab, int index_tab)
{
    for (cmd->i = 1; tab[cmd->i] != NULL; cmd->i++) {
        switch (get_arg_type(tab[cmd->i])) {
            case T_REG:
                write_t_reg((char)my_getnbr(tab[cmd->i] + 1), cmd);
                break;
            case T_IND:
                write_t_ind((short)my_getnbr(tab[cmd->i]), cmd);
                break;
            case T_DIR:
                write_t_dir(index_tab, tab[cmd->i], cmd, tab);
                break;
        }
    }
}

void write_header(cmd_infos *cmd, header_t *head)
{
    my_memset(head, 0, sizeof(header_t));
    head->magic = convert_big_endian(COREWAR_EXEC_MAGIC);
    my_strncpy(head->prog_name, cmd->name, PROG_NAME_LENGTH);
    head->prog_name[PROG_NAME_LENGTH] = '\0';
    my_strncpy(head->comment, cmd->comment, COMMENT_LENGTH);
    head->comment[COMMENT_LENGTH] = '\0';
    head->prog_size = convert_big_endian(cmd->prog_size);
    write(cmd->fd_file, head, sizeof(header_t));
}
