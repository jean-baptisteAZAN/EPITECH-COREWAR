/*
** EPITECH PROJECT, 2023
** get_cod_bytes_arg.c
** File description:
** Get proto and arg
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

int *get_coding_bytes(st_c *st_core, int cod_bytes, int pos)
{
    int *tmp = st_core->st_champ[pos]->cod_bytes;

    if (op_tab[st_core->st_champ[pos]->cmd].nbr_args == 1 && pos != 15) {
        tmp[0] = op_tab[st_core->st_champ[pos]->cmd].type[0];
        tmp[1] = -1;
        return tmp;
    }

    for (int n = 0; n < 4; n++) {
        tmp[n] = ((((cod_bytes >> 6) >> 1) & 1) << 1) + ((cod_bytes >> 6) & 1);
        cod_bytes = cod_bytes << 2;
        if (tmp[n] == 0)
            tmp[n] = -1;
    }

    st_core->st_champ[pos]->adres++;
    return tmp;
}

int get_byte_size(int command, int type)
{
    const char *pro_i[] = {"zjmp", "ldi", "sti", "fork", "lfork", "lldi", NULL};
    static const int type_proto[] = {[2] = DIR_SIZE, [4] = IND_SIZE, [1] = 1};
    int id = 0;
    while (op_tab[id].mnemonique && op_tab[id].code != command + 1)
        id++;
    if (type != T_REG && check_list(op_tab[id].mnemonique, (char **)pro_i))
        return (2);
    else
        return (type_proto[type]);
}

void patch_exception(st_c *st_core, int pos)
{
    if (st_core->st_champ[pos]->cmd == 9 || st_core->st_champ[pos]->cmd == 12 ||
        st_core->st_champ[pos]->cmd == 15) {
        if (st_core->st_champ[pos]->cod_bytes[0] == DIR_SIZE)
            st_core->st_champ[pos]->cod_bytes[0] = IND_SIZE;
        if (st_core->st_champ[pos]->cod_bytes[1] == DIR_SIZE)
            st_core->st_champ[pos]->cod_bytes[1] = IND_SIZE;
        if (st_core->st_champ[pos]->cod_bytes[2] == DIR_SIZE)
            st_core->st_champ[pos]->cod_bytes[2] = IND_SIZE;
    }
    if (st_core->st_champ[pos]->cmd == 9) {
        if (st_core->st_champ[pos]->cod_bytes[0] == DIR_SIZE)
            st_core->st_champ[pos]->cod_bytes[0] = IND_SIZE;
    }
    if (st_core->st_champ[pos]->cmd == 10 ||
        st_core->st_champ[pos]->cmd == 14) {
        if (st_core->st_champ[pos]->cod_bytes[0] == DIR_SIZE)
            st_core->st_champ[pos]->cod_bytes[0] = IND_SIZE;
        if (st_core->st_champ[pos]->cod_bytes[1] == DIR_SIZE)
            st_core->st_champ[pos]->cod_bytes[1] = IND_SIZE;
    }
}

// Pos = position dans la struct du champion (st_coret->st_champ)
int *get_arg(st_c *st_core, int pos, int *proto)
{
    static const int type_proto_for[] = {[1] = T_REG, [2] = T_DIR, [3] = T_IND};
    int *arg = st_core->st_champ[pos]->arg;
    int tp = 0;
    int n = 0;
    int a = 0;
    arg[0] = 0;
    int cmd = st_core->st_champ[pos]->cmd;
    for (int size = 0; proto[n] != -1; n++, a = a + size) {
        patch_exception(st_core, pos);
        tp = type_proto_for[proto[n]];
        if ((op_tab[cmd].type[n] & tp) != tp) {
            st_core->error_load_cmd = -1;
            return arg;
        }
        size = get_byte_size(cmd, tp);
        arg[n] = read_arena(st_core, pos, size, n);
        size = 0;
    }
    return arg;
}
