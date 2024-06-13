/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

#include "../../include/my.h"
#include "../../include/struct_all.h"
#include "../../include/op.h"

int check_cmd_aff(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    if (is_a_register_or_nbr(arg[0]) != 1)
        return -1;
    if (arg[0] > 16 || arg[0] < 1)
        return -1;
    int i = 0;
    for (; arg[i]; i++);
    if (i != 1)
        return -1;
    else
        return 0;
}

int cmd_aff(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    if (check_cmd_aff(st_core, pos, proto, arg) == -1)
        return -1;
    my_putchar(st_core->st_champ[pos]->registers[arg[0] - 1] % 256);
    return 0;
}
