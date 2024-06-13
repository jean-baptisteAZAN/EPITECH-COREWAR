/*
** EPITECH PROJECT, 2023
** verif_help.c
** File description:
** Get the value for struct info_core
*/

#include "my.h"
#include "struct_all.h"

int display_help(void)
{
    my_printf("USAGE\n");
    my_printf("./corewar [-dump nbr_cycle] [[-n prog_nb] [-a load_address] \
prog_name] ...\n");
    my_printf("DESCRIPTION\n");
    my_printf("-dump nbr_cycle dumps the memory after the nbr_cycle execution \
(if the round isn’t\n");
    my_printf("already over) with the following format: 32 bytes/line\n");
    my_printf("in hexadecimal (A0BCDEFE1DD3...)\n");
    my_printf("-n prog_nb sets the next program’s number. By default, \
the first free number\n");
    my_printf("in the parameter order\n");
    my_printf("-a load_address sets the next program’s loading address. \
When no address is\n");
    my_printf("specified, optimize the addresses so that the processes \
are as far\n");
    my_printf("away from each other as possible. The addresses are MEM_SIZE\
modulo.\n");
    return 1;
}

int verif_help(st_c *info_core)
{
    for (int n = 1; n < info_core->st_info->ac; n++) {
        if (my_strlen(info_core->st_info->av[n]) == 2 &&
            info_core->st_info->av[n][0] == '-' &&
            info_core->st_info->av[n][1] == 'h')
            return display_help();
    }
    return 0;
}
