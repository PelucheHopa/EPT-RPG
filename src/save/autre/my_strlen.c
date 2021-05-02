/*
** EPITECH PROJECT, 2019
** psu_navy_2019
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int index = 0;

    for (index = 0; str[index] != '\0'; index++);
    return index;
}