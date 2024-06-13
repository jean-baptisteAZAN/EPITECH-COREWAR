/*
** EPITECH PROJECT, 2022
** square root
** File description:
** square root
*/

#include <unistd.h>

int my_compute_square_root(int nb)
{
    int cpt = 1;
    for (int valeur = cpt * cpt ; valeur <= nb ; cpt ++) {
        valeur = cpt * cpt;
        if (valeur == nb) {
            return (cpt);
        }
        if (cpt > 46340) {
            return (0);
        }
    }
    return (0);
}
