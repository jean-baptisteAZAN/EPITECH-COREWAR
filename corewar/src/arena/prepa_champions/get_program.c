/*
** EPITECH PROJECT, 2023
** get_program.c
** File description:
** Prepare the program for champions
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

#include <fcntl.h>

// Ecrit dans l'arena le program_data au bon endroit pour le champion
int write_prog_champion(st_c *st_core, unsigned char *program_data, int n)
{
    int espace_cham = MEM_SIZE / st_core->st_player->nb_players;
    int pos = espace_cham * n;

    if (st_core->st_champ[n]->adres == -1)
        st_core->st_champ[n]->adres = pos;
    else
        pos = st_core->st_champ[n]->adres;

    for (int i = 0; i < st_core->st_champ[n]->size_prog; i++) {
        if (st_core->arena[mod(pos + i) % MEM_SIZE] != 0)
            return display_error(st_core, "Overlap detected !\n");
        else
            st_core->arena[mod(pos + i) % MEM_SIZE] = program_data[i];
    }
    return 0;
}

static void display_error_get_prog(st_c *st_core, int n)
{
    display_error(st_core, "Error: read file ");
    my_printf("%s failed (size program not good)\n",
        st_core->st_champ[n]->path_file);
}

int check_name_file(st_c *st_core, char *path)
{
    if (my_strlen(path) < 4) {
        display_error(st_core, "Error: extension of file is not correct\n");
        return -1;
    }
    int size = my_strlen(path);
    if (path[size - 4] != '.' || path[size - 3] != 'c' ||
        path[size - 2] != 'o' || path[size - 1] != 'r') {
        display_error(st_core, "Error: extension of file is not correct\n");
        return -1;
    }
    return 0;
}

int get_prog(st_c *st_core, struct header_s header, int n, int fd)
{
    if (check_name_file(st_core, st_core->st_champ[n]->path_file) == -1)
        return -1;
    close(fd);
    int fdee = open(st_core->st_champ[n]->path_file, O_RDONLY);
    unsigned char *program_data =
        my_malloc(sizeof(char) * st_core->st_champ[n]->size_prog);
    lseek(fdee, sizeof(header), SEEK_SET);
    int bytes_read = read(fdee, program_data, st_core->st_champ[n]->size_prog);
    if (bytes_read != st_core->st_champ[n]->size_prog) {
        display_error_get_prog(st_core, n);
        close(fd);
        return 84;
    }
    if (write_prog_champion(st_core, program_data, n) == 84) {
        close(fd);
        return 84;
    }
    return 0;
}
