/*
** EPITECH PROJECT, 2019
** Sftext
** File description:
** main.c
*/

#include "my.h"

sfVector2f set_pos(int x, int y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return vec;
}

sfText *create_texte(char const *str, sfVector2f pos)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile("./atwriter.ttf");

    sfText_setString(texte, str);
    sfText_setFont(texte, font);
    sfText_setColor(texte, sfWhite);
    sfText_setStyle(texte, sfTextRegular);
    sfText_setPosition(texte, pos);
    sfText_setCharacterSize(texte, 16);
    return texte;
}
