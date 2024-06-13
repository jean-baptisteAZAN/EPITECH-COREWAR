/*
** EPITECH PROJECT, 2023
** check_cmd_is_good.c
** File description:
** Player the full champions
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

static int (*check_exc_cmd[])(st_c *, int, int *, int *) =
{
    check_cmd_live,
    check_cmd_ld,
    check_cmd_st,
    check_cmd_add,
    check_cmd_sub,
    check_cmd_and,
    check_cmd_or,
    check_cmd_xor,
    check_cmd_zjmp,
    check_cmd_ldi,
    check_cmd_sti,
    check_cmd_fork,
    check_cmd_lld,
    check_cmd_lldi,
    check_cmd_lfork,
    check_cmd_aff,
    NULL
};

// Pos -> position of the champion in the struct st_champ
// Return 1 if the command is good else return 0
int check_cmd_is_good(st_c *st_core, int pos)
{
    int cmd = st_core->arena[mod(st_core->st_champ[pos]->adres)];
    if (cmd < 1 || cmd > 16)
        return 0;
    st_core->st_champ[pos]->nw_adres = st_core->st_champ[pos]->adres;
    st_core->st_champ[pos]->adres++;
    st_core->st_champ[pos]->cmd = (cmd - 1);
    st_core->error_load_cmd = 0;
    st_core->st_champ[pos]->status = -3;
    reset_cod_bytes_args(st_core, pos);
    int *tab_coding_bytes = get_coding_bytes(st_core,
        st_core->arena[mod(st_core->st_champ[pos]->adres)], pos);
    int *args_cmd = get_arg(st_core, pos, tab_coding_bytes);
    if (st_core->error_load_cmd == -1)
        return 0;
    if (check_exc_cmd[(int)cmd - 1](st_core, pos, tab_coding_bytes, args_cmd)
        == -1)
            return 0;
    st_core->st_champ[pos]->status = op_tab[cmd - 1].nbr_cycles + 1;
    return 1;
}
