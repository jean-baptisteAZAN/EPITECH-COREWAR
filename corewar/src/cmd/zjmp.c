/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

int check_cmd_zjmp(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    int i = 0;
    for (; arg[i] != -1; i++);
    if (arg[0] < 0)
        return 0;
    if (i != 1)
        return -1;
    else
        return 0;
}

int cmd_zjmp(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    if (st_core->st_champ[pos]->carry == 0)
        return 0;
    if (check_cmd_zjmp(st_core, pos, proto, arg) == -1)
        return -1;
    if (st_core->st_champ[pos]->carry == 1)
        st_core->st_champ[pos]->adres =
            ((st_core->st_champ[pos]->nw_adres + arg[0] % IDX_MOD));
    return 0;
}
