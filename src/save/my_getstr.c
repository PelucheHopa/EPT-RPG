/*
** EPITECH PROJECT, 2019
** my_getstr
** File description:
** reverse my_getnbr
*/

#include <stdlib.h>

char *my_getstr(int nbr)
{
    int x = 1;
    int letter = 1;
    int lock = 0;
    char *result = NULL;

    for (; nbr / x > 0 ; x = x * 10, letter++);
    x = x / 10;
    result = malloc(sizeof(char) * (letter));
    letter = 0;
    for (; x > 0 ; x = x / 10, letter++) {
        result[letter] = nbr / x + 48;
        result[letter + 1] = '\0';
        nbr = nbr % x;
        lock = 1;
    }
    if (lock == 0)
        return ("0");
    return (result);
}
