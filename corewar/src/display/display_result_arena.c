/*
** EPITECH PROJECT, 2023
** display_result_arena.c
** File description:
** display result arena for the end game
*/

#include "my.h"
#include "struct_all.h"

void display_win(st_c *st_core, int pos)
{
    my_printf("The player ");
    my_put_nbr_g(st_core->st_champ[pos]->prog_nb);
    my_printf("(%s) has won.\n", st_core->st_champ[pos]->name);
}

void display_alive(st_c *st_core, int pos)
{
    my_printf("The player ");
    my_put_nbr_g(st_core->st_champ[pos]->prog_nb);
    my_printf("(%s) is alive.\n", st_core->st_champ[pos]->name);
}

void display_equa(void)
{
    write(1, "It's an equality\n", 17);
}
