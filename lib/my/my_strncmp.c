/*
** EPITECH PROJECT, 2022
** strncmp
** File description:
** yes
*/

int my_strncmp(const char *s1, char *s2, int n)
{
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            a++;
            return s1[i] - s2[i];
        }
        if (s1[i] == '\0' && a == 0)
            return (0);
    }
    return (0);
}
