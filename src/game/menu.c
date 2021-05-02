/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu and pause
*/

#include "dialogue.h"
#include "rpg.h"
#include "get_next_line.h"

void display_big(sys sys)
{
    int a = 215;
    int b = 245;
    sfVector2i coord = sfMouse_getPositionRenderWindow(sys.window);

    if (sys.state == in_menu && coord.x > 220 && coord.x < 590 && \
        coord.y > 240 && coord.y < 355) {
        sfSprite_setPosition(sys.sprite.menu.start_two, (sfVector2f){a, b});
        sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.start_two, NULL);
    }
    if (sys.state == in_menu && coord.x > 220 && coord.x < 590 &&       \
        coord.y > 400 && coord.y < 505) {
        sfSprite_setPosition(sys.sprite.menu.leave_two, (sfVector2f){a, b + 150});
        sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.leave_two, NULL);
    }
    display_pause(sys, coord, b, a);
}

void smoke_function(sys sys)
{
    sfVector2f coord;

    sfSprite_move(sys.sprite.menu.brum, (sfVector2f){0, 1});
    sfSprite_move(sys.sprite.menu.brumtwo, (sfVector2f){0, 1});
    coord = sfSprite_getPosition(sys.sprite.menu.brum);
    if (coord.y > 1000)
        sfSprite_setPosition(sys.sprite.menu.brum, (sfVector2f){0, -1000});
    coord = sfSprite_getPosition(sys.sprite.menu.brumtwo);
    if (coord.y > 1000)
        sfSprite_setPosition(sys.sprite.menu.brumtwo, (sfVector2f){0, -1000});
}

int receive_choice(sfVector2i coord, int status)
{
    if (status == in_menu) {
        if (coord.x > 215 && coord.x < 590 && \
            coord.y > 245 && coord.y < 355)
            return (1);
        if (coord.x > 230 && coord.x < 580 && \
            coord.y > 400 && coord.y < 505)
            return (2);
    }
    if (status == in_pause) {
        if (coord.x > 215 && coord.x < 590 && \
            coord.y > 145 && coord.y < 255)
            return (3);
        if (coord.x > 215 && coord.x < 590 && \
            coord.y > 300 && coord.y < 405)
            return (4);
        if (coord.x > 215 && coord.x < 590 && \
            coord.y > 450 && coord.y < 555)
            return (2);
    }
    return (0);
}

sys menu(sys sys)
{
    int a = 230;
    int b = 250;
    int signal = 0;
    sfVector2i coord;

    sfRenderWindow_clear(sys.window, sfBlack);
    set_view(0, 0, sys.window);
    b = display_menu(sys, coord, b, a);
    while (sfRenderWindow_pollEvent(sys.window, &sys.event)) {
        if (sys.event.type == sfEvtClosed) sfRenderWindow_close(sys.window);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            coord = sfMouse_getPositionRenderWindow(sys.window);
            signal = receive_choice(coord, sys.state);
        }
    }
    display_big(sys);
    sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.brum, NULL);
    sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.brumtwo, NULL);
    smoke_function(sys);
    if (signal == 1) sys.state = in_map;
    if (signal == 2) sys.state = 84;
    if (signal == 3) sys.state = in_map;
    if (signal == 4) write_file(sys.player, sys.var);
    if (signal == 5) sys.state = in_menu;
    return (sys);
}
