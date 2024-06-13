/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

// If the parameter is a register: 01
// If the parameter is a direct: 10
// If the parameter is an indirect: 11
// Otherwise: 00

#include "../../include/my.h"
#include "../../include/struct_all.h"
#include "../../include/op.h"

int check_cmd_st(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    if (arg[0] > 16 || arg[0] < 1)
        return -1;
    int i = 0;
    for (; arg[i] != -1; i++);
    if (i != 2)
        return -1;
    return 0;
}

int cmd_st(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    if (check_cmd_st(st_core, pos, proto, arg) == -1)
        return -1;
    if (is_a_register_or_nbr(arg[1]) == 1)
        my_memcpy(&(st_core->st_champ[pos]->registers[arg[1] - 1]),
            &(st_core->st_champ[pos]->registers[arg[0] - 1]), REG_SIZE);
    else
        my_arencpy(&(st_core->arena[mod(st_core->st_champ[pos]->nw_adres) +
            arg[1] % IDX_MOD]),
                &(st_core->st_champ[pos]->registers[arg[0] - 1]), REG_SIZE);
    return 0;
}
