/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

int check_cmd_live(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    int i = 0;
    for (; arg[i] != -1; i++);
    if (i != 1)
        return -1;
    else
        return 0;
}

static int get_pos_player_live(st_c *st_core, int arg)
{
    for (int i = 0; i < st_core->st_player->nb_players; i++) {
        if (st_core->st_champ[i]->prog_nb == arg)
            return i;
    }
    return 0;
}

int cmd_live(__attribute__((unused))st_c *st_core,
    __attribute__((unused))int pos, __attribute__((unused))int *proto,
    __attribute__((unused))int *arg)
{
    if (check_cmd_live(st_core, pos, proto, arg) == -1)
        return -1;
    st_core->st_champ[get_pos_player_live(st_core, arg[0])]->live = 1;
    st_core->st_player->nb_live++;
    st_core->st_player->player_winner_end_game = pos;

    if (st_core->st_player->nb_live >= NBR_LIVE) {
        st_core->st_player->cycle_to_die -= CYCLE_DELTA;
        st_core->st_player->nb_live = 0;
    }
    my_printf("The player ");
        my_put_nbr_g(st_core->st_champ[pos]->prog_nb);
            my_printf("(%s) is alive.\n", st_core->st_champ[pos]->name);
    return 0;
}
