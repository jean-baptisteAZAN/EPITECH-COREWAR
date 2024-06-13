/*
** EPITECH PROJECT, 2023
** display_error.c
** File description:
** message for error
*/

#include "my.h"
#include "asm.h"
#include "op.h"

int disp_error(char *str)
{
    write(2, str, my_strlen(str));
    return 84;
}
