/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../../include/my.h"
#include "../../include/op.h"
#include "../../include/asm.h"

char *reformat_name_file(char *tmp)
{
    int i = my_strlen(tmp) - 1;
    int a = 0;
    if (no_slash == false)
        return (tmp);
    for (; tmp[i] && tmp[i] != '/'; i--);
    i++;
    int len = my_strlen(&tmp[i]);
    char *new_file = my_malloc(sizeof(char) * (len + 1));
    for (; tmp[i]; i++, a++)
        new_file[a] = tmp[i];
    new_file[a] = '\0';
    return (new_file);
}

void parse_file(char *buf, char *filename, cmd_infos *cmd)
{
    int cpt = 0;
    cmd->prog_size = 0;
    cmd->tab_file = my_str_to_word_array(buf, '\n');
    verif_all_error_header(buf, filename, cmd, cpt);
    cmd->tab_file = parse_args_file(buf, cmd);
    get_tab_label(cmd);
    error_tab_file(cmd->tab_file);
    if ((cmd->fd_file = open(filename, O_WRONLY
    | O_CREAT | O_TRUNC, 0644)) == -1)
        exit(84);
    cmd->prog_size = get_size_file(cmd->tab_file);
}

void asm_read(char **argv, int argc)
{
    for (int i = 1; i < argc; i++) {
        cmd_infos *cmd = my_malloc(sizeof(cmd_infos));
        header_t *head = my_malloc(sizeof(header_t));
        char *buf = NULL;
        char *filename = my_strdup(argv[i]);
        int fd = 0;
        if ((fd = open(filename, O_RDONLY)) < 0)
            exit(84);
        off_t filesize = lseek(fd, 0, SEEK_END);
        lseek(fd, 0, SEEK_SET);
        buf = my_malloc(filesize + 1);
        ssize_t read_bytes = read(fd, buf, filesize);
        buf[read_bytes] = '\0';
        if (my_strlen(buf) < 1) exit(84);
        cmd->inp_filename = my_strdup(filename);
        filename = get_name_file(filename);
        parse_file(buf, filename, cmd);
        write_header(cmd, head);
        write_args(cmd);
    }
}

int main(int argc, char **argv)
{
    int tmp = 0;
    if ((tmp = gestion_args(argc, argv)) != 1)
        return tmp;

    asm_read(argv, argc);
    full_free();
    return (0);
}
