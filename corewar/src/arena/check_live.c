/*
** EPITECH PROJECT, 2023
** check_live.c
** File description:
** Verify if the player is alive
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** task01
*/

void my_putchar(char c);

int my_len_int(int number)
{
    int count = 1;

    if (number < 0) {
        number = -number;
        count++;
    }

    while (number > 9) {
        number /= 10;
        count++;
    }

    return count;
}

int my_put_nbr_g(int number)
{
    if (number < 0) {
        number = -number;
        my_putchar('-');
    }

    if (number == 0) {
        my_putchar('0');
        return 0;
    }

    if (number > 0) {
        if (number / 10 > 0)
            my_put_nbr_g(number / 10);
        my_putchar((number % 10) + '0');
    }
    return 0;
}

int check_fork(st_c *st_core, int pos)
{
    int tmp = st_core->st_champ[pos]->prog_nb;
    for (int n = 0; n < pos; n++) {
        if (st_core->st_champ[n]->prog_nb == tmp
            && st_core->st_champ[n]->live == 1)
            return 0;
    }
    return 1;
}

// Verifier combien il reste de joeur en vie et renvoyer le nombre de joeur
//  encore en vie + change in st_core: st_core->st_player->live[~]
int check_live(st_c *st_core)
{
    int nb_live = 0;
    for (int n = 0; n < st_core->st_player->nb_players; n++) {
        if (st_core->st_champ[n]->live == 1 &&
            st_core->st_champ[n]->dead == 0) {
                nb_live++;
        } else
            st_core->st_champ[n]->dead = 1;
        st_core->st_champ[n]->live = 0;
    }
    st_core->st_player->nb_player_live_end_game = nb_live;
    return nb_live;
}
