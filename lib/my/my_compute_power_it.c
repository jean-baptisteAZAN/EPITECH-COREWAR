/*
** EPITECH PROJECT, 2022
** task03
** File description:
** task03
*/

#include <unistd.h>

int my_compute_power_it(int nb, int p)
{
    int resultat = 1;
    if (p == 0 || nb == 0) {
        return (0);
    }
    for (int compt = 0; compt != p; compt++) {
        resultat = resultat * nb;
    }
    return (resultat);
}
