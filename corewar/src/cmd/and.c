/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

int cmd_and(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    if (check_cmd_and(st_core, pos, arg, proto) == -1) {
        st_core->st_champ[pos]->carry = 0;
        return -1;
    }
    st_core->st_champ[pos]->registers[arg[2] - 1] =
    st_core->st_champ[pos]->registers[arg[0] - 1] &
    st_core->st_champ[pos]->registers[arg[1] - 1];
    st_core->st_champ[pos]->carry = 1;
    return 0;
}

// Return -1 if cmd is not good else return 0
int check_cmd_and(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    int i = 0;
    for (; arg[i]; i++);
    if (i != 3) {
        st_core->st_champ[pos]->carry = 0;
        return -1;
    } else
        return 0;
}
