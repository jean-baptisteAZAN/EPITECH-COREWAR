/*
** EPITECH PROJECT, 2023
** init_struct.c
** File description:
** Function that initialize the struct
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

int malloc_struct_champ(st_c *st_core)
{
    st_core->st_info->size_alloc_st_player = 4;
    st_core->st_champ =
        my_malloc(sizeof(st_ch *) * (st_core->st_info->size_alloc_st_player));
    if (st_core->st_champ == NULL)
        return 84;
    for (int n = 0; n < st_core->st_info->size_alloc_st_player; n++) {
        st_core->st_champ[n] = my_malloc(sizeof(st_ch));
        if (st_core->st_champ[n] == NULL)
            return 84;
        st_core->size_struct++;
    }
    return 0;
}

int malloc_struct(st_c *st_core, int ac)
{
    st_core->size_struct = 0;
    st_core->st_info = my_malloc(sizeof(st_i));
    if (st_core->st_info == NULL)
        return 84;
    st_core->st_player = my_malloc(sizeof(st_p));
    if (st_core->st_player == NULL)
        return 84;
    st_core->arena = my_malloc(sizeof(char) * MEM_SIZE);
    if (st_core->arena == NULL)
        return 84;
    st_core->st_info->av = my_malloc(sizeof(char *) * (ac + 2));
    if (st_core->st_info->av == NULL)
        return 84;
    st_core->proto = my_malloc(sizeof(int) * 6);
    st_core->arg = my_malloc(sizeof(int) * 5);
    return 0;
}

void initialize_struct(st_c *st_core, int ac, char **av)
{
    st_core->st_info->size_arena = MEM_SIZE;
    st_core->st_info->cycle = CYCLE_TO_DIE;
    st_core->st_player->pos_player = 0;
    for (int n = 0; n < ac; n++)
        st_core->st_info->av[n] = my_strdup(av[n]);
    for (int n = 0; n < st_core->st_info->size_alloc_st_player; n++) {
        complet_player(st_core, n);
    }
    st_core->st_info->av[ac] = NULL;
    st_core->st_info->av[ac + 1] = NULL;
    st_core->st_info->ac = ac;
    st_core->st_player->nb_players = 0;
    st_core->st_player->nb_dump = 0;
}

void memset_struct(st_c *st_core)
{
    for (int n = 0; n < MEM_SIZE; n++)
        st_core->arena[mod(n)] = 0;
}

int init_struct(st_c *st_core, int ac, char **av)
{
    if (malloc_struct(st_core, ac) == 84) {
        my_printf("Error: my_malloc failed\n");
        return 84;
    }
    if (malloc_struct_champ(st_core) == 84) {
        my_printf("Error: my_malloc failed\n");
        return 84;
    }
    memset_struct(st_core);
    initialize_struct(st_core, ac, av);
    return 0;
}
