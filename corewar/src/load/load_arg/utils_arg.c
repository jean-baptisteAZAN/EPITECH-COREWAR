/*
** EPITECH PROJECT, 2023
** load_arg.c
** File description:
** load the vm
*/

#include "my.h"
#include "struct_all.h"

int arg_dump(st_c *st_core, char **av, int n)
{
    if (av[n + 1] && verif_is_nbr(av[n + 1]) == 1) {
        st_core->st_player->nb_dump++;
        st_core->st_player->dump =
            my_getnbr(st_core->st_info->av[n + 1]);
        return 1;
    }
    display_error(st_core, "Error: wrong number of arguments in '-dump'\n");
    return 0;
}

int arg_adress(st_c *st_core, char **av, int n)
{
    st_core->st_player->arg_a++;
    if (av[n + 1] && verif_is_nbr(av[n + 1]) == 1) {
        st_core->st_champ[st_core->st_player->pos_player]->adres =
            my_getnbr(av[n + 1]);
        return 1;
    }
    display_error(st_core, "Error: wrong number of arguments in '-a'\n");
    return 0;
}

int verif_displacted_arg_prog_nb(st_c *st_core)
{
    if (st_core->st_champ[st_core->st_player->pos_player]->prog_nb < 1 ||
        st_core->st_champ[st_core->st_player->pos_player]->prog_nb > 4) {
        display_error(st_core,
            "Error: -n option value must be between 1 and 4\n");
        return 84;
    }
    for (int n = 0; n < st_core->st_player->pos_player; n++) {
        if (st_core->st_champ[n]->prog_nb ==
            st_core->st_champ[st_core->st_player->pos_player]->prog_nb) {
            display_error(st_core, "Error: duplicated program number\n");
            return 84;
        }
    }
    return 0;
}

int arg_prog_nb(st_c *st_core, char **av, int n)
{
    st_core->st_player->arg_n++;
    if (av[n + 1] && verif_is_nbr(av[n + 1]) == 1) {
        st_core->st_champ[st_core->st_player->pos_player]->prog_nb =
            my_getnbr(av[n + 1]);
        if (verif_displacted_arg_prog_nb(st_core) == 84)
            return 0;
        return 1;
    }
    if (st_core->st_champ[st_core->st_player->pos_player]->prog_nb < 1) {
        display_error(st_core,
            "Error: -n option value must be between 1 and 4\n");
    }
    display_error(st_core, "Error: wrong number of arguments in '-n'\n");
    return 0;
}

int add_path_player(st_c *st_core, char *arg)
{
    if (st_core->st_player->nb_players > 3) {
        display_error(st_core, "Error: too many players\n");
        return 0;
    }
    if (verif_file_exist(arg) == 0) {
        display_error(st_core, "Error: file does not exist\n");
        return 0;
    }
    st_core->st_champ[st_core->st_player->pos_player]->path_file =
        my_strdup(arg);
    st_core->st_player->pos_player++;
    st_core->st_player->nb_players++;
    if (st_core->st_player->arg_n > 1 || st_core->st_player->arg_a > 1)
        return display_error(st_core, "Error: wrong options\n");
    st_core->st_player->arg_n = 0;
    st_core->st_player->arg_a = 0;
    return 0;
}
