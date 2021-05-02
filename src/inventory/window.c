/*
** EPITECH PROJECT, 2019
** MAIN RUNNER
** File description:
** RUNNER
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void close_window(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            sfRenderWindow_close(window);
        }
    }
}

void clear_window(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
}
