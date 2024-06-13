/*
** EPITECH PROJECT, 2023
** bit
** File description:
** endian
*/

#include "my.h"
#include "op.h"
#include "asm.h"

int convert_big_endian(int value)
{
    return ((value >> 24) & 0xFF) |
    ((value >> 8) & 0xFF00) |
    ((value << 8) & 0xFF0000) |
    ((value << 24) & 0xFF000000);
}

short int convert_short_endian(short int value)
{
    return (value << 8) | ((value >> 8) & 0xFF);
}
