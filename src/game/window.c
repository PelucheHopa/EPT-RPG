/*
** EPITECH PROJECT, 2020
** window
** File description:
** window
*/

#include "rpg.h"

sfRenderWindow *set_window(void)
{
    sfRenderWindow* w;
    sfVideoMode mode = {800, 600, 50};

    w = sfRenderWindow_create(mode, "ISHTAR", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w, 15);
    sfRenderWindow_clear(w, sfBlack);
    return (w);
}
