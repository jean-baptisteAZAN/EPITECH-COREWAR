/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

static void duplicate_player_fork(st_c *st_core, int pos, int dest)
{
    st_core->st_champ[dest]->cmd = 0;
    st_core->st_champ[dest]->cod_bytes = my_malloc(sizeof(int) * 5);
    st_core->st_champ[dest]->arg = my_malloc(sizeof(int) * 5);
    reset_cod_bytes_args(st_core, dest);
    st_core->st_champ[dest]->registers = my_malloc(sizeof(int) * (REG_NUMBER));
    for (int i = 0; i < REG_NUMBER; i++)
        st_core->st_champ[dest]->registers[i] =
            st_core->st_champ[pos]->registers[i];
    st_core->st_champ[pos]->status = -3;
    st_core->st_champ[dest]->live = 0;
    st_core->st_champ[dest]->status = 0;
    st_core->st_champ[dest]->name = my_strdup(st_core->st_champ[pos]->name);
    st_core->st_champ[dest]->path_file =
        my_strdup(st_core->st_champ[pos]->path_file);
    st_core->st_champ[dest]->prog_nb = st_core->st_champ[pos]->prog_nb;
    st_core->st_champ[dest]->carry = st_core->st_champ[pos]->carry;
    st_core->st_champ[dest]->adres = st_core->st_champ[pos]->adres;
}

void decale_fork(st_c *st_core)
{
    st_core->st_player->pos_champ =
        realloc(st_core->st_player->pos_champ,
            st_core->st_player->nb_players + 2);
    st_core->st_player->pos_champ[st_core->st_player->nb_players] =
        st_core->st_player->nb_players;
}

int cmd_fork(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    st_core->st_info->size_alloc_st_player++;
    st_core->st_champ =
        my_realloc(st_core->st_champ, sizeof(st_ch *) *
            (st_core->st_info->size_alloc_st_player));
    decale_fork(st_core);
    st_core->st_champ[st_core->st_info->size_alloc_st_player - 1] =
        my_malloc(sizeof(st_ch));
    duplicate_player_fork(st_core, pos, st_core->st_player->nb_players);
    st_core->st_champ[st_core->st_player->nb_players]->adres +=
        (arg[0] % IDX_MOD);
    st_core->st_player->nb_players++;
    return 0;
}

// Return -1 if cmd is not good else return 0
int check_cmd_fork(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    return -1;
    int n = 0;
    for (; proto[n] != -1; n++);
    if (n != 1)
        return -1;
    return 0;
}
