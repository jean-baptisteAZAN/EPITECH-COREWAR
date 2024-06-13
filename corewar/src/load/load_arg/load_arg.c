/*
** EPITECH PROJECT, 2023
** load_arg.c
** File description:
** load the vm
*/

#include "my.h"
#include "struct_all.h"

int verif_is_nbr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int verif_file_exist(char* path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return 0;
    close(fd);
    return 1;
}

int sub_load_arg(st_c *st_core, int n)
{
    char **av = st_core->st_info->av;
    if (my_strcmp(av[n], "-dump") == 0)
        return arg_dump(st_core, av, n);
    if (my_strcmp(av[n], "-a") == 0)
        return arg_adress(st_core, av, n);
    if (my_strcmp(av[n], "-n") == 0)
        return arg_prog_nb(st_core, av, n);
    if (av[n][0] == '-')
        return display_error(st_core, "Error: invalid option\n");
    add_path_player(st_core, av[n]);
    return 0;
}

int load_arg(st_c *st_core)
{
    st_core->st_player->error = 0;
    st_core->st_player->dump = 0;
    st_core->st_player->arg_n = 0;
    st_core->st_player->arg_a = 0;
    for (int n = 1; n < st_core->st_info->ac; n++) {
        n += sub_load_arg(st_core, n);
        if (st_core->st_player->error == 84)
            return 84;
    }
    if (st_core->st_player->nb_players < 2)
        return display_error(st_core, "Error: Too few players!\n");
    if (st_core->st_player->nb_dump > 1)
        return display_error(st_core, "Error: \
Double definition of option dump.\n");
    st_core->st_player->pos_player = 0;
    if (st_core->st_player->arg_n != 0 || st_core->st_player->arg_a != 0)
        return display_error(st_core, "Error: wrong options\n");
    return 0;
}
