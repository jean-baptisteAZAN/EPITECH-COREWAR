/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** Function who check if the parameter is a register or a number
*/

#include "../../../include/my.h"


// If the parameter is a register: 01
// If the parameter is a direct: 10
// If the parameter is an indirect: 11
// Otherwise: 00
// if ((two_f_bits & 0b11) == 0b01) --> Compare si c'est un register

int is_a_register_or_nbr(int nbr)
{
    int two_f_bits = (nbr >> (sizeof(int) * 8 - 2));
    two_f_bits &= 0b11;
    if ((two_f_bits & 0b11) == 0b01)
        return 1;
    else
        return 0;
}
