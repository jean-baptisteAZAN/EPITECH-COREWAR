/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

#include "../../include/my.h"
#include "../../include/struct_all.h"
#include "../../include/op.h"

int check_cmd_lldi(__attribute__((unused))st_c *st_core,
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

int cmd_lldi(st_c *st_core, int pos, int *proto, int *arg)
{
    if (check_cmd_lldi(st_core, pos, proto, arg) == -1)
        return -1;
    int S = 0;
    my_arencpy(&S, &(st_core->arena[mod(st_core->st_champ[pos]->nw_adres)
        + arg[0]]), IND_SIZE);;
    S += arg[1];
    my_memcpy(&(st_core->st_champ[pos]->registers[arg[2] - 1]),
        &(st_core->arena[mod(st_core->st_champ[pos]->nw_adres) + S]), REG_SIZE);
    st_core->st_champ[pos]->carry = 1;
    return 0;
}
