/*
** EPITECH PROJECT, 2019
** psu_navy_2019
** File description:
** my_putstr.c
*/

#include "save.h"

void my_putstr(char *str)
{
    for (int index = 0; str[index] != '\0'; index++)
        my_putchar(str[index]);
}
