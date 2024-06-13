/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** all prototypes and include
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////
///////////////////////  LIB  //////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include <signal.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <dirent.h>
    #include <termios.h>
    #include <sys/ioctl.h>
    #include <ctype.h>
    #include <glob.h>
    #include <time.h>
    #include <fnmatch.h>
    #include <errno.h>
    #include <stddef.h>

    #include "struct_all.h"
    #include "op.h"

////////////////////// Function ///

        void my_puterror(char const *str);
        void my_putchar1(char c);
        char *my_strdup(char const *src);
        char **my_chardup(char **str, char **src);
        int my_strlen4(char const *str);
        int my_show_word_array(char * const *tab);
        int my_strlen3(char const *str);
        int my_strlen7(char const *str);
        int sub_my_strstr(char *str, char const *to_find, int i, int v);
        void my_putchar(char c);
        char *my_strstr(char *str, char const *to_find);
        int my_isneg(int nb);
        int my_strcmp(char const *s1, char const *s2);
        int my_strncmp(char const *s1, char const *s2, int n);
        void my_swap(int *a, int *b);
        char *my_strupcase(char *str);
        int my_putstr(char const *str);
        char *my_strlowcase(char *str);
        int my_strlen(char const *str);
        char *my_strcapitalize(char *str);
        int my_getnbr(char const *str);
        int my_str_isalpha(char const *str);
        int my_sort_int_array(int *tab, int size);
        int my_str_isnum(char const *str);
        int my_compute_power_rec(int nb, int power);
        int my_str_islower(char const *str);
        int my_compute_square_root(int nb);
        int my_str_isupper(char const *str);
        int my_is_prime(int nb);
        int my_str_isprintable(char const *str);
        int my_find_prime_sup(int nb);
        int my_showstr(char const *str);
        char *my_strcpy(char *dest, char const *src);
        int my_showmem(char const *str, int size);
        char *my_strncpy(char *dest, char const *src, int n);
        char *my_strcat(char const *dest, char const *src);
        char *my_revstr(char *str);
        char *my_strncat(char *dest, char const *src, int nb);
        int my_show_word_array(char *const *tab);
        int sws1(va_list list, int *i, int *cpt, char const *format);
        int sws2(va_list list, int *i, int *cpt, char const *format);
        int sws3(va_list list, int *i, int *cpt, char const *format);
        int swm1(va_list list, int *i, int *cpt, char const *format);
        int swc1(va_list list, int *i, int *cpt, char const *format);
        int modifier(va_list list, int *i, int *cpt, char const *format);
        int modifier2(va_list list, int *i, int *cpt, char const *format);
        int modifier3(va_list list, int *i, int *cpt, char const *format);
        int modifier4(va_list list, int *i, int *cpt, char const *format);
        int modifier5(va_list list, int *i, int *cpt, char const *format);
        char *my_put_nbr(float number);
        char *my_put_nbr_int(int nb);
        int intlen(int n);
        int my_getnbr(char const *str);
        int my_putnbr_base(unsigned int nbr, char const *base);
        char **my_str_to_word_array(char const *str, char separateur);
        int my_printf(const char *format, ...);
        void my_memcpy(void *dest, const void *src, size_t n);
        void my_arencpy(void *dest, const void *src, size_t n);


////////////////////////////////////////////////////////////////////////////////
/////////////////////// COREWAR ////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    //////////////////////// INIT ///
    /**/    int init_struct(st_c *st_core, int ac, char **av);
    /**/    int malloc_struct(st_c *st_core, int ac);
    /**/    void initialize_struct(st_c *st_core, int ac, char **av);
    /**/    void memset_struct(st_c *st_core);
    /**/    void complet_player(st_c *st_core, int pos);
    /////////////////////////////////

    //////////////////////// GET_VALUE_PLAYER ///
    /**/    int get_player(st_c *st_core);
    /**/    void create_player(st_c *st_core, char *path_file);
    /**/    int verif_is_nbr(char *str);
    /**/    void verif_prog_nb(st_c *st_core, int pos_av);
    /**/    int get_nb_player(st_c *info_core);
    /**/    int verif_help(st_c *info_core);
    /////////////////////////////////

    //////////////////////// LOAD ARG ///
    /**/    int load(st_c *st_core);
    /**/    int load_arg(st_c *st_core);
    /**/    int arg_dump(st_c *st_core, char **av, int n);
    /**/    int arg_adress(st_c *st_core, char **av, int n);
    /**/    int arg_prog_nb(st_c *st_core, char **av, int n);
    /**/    int add_path_player(st_c *st_core, char *av);
    /**/    int verif_file_exist(char* path);
    /////////////////////////////////

    //////////////////////// ARENA (VM) ///
    /**/    int home_arena(st_c *st_core);
    /**/    int check_cmd_win(st_c *st_core);
    /**/    void play_player(st_c *st_core);
    /**/    void display_arena(st_c *st_core);
    /**/    int recup_mod(int nb);
    /**/    int check_live(st_c *st_core);
    /**/    void play_player(st_c *st_core);
    /**/    int check_cmd_is_good(st_c *st_core, int pos);
    /**/    void end_game(st_c *st_core);
    /**/    void reset_cod_bytes_args(st_c *st_core, int pos);
    /**/    int my_put_nbr_g(int nb);
    /////////////////////////////////

    //////////////////////// EXCUTE CMD ///
    /**/    int excute_cmd(st_c *st_core, int n);
    /**/    int *get_coding_bytes(st_c *st_core, int cod_bytes, int pos);
    /**/    int *get_arg(st_c *st_core, int pos, int *proto);
    /**/    int mod(int nb);
    /**/    int get_size_tab(int *tab);
    /**/    int check_list(char *str, char **tab);
    /**/    int convert_big_endian(int value);
    /**/    short int short_big_endian(short int value);
    /**/    void my_corecpy(void *dest, const void *src, size_t n);
    /**/    int read_arena(st_c *st_core, int pos, size_t size, int n);
    /////////////////////////////////

    //////////////////////// PREPA CHAMPIONS ///
    /**/    int prepa_champions(st_c *st_core);
    /**/    int get_prog(st_c *st_core, struct header_s header, int n, int fd);
    /**/    void get_size_prog(st_c *st_core, int fd, int n);
    /**/    int verif_magic_nb(st_c *st_core, int magic);
    /////////////////////////////////

    //////////////////////// CONVERT ///
    /**/    int convert_str_to_int_hexa(char *str, int nb_bytes);
    /////////////////////////////////

    //////////////////////// DISPLAY ///
    /**/    int display_error(st_c *st_core, char *write_error);
    /**/    void display_arena(st_c *st_core);
    /**/    void display_win(st_c *st_core, int pos);
    /**/    void display_alive(st_c *st_core, int pos);
    /**/    void display_equa(void);
    /////////////////////////////////

    //////////////////////// INSTRUCTION CMD ///
    /**/    int is_a_register_or_nbr(int nbr);
    /**/    void change_carry(st_c *st_core, int value, int pos);
    /**/    void cmd_sti_with_2_register(st_c *st_core, int pos, int *arg);
    /**/    void cmd_sti_with_1_register(st_c *st_core, int pos, int *arg);
    /**/    void cmd_sti_with_1_register_else(st_c *st_core, int pos, int *arg);
    /**/    void cmd_sti_without_register(st_c *st_core, int pos, int *arg);
    /////////////////////////////////////////////

    //////////////////////// MY_MALLOC and MY_FREE ///
    /**/    void* my_realloc(void* ptr, size_t size);
    /**/    void* my_malloc(size_t size);
    /**/    void full_free(void);
    /////////////////////////////////


    //////////////////////// CMD ///
    /**/    int cmd_add(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_aff(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_and(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_fork(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_ld(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_ldi(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_live(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_lld(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_lldi(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_or(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_st(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_sti(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_sub(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_xor(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_lfork(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int cmd_zjmp(st_c *st_core, int pos, int *proto, int *arg);
    /////////////////////////////////

    //////////////////////// CMD_VERIF ///
    /**/    int check_cmd_add(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_aff(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_and(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_fork(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_ld(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_ldi(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_live(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_lld(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_lldi(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_or(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_st(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_sti(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_sub(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_xor(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_lfork(st_c *st_core, int pos, int *proto, int *arg);
    /**/    int check_cmd_zjmp(st_c *st_core, int pos, int *proto, int *arg);
    /////////////////////////////////
