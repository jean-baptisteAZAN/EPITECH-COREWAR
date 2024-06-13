/*
** EPITECH PROJECT, 2023
** pars
** File description:
** ing
*/

#include "my.h"
#include "asm.h"
#include "op.h"

void sub_remove_comments(char *line)
{
    int comment_start = -1;
    for (int j = 0; line[j] != '\0'; j++) {
        if (line[j] == COMMENT_CHAR) {
            comment_start = j;
            break;
        }
    }
    if (comment_start != -1) {
        for (int j = comment_start; line[j] != '\0'; j++)
            line[j] = ' ';
    }
}

int sub_sub_remove_comments(char *line, char **result, int result_index)
{
    int is_empty = 1;
    for (int j = 0; line[j] != '\0'; j++) {
        if (line[j] != ' ' && line[j] != '\t') {
            is_empty = 0;
            break;
        }
    }
    if (!is_empty) {
        result[result_index] = line;
        result_index++;
    }
    return result_index;
}

char **remove_comments(char **lines)
{
    int num_lines = 0;
    int non_empty_lines = 0;
    while (lines[num_lines] != NULL) {
        if (my_strlen(lines[num_lines]) > 0) {
            non_empty_lines++;
        }
        num_lines++;
    }
    char **result = my_malloc((non_empty_lines + 1) * sizeof(char*));
    result[non_empty_lines] = NULL;
    int result_index = 0;
    for (int i = 0; i < num_lines; i++) {
        char *line = lines[i];
        sub_remove_comments(line);
        result_index = sub_sub_remove_comments(line, result, result_index);
    }
    return result;
}

char **parse_args_file(char *buf, cmd_infos *cmd)
{
    char **tab_back_n = my_str_to_word_array(buf, '\n');
    for (int i = 0; tab_back_n[i]; i++) {
        tab_back_n[i] = my_cleanstr(tab_back_n[i]);
    }
    tab_back_n = remove_comments(tab_back_n);
    char **tab_name = my_str_to_word_array(tab_back_n[0], '"');
    char **comment = my_str_to_word_array(tab_back_n[1], '"');
    cmd->name = tab_name[1];
    cmd->comment = comment[1];
    return (tab_back_n);
}
