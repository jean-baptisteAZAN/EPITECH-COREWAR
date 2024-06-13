/*
** EPITECH PROJECT, 2023
** home_arena.c
** File description:
** arena for the game (virtual machine)
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

int check_win(st_c *st_core)
{
    if (st_core->st_player->nb_live >= NBR_LIVE) {
        st_core->st_player->cycle_to_die -= CYCLE_DELTA;
        st_core->st_player->nb_live = 0;
    }
    if (st_core->st_player->cycle_to_die <= 0)
        return 1;
    if (st_core->st_player->tempo_cycle > st_core->st_player->cycle_to_die) {
        st_core->st_player->tempo_cycle = 0;
        int tmp = check_live(st_core);

        if (tmp <= 1)
            return 1;
        else
            return 0;
    }
    return 0;
}

int sub_cut_indice(int *tmp_int, int n, int i, int min_idx)
{
    for (int j = i + 1; j < n; j++)
        if (tmp_int[j] < tmp_int[min_idx])
            min_idx = j;
    return min_idx;
}

void cut_indice(int arr[], int n, int *cut_indice)
{
    int tmp_int[n];
    for (int i = 0; i < n; i++) {
        tmp_int[i] = arr[i];
        cut_indice[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        min_idx = sub_cut_indice(tmp_int, n, i, min_idx);
        if (min_idx != i) {
            int temp = tmp_int[min_idx];
            tmp_int[min_idx] = tmp_int[i];
            tmp_int[i] = temp;
            int temp_idx = cut_indice[min_idx];
            cut_indice[min_idx] = cut_indice[i];
            cut_indice[i] = temp_idx;
        }
    }
}

void prepa_pos_champion(st_c *st_core)
{
    st_core->st_player->pos_champ = my_malloc((sizeof(int) *
        (st_core->st_player->nb_players + 1)));
    for (int i = 0; i < (st_core->st_player->nb_players + 1); i++)
        st_core->st_player->pos_champ[i] = -1;
    int *tmp = my_malloc((sizeof(int) * (5)));
    for (int n = 0; n < 4; n++)
        tmp[n] = st_core->st_champ[n]->prog_nb;
    cut_indice(tmp, st_core->st_player->nb_players,
        st_core->st_player->pos_champ);
}

int home_arena(st_c *st_core)
{
    st_core->st_player->nb_live = 0;
    st_core->st_player->tempo_cycle = 0;
    st_core->st_player->cycle_to_die = CYCLE_TO_DIE;
    st_core->st_player->n_cycle_to_die = CYCLE_TO_DIE;
    st_core->st_player->player_winner_end_game = -1;
    if (prepa_champions(st_core) == 84)
        return 84;
    if (st_core->st_player->error == 84)
        return 84;
    prepa_pos_champion(st_core);
    for (st_core->st_player->nb_cycle = 1; check_win(st_core) == 0;
    st_core->st_player->nb_cycle++, st_core->st_player->tempo_cycle++) {
        play_player(st_core);
        if (st_core->st_player->nb_cycle == st_core->st_player->dump)
            display_arena(st_core);
    }
    end_game(st_core);
    return 0;
}
