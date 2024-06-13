/*
** EPITECH PROJECT, 2023
** create_player.c
** File description:
** int full struct
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

void reset_cod_bytes_args(st_c *st_core, int pos)
{
    for (int n = 0; n < 5; n++) {
        st_core->st_champ[pos]->cod_bytes[n] = -1;
        st_core->st_champ[pos]->arg[n] = -1;
    }
}

void complet_player(st_c *st_core, int pos)
{
    st_core->st_champ[pos]->path_file = NULL;
    st_core->st_champ[pos]->adres = -1;
    st_core->st_champ[pos]->prog_nb = 0;
    st_core->st_champ[pos]->name = NULL;
    st_core->st_champ[pos]->live = 0;
    st_core->st_champ[pos]->dead = 0;
    st_core->st_champ[pos]->carry = 1;
    st_core->st_champ[pos]->cod_bytes = my_malloc(sizeof(int) * 5);
    st_core->st_champ[pos]->arg = my_malloc(sizeof(int) * 5);
    reset_cod_bytes_args(st_core, pos);
    st_core->st_champ[pos]->registers = my_malloc(sizeof(int) * (REG_NUMBER));
    for (int i = 0; i < REG_NUMBER; i++)
        st_core->st_champ[pos]->registers[i] = 0;
    st_core->st_champ[pos]->status = -3;
}
