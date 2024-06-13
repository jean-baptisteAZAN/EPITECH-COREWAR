/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** load the vm
*/

#include "my.h"
#include "struct_all.h"

int load(st_c *st_core)
{
    if (verif_help(st_core) == 1)
        return 0;
    if (load_arg(st_core) == 84)
        return 84;
    return -1;
}
