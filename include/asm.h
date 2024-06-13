/*
** EPITECH PROJECT, 2023
** asm
** File description:
** asm
*/

/////////////////////////////////////////////////////////
//////////////////////////////// INCLUDE////////////////
///////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "op.h"

#pragma once

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// STRUCT MAIN //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
    typedef struct {
        char *header;
        char *name;
        char *comment;
        char *inp_filename;
        bool first;
        int fd_file;
        int size_file;
        char **tab_label; //tableau decla label
        int *tab_pos_label; // tableau pos decla
        int size_tab_label;
        int nb_label;
        char **tab_file;
        int prog_size;
        int i;
    } cmd_infos;


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


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// PROTO ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void verif_all_error_header(char *buf, char *filename, cmd_infos *cmd, int cpt);
char **divide_in_2_str(char *str, char c);
char *my_cleanstr(char *str);
char *get_name_format(char* filename);
char **parse_args_file(char *buf, cmd_infos *cmd);
char *get_name_file(char *file_name);
int get_size_file(char **tab);
int get_size_line(char *str);
short int convert_short_endian(short int value);
int convert_big_endian(int value);
bool no_slash(char *str);
char *reformat_name_file(char *tmp);
void write_args(cmd_infos *cmd);
bool is_digit(char c);
void write_params(cmd_infos *cmd, char **tab, int index_tab);
int transform_binary_to_decimal(const char *binary);
int get_arg_type(char *arg);
void write_t_dir(int index_tab, char *str, cmd_infos *cmd, char **tab);
int get_label_nbr(char *tab, cmd_infos *cmd);
void error_tab_file(char **tab);
int get_size_tab(char **tab);

    //////////////////////// WRITE HEADER ///
    /**/    void write_header(cmd_infos *cmd, header_t *head);
    /**/    void *my_memset(void *ptr, int value, size_t num);
    /////////////////////////////////

    //////////////////////// GET_TAB_LABEL ///
    /**/    int get_tab_label(cmd_infos *st_cmd);
    /**/    char *cut_beg_string(char *str, int cut);
    /**/    void remove_first_two(char **strings);
    /**/    int check_cara_is_label(char str);
    /////////////////////////////////

    //////////////////////// MY_MALLOC and MY_FREE ///
    /**/    void* my_realloc(void* ptr, size_t size);
    /**/    void* my_malloc(size_t size);
    /**/    void full_free(void);
    /**/    char *my_strdup_mac(char const *src);
    /////////////////////////////////

    //////////////////////// ERROR ///
    /**/    int disp_error(char *str);
    /**/    int gestion_args(int ac, char **av);
    /////////////////////////////////
