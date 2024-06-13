/*
** EPITECH PROJECT, 2023
** utils_program.c
** File description:
** Utils for prepare the program for champions
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

void get_size_prog(st_c *st_core, int fd, int n)
{
    int offset = 136;
    char bin[5] = {0};

    bin[4] = '\0';
    lseek(fd, offset, SEEK_SET);
    read(fd, bin, 4);
    st_core->st_champ[n]->size_prog = convert_str_to_int_hexa((char *)bin, 4);
}

int convert_big_endian(int value)
{
    return ((value >> 24) & 0xFF) |
    ((value >> 8) & 0xFF00) |
    ((value << 8) & 0xFF0000) |
    ((value << 24) & 0xFF000000);
}

int verif_magic_nb(st_c *st_core, int magic)
{
    if (convert_big_endian(magic) != COREWAR_EXEC_MAGIC)
        return display_error(st_core, "Error: bad magic number\n");
    return 0;
}
