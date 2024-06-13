/*
** EPITECH PROJECT, 2023
** home_excute_cmd.c
** File description:
** Player the full champions
*/

#include "my.h"
#include "struct_all.h"
#include "op.h"

static int (*exc_cmd[])(st_c *, int, int *, int *) =
{
    cmd_live,
    cmd_ld,
    cmd_st,
    cmd_add,
    cmd_sub,
    cmd_and,
    cmd_or,
    cmd_xor,
    cmd_zjmp,
    cmd_ldi,
    cmd_sti,
    cmd_fork,
    cmd_lld,
    cmd_lldi,
    cmd_lfork,
    cmd_aff,
    NULL
};

// If the command is not a valid command, return 0 else return 1
int excute_cmd(st_c *st_core, int n)
{
    int cmd = st_core->st_champ[n]->cmd;
    if (cmd < 0 || cmd > 15)
        return 0;
    st_core->st_champ[n]->status = -3;
    st_core->error_load_cmd = 0;
    return exc_cmd[(int)cmd](st_core, n,
        st_core->st_champ[n]->cod_bytes, st_core->st_champ[n]->arg);
}
