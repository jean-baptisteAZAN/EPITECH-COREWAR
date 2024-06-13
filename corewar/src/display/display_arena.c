/*
** EPITECH PROJECT, 2023
** display_arena.c
** File description:
** Display arena information -> memory usage
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

void print_hex(unsigned char nbr)
{
    const char label_char[] = "0123456789ABCDEF";
    char str[3];
    str[0] = label_char[nbr / 16];
    str[1] = label_char[nbr % 16];
    str[2] = '\0';
    write(1, str, 2);
}

void display_arena(st_c *st_core)
{
    int a = 0;
    int b = 0;
    while (a < MEM_SIZE) {
        print_hex(st_core->arena[mod(a)]);
        write(1, " ", 1);
        if (b == 31) {
            write(1, "\n", 1);
            b = -1;
        }
        a++;
        b++;
    }
}
