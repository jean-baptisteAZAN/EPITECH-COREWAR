/*
** EPITECH PROJECT, 2022
** struct_all.h
** File description:
** struct for corewar
*/

#pragma once

#include <stdio.h>

/////////////////////////////////////////////////////////
//////////////////////////////// DEFINE ////////////////
///////////////////////////////////////////////////////

// PC = Program Counter = INDEX DU CHAMPION ACTUEL
// #define PC st_core->st_player->...

////////////////////////////////////////////////////////
////////////////////////////// STRUCTS OTHERS /////////
//////////////////////////////////////////////////////

    typedef struct st_info {
        int ac;
        char **av;
        int cycle; // nb cycle to end of cycle
        int nb_live; // number of lives
        int dmp; // Dump
        int size_arena; // size of arena
        int size_reg;
        int size_alloc_st_player;
    } st_i;

    typedef struct st_player {
        int *pos_champ;

        int nb_live; // number of lives
        int dump; // Value of dump -> NB cycle for stopping
        int nb_players; // Number of players
        int pos_player; // Position of player
        int winner; // Winner
        int nb_cycle; // Number of cycles
        int cycle_to_die; // Cycle to die <- CYCLE_TO_DIE
        int n_cycle_to_die; // n <- CYCLE_TO_END

        //// FOR INIT ///
        int error; // Error == 84 in function get_player
        int arg_n; // For initialization arguments -> '-n'
        int arg_a; // For initialization arguments -> '-a'
        int nb_dump; // Temporary memory for get_player

        int nb_player_live_end_game;
        int player_winner_end_game;
        int tempo_cycle;
    } st_p;

    typedef struct st_champ {
        int nw_adres;
        int cmd;
        int *cod_bytes;
        int *arg;
        int live; // if 0 = dead, 1 = live
        char *name; // Name of player
        char *path_file; // path_file of player
        int adres; // PC -> default = -1 | ou '-a' (si dead = -2)
        int prog_nb; // default = 0 else position for player in arena ("-n")
        int carry; // if 0 = no carry, 1 = carry (?) -> for xjump
        int *registers; // Registers of player
        int status; // Nombre de tour avant d'exec la cmd
        int dead; // Is player dead? if 0 a alive | if 1 dead
        // Save proto + arguments

        int size_prog; // Size of program for champions
    } st_ch;


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// STRUCT MAIN //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    typedef struct st_core {
        unsigned char *arena; // Memory arena
        st_i *st_info; // INFO BASIC
        st_p *st_player; // INFO PLAYER
        int size_struct; // Size of st_champ
        int error_load_cmd;
        int *proto;
        int *arg;
        st_ch **st_champ; // INFO CHAMPIONS
    } st_c;


////////////////////////////////////////////////////////////////////////////////
/////////////////////////// STRUCT GORBAGE COLLECTOR ///////////////////////////
////////////////////////////////////////////////////////////////////////////////

    typedef struct GCNode {
        void* pointer;
        struct GCNode* next;
    } GCNode;

    typedef struct {
        GCNode* head;
    } GarbageCollector;
