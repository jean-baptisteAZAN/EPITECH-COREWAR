/*
** EPITECH PROJECT, 2023
** prepa_champions.c
** File description:
** Preparation of the champions
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

#include <fcntl.h>

int not_exist_prog(st_c *st_core, int n)
{
    for (int i = 0; i < st_core->st_player->nb_players; i++) {
        if (st_core->st_champ[i]->prog_nb == n)
            return 0;
    }
    return 1;
}

void prepa_prog_nb(st_c *st_core)
{
    int nb_player_good = 0;
    int n = 1;
    for (; nb_player_good < (st_core->st_player->nb_players - 1); n++) {
        if (st_core->st_champ[nb_player_good]->prog_nb != 0 &&
        nb_player_good < st_core->st_player->nb_players)
            nb_player_good++;
        if (st_core->st_champ[nb_player_good]->prog_nb == 0 &&
            not_exist_prog(st_core, n) == 1)
            st_core->st_champ[nb_player_good]->prog_nb = n;
    }
}

int save_header_champion(st_c *st_core, struct header_s header, int n)
{
    if (my_strlen(header.prog_name) > PROG_NAME_LENGTH) {
        display_error(st_core, "Error: program name too long\n");
        return 84;
    }
    st_core->st_champ[n]->name = my_strdup(header.prog_name);
    return 0;
}

int prepa_one_champion(st_c *st_core, int n)
{
    int fd = open(st_core->st_champ[n]->path_file, O_RDONLY);
    struct header_s header;
    int bytes_read = read(fd, &header, sizeof(struct header_s));
    if (bytes_read != sizeof(struct header_s)) {
        display_error(st_core, "Error: read file ");
        my_printf("%s failed\n", st_core->st_champ[n]->path_file);
        close(fd);
        return 84;
    }
    get_size_prog(st_core, fd, n);

    if (verif_magic_nb(st_core, header.magic) == 84)
        return 84;
    if (save_header_champion(st_core, header, n) == 84)
        return 84;
    if (get_prog(st_core, header, n, fd) == 84)
        return 84;
    close(fd);
    return 0;
}

int prepa_champions(st_c *st_core)
{
    for (int n = 0; n < st_core->st_player->nb_players; n++) {
        if (prepa_one_champion(st_core, n) == 84)
            return 84;
        if (st_core->st_player->error == 84)
            return 84;
    }
    prepa_prog_nb(st_core);
    for (int n = 0; n < st_core->st_player->nb_players; n++)
        st_core->st_champ[n]->registers[0] = st_core->st_champ[n]->prog_nb;
    return 0;
}
