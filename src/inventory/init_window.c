/*
** EPITECH PROJECT, 2019
** MAIN RUNNER
** File description:
** RUNNER
*/

#include <SFML/Graphics.h>

sfRenderWindow *initialisation_window(sfRenderWindow *window, char *str)
{
    sfVideoMode mode = {800, 650, 50};

    window = sfRenderWindow_create(mode, str, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (window);
}
