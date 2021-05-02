/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "dialogue.h"
#include "rpg.h"
#include "get_next_line.h"

sfVector2f position_text(sfVector2f vec, sfSprite *player)
{
    vec = sfSprite_getPosition(player);
    if (vec.x > 200 && vec.x <= 4550) vec.x = vec.x - 150;
    if (vec.x < 200) vec.x = 200;
    if (vec.x > 4550) vec.x = 4400;
    return (vec);
}

void free_function(char **map)
{
    for (int letter = 0; map[letter] != NULL; letter++) free(map[letter]);
}

sys display(sys sys)
{
    sfRenderWindow_drawSprite(sys.window, sys.sprite.town, NULL);
    sfRenderWindow_drawSprite(sys.window, sys.sprite.player, NULL);
    sfRenderWindow_drawSprite(sys.window, sys.sprite.toit, NULL);
    sfSprite_setPosition(sys.sprite.inventory, (sfVector2f){sys.var.a + 10, sys.var.b + 510});
    sfRenderWindow_drawSprite(sys.window, sys.sprite.inventory, NULL);
    sfSprite_setPosition(sys.sprite.interface, (sfVector2f){sys.var.a + 10, sys.var.b + 10});
    sfRenderWindow_drawSprite(sys.window, sys.sprite.interface, NULL);
    sys.vec = position_text(sys.vec, sys.sprite.player);
    sys.vec = position_text(sys.vec, sys.sprite.player);
    if (sys.var.line == 0) sys.dial_status = 0;
    if (sys.var.x / 50 <= 3 && sys.var.y / 50 >= 35 && sys.var.y / 50 <= 39) {
        sys.var.line = init_talk(sys.dial_one, sys.var.line, sys.window, sys.vec);
        sys.dial_status = 1;
    }
    if (sys.var.y / 50 <= 10 && sys.var.x / 50 >= 50 && sys.var.x / 50 <= 54) {
        sys.var.line = init_talk(sys.dial_two, sys.var.line, sys.window, sys.vec);
        sys.dial_status = 1;
    }
    if (sys.var.x / 50 == 88 && sys.var.y / 50 == 35) {
        sys.var.line = init_talk(sys.dial_tree, sys.var.line, sys.window, sys.vec);
        sys.dial_status = 1;
    }
    return (sys);
}

void display_pause(sys sys, sfVector2i coord, int b, int a)
{
    if (sys.state == in_pause && coord.x > 220 && coord.x < 590 &&      \
        coord.y > 140 && coord.y < 255) {
        b = b - 95;
        sfSprite_setPosition(sys.sprite.menu.resume_two, (sfVector2f){a, b});
        sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.resume_two, NULL);
    }
    if (sys.state == in_pause && coord.x > 220 && coord.x < 590 &&      \
        coord.y > 300 && coord.y < 415) {
        b = b + 50;
        sfSprite_setPosition(sys.sprite.menu.save_two, (sfVector2f){a, b});
        sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.save_two, NULL);
    }
    if (sys.state == in_pause && coord.x > 220 && coord.x < 590 &&       \
        coord.y > 460 && coord.y < 565) {
        sfSprite_setPosition(sys.sprite.menu.leave_two, (sfVector2f){a, b + 200});
        sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.leave_two, NULL);
    }
}

int display_menu(sys sys, sfVector2i coord, int b, int a)
{
    if (sys.state == in_menu) {
        sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.title, NULL);
        sfSprite_setPosition(sys.sprite.menu.start, (sfVector2f){a, b});
        sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.start, NULL);
    }
    else {
        b = b - 100;
        sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.pause_menu, NULL);
        sfSprite_setPosition(sys.sprite.menu.resume, (sfVector2f){a, b});
        sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.resume, NULL);
        sfSprite_setPosition(sys.sprite.menu.save, (sfVector2f){a, b + 150});
        sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.save, NULL);
        b = b + 150;
    }
    sfSprite_setPosition(sys.sprite.menu.leave, (sfVector2f){a, b + 150});
    sfRenderWindow_drawSprite(sys.window, sys.sprite.menu.leave, NULL);
    return (b);
}
