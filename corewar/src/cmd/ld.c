/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

#include "../../include/my.h"
#include "../../include/struct_all.h"
#include "../../include/op.h"

// PC = INDEX ACTUEL DU CHAMPION
// ld 34,r3 = load REG_SIZE at the adress PC + 34 % IDX_MOD into r3

int check_cmd_ld(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    if (arg[1] > 16 || arg[1] < 1)
        return -1;
    int i = 0;
    for (; arg[i] != -1; i++);
    if (i != 2) {
        st_core->st_champ[pos]->carry = 0;
        return -1;
    } else
        return 0;
}

int cmd_ld(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    int value = arg[0];
    int value2 = arg[1];
    if (check_cmd_ld(st_core, pos, proto, arg) == -1) {
        st_core->st_champ[pos]->carry = 0;
        return 0;
    }
    my_memcpy(&(st_core->st_champ[pos]->registers[value2 - 1]),
        &(st_core->arena[mod(st_core->st_champ[pos]->nw_adres) +
            value % IDX_MOD]), REG_SIZE);
    st_core->st_champ[pos]->registers[value2 - 1] = value;
    st_core->st_champ[pos]->carry = 1;
    return 1;
}
