/*
** EPITECH PROJECT, 2023
** utils_get_player.c
** File description:
** All  functions for file get_player.c
*/

#include "my.h"
#include "struct_all.h"

int display_error(st_c *st_core, char *write_error)
{
    write(2, write_error, my_strlen(write_error));
    st_core->st_player->error = 84;
    return 84;
}
