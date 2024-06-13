/*
** EPITECH PROJECT, 2022
** int len
** File description:
** len int
*/

int intlen(int n)
{
    int storage = 0;

    while (n > 0) {
        n = n / 10;
        storage++;
    }
    return (storage);
}
