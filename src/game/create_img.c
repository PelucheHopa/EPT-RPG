/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_img
*/

#include "my.h"

image_s *create_img(char *file_path)
{
    image_s *image;

    image = malloc(sizeof(image_s));
    image->sprite = sfSprite_create();
    image->texture = sfTexture_createFromFile(file_path, NULL);
    sfTexture_setRepeated(image->texture, 0);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    return (image);
}