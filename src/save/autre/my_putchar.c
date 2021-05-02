/*
** EPITECH PROJECT, 2019
** psu_navy_2019
** File description:
** my_putchar.c
*/

#include <unistd.h>

void my_putchar(char x)
{
    write(1, &x, 1);
}