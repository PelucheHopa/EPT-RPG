/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** str
*/

#include "rpg.h"

void my_putstr(char const *str)
{
    int z = 0;

    while (str[z] != '\0') {
        my_putchar(str[z]);
        z++;
    }
}
