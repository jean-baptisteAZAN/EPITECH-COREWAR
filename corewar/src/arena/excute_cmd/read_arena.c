/*
** EPITECH PROJECT, 2023
** read_arena.c
** File description:
** Get proto and arg
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

int reg_read_arena(st_c *st_core, int pos, size_t size)
{
    short int tmp = 0;
    my_corecpy(&tmp, &st_core->arena[mod(st_core->st_champ[pos]->adres)],
        size);
    st_core->st_champ[pos]->adres += size;
    if (size == 1)
        return tmp;
    if (size == 2)
        return short_big_endian(tmp);
    else
        return convert_big_endian((int)tmp);
}

int other_read_arena(st_c *st_core, int pos, size_t size)
{
    int tmp = 0;
    my_corecpy(&tmp, &st_core->arena[mod(st_core->st_champ[pos]->adres)],
        size);
    st_core->st_champ[pos]->adres += size;
    if (size == 1) return tmp;
    if (size == 2)
        return short_big_endian(tmp);
    else
        return convert_big_endian((int)tmp);
}

int read_arena(st_c *st_core, int pos, size_t size, int n)
{
    if (st_core->st_champ[pos]->cod_bytes[n] == T_REG) {
        return reg_read_arena(st_core, pos, size);
    } else {
        return other_read_arena(st_core, pos, size);
    }
}
