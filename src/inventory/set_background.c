/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_background
*/

#include "my.h"

image_s *set_background(char *img_path)
{
    image_s *img;

    img = malloc(sizeof(image_s));
    img->texture = sfTexture_createFromFile(img_path, NULL);
    img->sprite = sfSprite_create();
    sfSprite_setTexture(img->sprite, img->texture, 0);
    return (img);
}