/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

int check_cmd_xor(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    if (arg[0] < 0 || arg[0] > 16)
        return -1;
    if (arg[1] < 0 || arg[1] > 16)
        return -1;
    if (arg[2] < 0 || arg[2] > 16)
        return -1;
    int i = 0;
    for (; arg[i] != -1; i++);

    if (i != 3)
        return -1;
    else
        return 0;
}

int cmd_xor(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    if (check_cmd_xor(st_core, pos, proto, arg) == -1)
        return -1;
    st_core->st_champ[pos]->registers[arg[2] - 1] =
        st_core->st_champ[pos]->registers[arg[0] - 1] ^
        st_core->st_champ[pos]->registers[arg[1] - 1];
    return 0;
}
