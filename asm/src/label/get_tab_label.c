/*
** EPITECH PROJECT, 2023
** get_tab_label.c
** File description:
** Get full information about a tab label
*/

#include "my.h"
#include "op.h"
#include "asm.h"

void sub_malloc_nb_tab_label(cmd_infos *st_cmd, char c)
{
    if (c == ':')
        st_cmd->nb_label++;
}

void malloc_nb_tab_label(cmd_infos *st_cmd)
{
    st_cmd->nb_label = 0;
    for (int n = 0; st_cmd->tab_file[n]; n++) {
        for (int a = 0; st_cmd->tab_file[n][a] != '\0'; a++) {
            sub_malloc_nb_tab_label(st_cmd, st_cmd->tab_file[n][a]);
        }
    }
    st_cmd->tab_label = my_malloc(sizeof(char *) * st_cmd->nb_label);
    st_cmd->tab_pos_label = my_malloc(sizeof(char *) * st_cmd->nb_label);
    st_cmd->nb_label = 0;
}

int get_label(cmd_infos *st_cmd, char *str, int pos_in_file)
{
    if (str[0] == ':')
        return disp_error("Error label not good\n");
    int end_label = 0;
    for (int n = 0; str[n] != '\0' && str[n + 1] != '\0'; n++) {
        if (str[n] == ':' && str[n - 1] != '%') {
            end_label = n;
            break;
        }
    } if (end_label == 0)
        return 0;
    st_cmd->tab_label[st_cmd->nb_label] = my_strdup_mac(str);
    st_cmd->tab_label[st_cmd->nb_label][end_label] = '\0';
    st_cmd->tab_pos_label[st_cmd->nb_label] = pos_in_file - 2;
    for (int i = 0; st_cmd->tab_label[st_cmd->nb_label][i] != '\0'; i++) {
        if (check_cara_is_label(st_cmd->tab_label[st_cmd->nb_label][i]) == 84)
            return 84;
    } st_cmd->nb_label++;
    st_cmd->tab_file[pos_in_file] =
    cut_beg_string(st_cmd->tab_file[pos_in_file], end_label++);
    return 0;
}

void delete_comma(char *str)
{
    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] == ',')
            str[n] = ' ';
    }
}

int get_tab_label(cmd_infos *st_cmd)
{
    malloc_nb_tab_label(st_cmd);
    for (int n = 0; st_cmd->tab_file[n]; n++)
        my_cleanstr(st_cmd->tab_file[n]);
    st_cmd->nb_label = 0;
    for (int n = 2; st_cmd->tab_file[n]; n++) {
        if (get_label(st_cmd, st_cmd->tab_file[n], n) == 84)
            return 84;
    }
    for (int n = 0; st_cmd->tab_file[n]; n++)
        delete_comma(st_cmd->tab_file[n]);
    remove_first_two(st_cmd->tab_file);
    for (int n = 0; st_cmd->tab_file[n]; n++)
        my_cleanstr(st_cmd->tab_file[n]);
    return 0;
}
