/*
** EPITECH PROJECT, 2023
** header
** File description:
** he
*/

#include "my.h"
#include "asm.h"
#include "op.h"

char *clear_line(char *str)
{
    char *string = my_malloc(sizeof(char) * (my_strlen(str) + 1));
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '"' && str[i] != '\n') {
            string[j] = str[i];
            j++;
        }
    }
    string[j] = '\0';
    return string;
}

void error_header_format(char **tab_file, char *filename, int i)
{
    if (my_strncmp(tab_file[0], NAME_CMD_STRING, 5) != 0) {
        my_puterror("asm");
        my_puterror(get_name_format(filename));
        my_puterror(", line ");
        my_puterror(int_to_char(i + 1));
        my_puterror(": Invalid instruction.\n");
        exit(84);
    }
    if (my_strncmp(tab_file[1], COMMENT_CMD_STRING,
    COMMENT_LENGTH != 0)) {
        my_puterror("asm");
        my_puterror(get_name_format(filename));
        my_puterror(", line ");
        my_puterror(int_to_char(i + 1));
        my_puterror(": Invalid instruction.\n");
        exit(84);
    }
}

void error_header_tab(char **tab_line_comment_error, char **tab_line_name_error,
cmd_infos *cmd, int i)
{
    tab_line_name_error[0] = my_cleanstr(tab_line_name_error[0]);
    tab_line_comment_error[0] = my_cleanstr(tab_line_comment_error[0]);
    if ((my_strcmp(tab_line_name_error[0], NAME_CMD_STRING) != 0) ||
        (my_strcmp(tab_line_comment_error[0], COMMENT_CMD_STRING) != 0) ||
        (my_strlen(tab_line_name_error[0]) == 0) ||
        (my_strlen(tab_line_comment_error[0]) == 0))
        exit(84);
}

void verif_all_error_header(char *buf, char *filename, cmd_infos *cmd, int cpt)
{
    for (int i = 0; cmd->tab_file[i]; i++) {
        my_cleanstr(cmd->tab_file[i]);
        if (cmd->tab_file[i][0] == '.' && cpt <= 2) {
            cmd->tab_file[i + 1] = my_cleanstr(cmd->tab_file[i + 1]);
            char **tab_line_name = my_str_to_word_array(cmd->tab_file[i], '"');
            char **tab_line_comment = my_str_to_word_array(cmd->tab_file[i + 1],
            '"');
            error_header_tab(tab_line_comment, tab_line_name, cmd, i);
            cmd->name = clear_line(tab_line_name[1]);
            cmd->comment = clear_line(tab_line_comment[1]);
            break;
        }
        if (cmd->tab_file[i][0] != '#' && cmd->tab_file[i][0] != '\0' &&
            cmd->tab_file[i][0] != ' ')
            error_header_format(cmd->tab_file, cmd->inp_filename, i);
    }
}
