/*
** EPITECH PROJECT, 2022
** mystrstr
** File description:
** task05
*/

#include <unistd.h>

int my_strlen7(char const *str)
{
    int compt = 0;
    int i = 0;
    while (str[i] != '\0') {
        compt++;
        i++;
    }
    return (compt);
}

int sub_my_strstr(char *str, char const *to_find, int i, int v)
{
    if (str[i] == to_find[v]) {
        v++;
        return (v);
    } else if (v > 0) {
        v = 0;
    }
    return (v);
}

char *my_strstr(char *str , char const *to_find)
{
    int v = 0;
    int index = -1;
    int length_str = my_strlen7(str);
    int length_str_to_find = my_strlen7(to_find);
    if (length_str_to_find > length_str)
        return 0;
    if (length_str == 0 || length_str_to_find == 0)
        return 0;
    for (int  i = 0; str[i] != '\0' ;i++){
        if (str[i] == to_find[v] && v == 0 ) {
            v++;
            index = i;
        } else {
            v = sub_my_strstr( str, to_find, i, v);
        }
    }
    if (index == -1)
        return 0;
    return (&str[index]);
}
