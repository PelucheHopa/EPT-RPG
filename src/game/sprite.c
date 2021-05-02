/*
** EPITECH PROJECT, 2020
** sprite
** File description:
** sprite
*/

#include "rpg.h"

sfSprite *set_sprite(char *path, int x, int y)
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position = {x, y};

    texture = sfTexture_createFromFile(path, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    return (sprite);
}

sfMusic *set_music_game(char *str)
{
    sfMusic *s_music;

    s_music = sfMusic_createFromFile(str);
    sfMusic_setVolume(s_music, 0);
    sfMusic_play(s_music);
    return (s_music);
}
