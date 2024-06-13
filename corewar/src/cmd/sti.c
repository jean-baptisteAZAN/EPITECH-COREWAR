/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

#include "../../include/my.h"
#include "../../include/struct_all.h"
#include "../../include/op.h"

int check_cmd_sti(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    int i = 0;
    for (; arg[i] != -1; i++);
    if (i != 3)
        return -1;
    else
        return 0;
}

int cmd_sti(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    int new_arg1 = 0;
    int new_arg2 = 0;
    int value = st_core->st_champ[pos]->registers[arg[0] - 1];
    value = convert_big_endian(value);
    if (check_cmd_sti(st_core, pos, proto, arg) == -1)
        return -1;
    if (proto[1] == T_REG)
        new_arg1 = st_core->st_champ[pos]->registers[arg[1] - 1];
    else
        new_arg1 = arg[1];
    if (proto[2] == T_REG)
        new_arg2 = st_core->st_champ[pos]->registers[arg[2] - 1];
    else
        new_arg2 = arg[2];
    my_arencpy(&(st_core->arena[mod(st_core->st_champ[pos]->nw_adres +
            (new_arg1 + new_arg2) % IDX_MOD)]),
            &value, REG_SIZE);
    return 0;
}
