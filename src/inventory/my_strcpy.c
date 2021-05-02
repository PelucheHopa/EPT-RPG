/*
** EPITECH PROJECT, 2019
** Str_Cpy
** File description:
** Day 6 C_Pool
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int number_character = 0;
    int i = 0;

    while ( str[i] != '\0') {
        number_character += 1;
        i++;
    }
    return number_character;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
