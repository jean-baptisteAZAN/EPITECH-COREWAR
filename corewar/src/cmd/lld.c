/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

#include "../../include/my.h"
#include "../../include/struct_all.h"
#include "../../include/op.h"

int check_cmd_lld(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    if (arg[1] > 16 || arg[1] < 1)
        return -1;
    int i = 0;
    for (; arg[i]; i++);
    if (i != 2) {
        st_core->st_champ[pos]->carry = 0;
        return -1;
    } else
        return 0;
}

int cmd_lld(st_c *st_core, int pos, int *proto, int *arg)
{
    int value = arg[0];
    int value2 = arg[1];

    if (check_cmd_lld(st_core, pos, proto, arg) == -1)
        return -1;
    my_memcpy(&(st_core->st_champ[pos]->registers[value2 - 1]),
        &(st_core->arena[mod(st_core->st_champ[pos]->nw_adres) + value]),
            REG_SIZE);
    st_core->st_champ[pos]->carry = 1;
    return 0;
}
