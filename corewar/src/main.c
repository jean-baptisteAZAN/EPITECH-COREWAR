/*
** EPITECH PROJECT, 2023
** main_corewar
** File description:
** corewar
*/

#include "my.h"
#include "struct_all.h"

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    st_c *st_core = my_malloc(sizeof(st_c));
    if (init_struct(st_core, ac, av) == 84) {
        full_free();
        return 84;
    }
    int error = load(st_core);
    if (error != -1) {
        full_free();
        return error;
    }
    int tmp = home_arena(st_core);
    full_free();
    return tmp;
}
