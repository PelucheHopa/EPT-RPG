/*
** EPITECH PROJECT, 2020
** view
** File description:
** view
*/

#include "dialogue.h"
#include "rpg.h"
#include "get_next_line.h"

void view_player(int a, int b, sfRenderWindow *window)
{
    sfView *cam;

    cam = sfView_createFromRect((sfFloatRect){a, b, 800, 600});
    sfRenderWindow_setView(window, cam);
}

sfView *set_view(int a, int b, sfRenderWindow *window)
{
    sfView *view;

    view = sfView_createFromRect((sfFloatRect){a, b, 800, 600});
    sfRenderWindow_setView(window, view);
    return (view);
}
