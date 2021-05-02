/*
** EPITECH PROJECT, 2020
** fight
** File description:
** fight
*/

#include "my.h"
#include "rpg.h"
#include <time.h>

void set_fight(sys sys)
{
    set_view(0, 0, sys.window);
    sfSprite_setPosition(sys.sprite.hero, (sfVector2f){500 , 300});
    sfSprite_setPosition(sys.sprite.but_one, (sfVector2f){100 , 400});
    sfSprite_setPosition(sys.sprite.but_two, (sfVector2f){100 , 500});
    sfSprite_setPosition(sys.sprite.but_tree, (sfVector2f){300 , 400});
    sfSprite_setPosition(sys.sprite.but_for, (sfVector2f){300 , 500});
    sfSprite_setTextureRect(sys.sprite.hero, (sfIntRect){222, 429, 191, 191});
    sfSprite_setTextureRect(sys.sprite.monster_one, (sfIntRect){21, 21, 274, 274});
    sfSprite_setPosition(sys.sprite.monster_one, (sfVector2f){200 , 100});
    sfSprite_setPosition(sys.sprite.skill_one, (sfVector2f){200 , 200});
    sfSprite_setPosition(sys.sprite.skill_two, (sfVector2f){200 , 200});
    sfSprite_setPosition(sys.sprite.skill_tree, (sfVector2f){200 , 200});
    sfSprite_setPosition(sys.sprite.skill_for, (sfVector2f){200 , 200});
}

void display_fight(sys sys)
{
    sfRenderWindow_drawSprite(sys.window, sys.sprite.background, NULL);
    sfRenderWindow_drawSprite(sys.window, sys.sprite.hero, NULL);
    sfRenderWindow_drawSprite(sys.window, sys.sprite.monster_one, NULL);
}

void display_button(sys sys)
{
    sfRenderWindow_drawSprite(sys.window, sys.sprite.but_one, NULL);
    sfRenderWindow_drawSprite(sys.window, sys.sprite.but_two, NULL);
    sfRenderWindow_drawSprite(sys.window, sys.sprite.but_tree, NULL);
    sfRenderWindow_drawSprite(sys.window, sys.sprite.but_for, NULL);
}

void animation_for(sys sys)
{
    sfClock *clock = sfClock_create();

    for (int y = 57; y < 3125 - 284; y = y + 284)
        for (int x = 11; x < 1116;) {
            sfSprite_setTextureRect(sys.sprite.skill_for, (sfIntRect){x, y, 279, 284});
            display_fight(sys);
            sfRenderWindow_drawSprite(sys.window, sys.sprite.skill_for, NULL);
            display_button(sys);
            sfRenderWindow_display(sys.window);
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 50) {
                x = x + 279;
                sfClock_restart(clock);
            }
        }
    sfClock_destroy(clock);
}

void animation_two(sys sys)
{
    sfClock *clock = sfClock_create();

    for (int y = 15; y < 1823; y = y + 165)
        for (int x = 20; x < 691;) {
            sfSprite_setTextureRect(sys.sprite.skill_two, (sfIntRect){x, y, 220, 149});
            display_fight(sys);
            sfRenderWindow_drawSprite(sys.window, sys.sprite.skill_two, NULL);
            display_button(sys);
            sfRenderWindow_display(sys.window);
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 50) {
                x = x + 242;
                sfClock_restart(clock);
            }
        }
    sfClock_destroy(clock);
}

void animation_tree(sys sys)
{
    sfClock *clock = sfClock_create();

    for (int y = 52; y < 1725; y = y + 280)
        for (int x = 12; x < 1125;) {
            sfSprite_setTextureRect(sys.sprite.skill_tree, (sfIntRect){x, y, 270, 275});
            display_fight(sys);
            sfRenderWindow_drawSprite(sys.window, sys.sprite.skill_tree, NULL);
            display_button(sys);
            sfRenderWindow_display(sys.window);
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 50) {
                x = x + 280;
                sfClock_restart(clock);
            }
        }
    sfClock_destroy(clock);
}

void animation_one(sys sys)
{
    sfClock *clock = sfClock_create();

    for (int y = 0; y < 180 * 4; y = y + 180)
        for (int x = 0; x < 245 * 4;) {
            sfSprite_setTextureRect(sys.sprite.skill_one, (sfIntRect){x, y, 245, 180});
            display_fight(sys);
            sfRenderWindow_drawSprite(sys.window, sys.sprite.skill_one, NULL);
            display_button(sys);
            sfRenderWindow_display(sys.window);
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 50) {
                x = x + 245;
                sfClock_restart(clock);
            }
        }
    sfClock_destroy(clock);
}

sys fight_event(sys sys, sfVector2i coord)
{
    if (sys.event.type == sfEvtClosed) sfRenderWindow_close(sys.window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && coord.x > 100 && \
        coord.x < 273 && coord.y > 400 && coord.y < 480) {
        sfSprite_setTextureRect(sys.sprite.hero, (sfIntRect){15, 636, 191, 191});
        sfSprite_setTextureRect(sys.sprite.monster_one, (sfIntRect){1207, 318, 274, 274});
        animation_one(sys);
        sys.turn = 1;
        sys.life_monster = sys.life_monster - 50;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && coord.x > 100 && \
        coord.x < 273 && coord.y > 500 && coord.y < 580) {
        sfSprite_setTextureRect(sys.sprite.hero, (sfIntRect){222, 843, 191, 191});
        sfSprite_setTextureRect(sys.sprite.monster_one, (sfIntRect){1207, 318, 274, 274});
        animation_tree(sys);
        sys.turn = 1;
        sys.life_monster = sys.life_monster - 10;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && coord.x > 300 && \
        coord.x < 473 && coord.y > 400 && coord.y < 480) {
        sfSprite_setTextureRect(sys.sprite.hero, (sfIntRect){222, 843, 191, 191});
        sfSprite_setTextureRect(sys.sprite.monster_one, (sfIntRect){1207, 318, 274, 274});
        animation_two(sys);
        sys.turn = 1;
        sys.life_monster = sys.life_monster - 40;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && coord.x > 300 && \
        coord.x < 473 && coord.y > 500 && coord.y < 580) {
        sfSprite_setTextureRect(sys.sprite.hero, (sfIntRect){222, 843, 191, 191});
        sfSprite_setTextureRect(sys.sprite.monster_one, (sfIntRect){1207, 318, 274, 274});
        animation_for(sys);
        sys.turn = 1;
        sys.life_monster = sys.life_monster - 20;
    }
    return (sys);
}

sys fight(sys sys)
{
    sfVector2i coord = sfMouse_getPositionRenderWindow(sys.window);
    int victory = 0;
    int turn = 1;
    sfMusic *music = set_music_game("music/battle.ogg");

    sfMusic_setVolume(music, 50);
    set_fight(sys);
    sys.turn = 0;
    sys.life_monster = 100;
    while (victory == 0 && sfRenderWindow_isOpen(sys.window)) {
        sfSprite_setTextureRect(sys.sprite.hero, (sfIntRect){222, 429, 191, 191});
        sfSprite_setTextureRect(sys.sprite.monster_one, (sfIntRect){21, 21, 274, 274});
        if (turn == 1) {
            sfSprite_setPosition(sys.sprite.skill_one, (sfVector2f){200 , 200});
            sfSprite_setPosition(sys.sprite.skill_two, (sfVector2f){200 , 200});
            sfSprite_setPosition(sys.sprite.skill_tree, (sfVector2f){200 , 200});
            sfSprite_setPosition(sys.sprite.skill_for, (sfVector2f){200 , 200});
            while (sfRenderWindow_pollEvent(sys.window, &sys.event)) {
                coord = sfMouse_getPositionRenderWindow(sys.window);
                sys = fight_event(sys, coord);
            }
            display_fight(sys);
            display_button(sys);
            sfRenderWindow_display(sys.window);
            if (sys.turn == 1) {
                turn = 2;
                sys.turn = 0;
            }
        }
        if (sys.life_monster <= 0) victory = 1;
        if (turn == 2 && victory == 0) {
            srand(time(0));
            turn = (rand() % 4);
            sfSprite_setTextureRect(sys.sprite.hero, (sfIntRect){222, 429, 191, 191});
            sfSprite_setTextureRect(sys.sprite.monster_one, (sfIntRect){21, 318, 274, 274});
            sfSprite_setPosition(sys.sprite.skill_one, (sfVector2f){400 , 300});
            sfSprite_setPosition(sys.sprite.skill_two, (sfVector2f){470 , 350});
            sfSprite_setPosition(sys.sprite.skill_tree, (sfVector2f){400 , 300});
            sfSprite_setPosition(sys.sprite.skill_for, (sfVector2f){400 , 300});
            display_fight(sys);
            if (turn == 0) animation_one(sys);
            if (turn == 1) animation_two(sys);
            if (turn == 2) animation_tree(sys);
            if (turn == 3) animation_for(sys);
            sys.player.pv = sys.player.pv - (sys.player.pv - (10 * turn + 10));
            sfRenderWindow_display(sys.window);
            turn = 1;
        }
        if (sys.player.pv <= 0) victory = -1;
        
    }
    sfMusic_destroy(music);
    sys.state = in_map;
    sys.var.y = sys.var.y + 50;
    sys.var.b = sys.var.b + 50;
    return (sys);
}
