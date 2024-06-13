/*
** EPITECH PROJECT, 2023
** play_player.c
** File description:
** Player the full champions
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

// Pour ne pas sortir de l'arena
int mod(int nb)
{
    if (nb < 0)
        return nb % MEM_SIZE + MEM_SIZE;
    else
        return nb % MEM_SIZE;
}

void sub_play_player(st_c *st_core, int n)
{
    if (st_core->st_champ[n]->status == -3) {
        if (check_cmd_is_good(st_core, n) != 1)
            st_core->st_champ[n]->adres++;
        return;
    }
    if (st_core->st_champ[n]->status == 0)
        excute_cmd(st_core, n);
    else
        st_core->st_champ[n]->status--;
}

void play_player(st_c *st_core)
{
    for (int n = 0; n < st_core->st_player->nb_players; n++) {
        if (st_core->st_champ[n]->dead == 0) {
            sub_play_player(st_core, st_core->st_player->pos_champ[n]);
        }
    }
}
