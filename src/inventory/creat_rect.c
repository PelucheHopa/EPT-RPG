/*
** EPITECH PROJECT, 2019
** MAIN RUNNER
** File description:
** RUNNER
*/

#include <SFML/Graphics.h>

sfIntRect creat_int_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}
