/*
** EPITECH PROJECT, 2023
** cmd_*
** File description:
** cmd_*
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

void end_game(st_c *st_core)
{
    if (st_core->st_player->player_winner_end_game != -1)
        display_win(st_core, st_core->st_player->player_winner_end_game);
    return;
}
