/*
** EPITECH PROJECT, 2023
** gestion_arg.c
** File description:
** function for gestion argument
*/

#include "my.h"
#include "op.h"
#include "asm.h"

void help(void)
{
    my_printf("USAGE\n./asm file_name[.s]\nDESCRIPTION\n");
    my_printf("file_name file in assembly language to be converted ");
    my_printf("into file_name.cor, an\nexecutable in the Virtual Machine.\n");
}

int gestion_args(int ac, char **av)
{
    if (ac < 2) {
        return disp_error("Usage: ./asm file_name[.s] ....\n");
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help();
        return 0;
    }
    return 1;
}
