/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "dialogue.h"
#include "rpg.h"
#include "get_next_line.h"
#include <sys/wait.h>

void help(sys sys)
{
    set_view(0, 0, sys.window);
    sys.sprite.help = set_sprite("picture/png/help.png", 0, 0);
    while (sfRenderWindow_isOpen(sys.window)) {
        while (sfRenderWindow_pollEvent(sys.window, &sys.event))
            if (sys.event.type == sfEvtClosed)
                sfRenderWindow_close(sys.window);
        sfRenderWindow_drawSprite(sys.window, sys.sprite.help, NULL);
        sfRenderWindow_display(sys.window);
    }
    sfSprite_destroy(sys.sprite.help);
}

char **take_map(char *path)
{
    int fd = open(path, O_RDONLY);
    char **map = NULL;

    map = malloc(sizeof(char *) * (100));
    map[0] = get_next_line(fd);
    for (int letter = 0; map[letter] != NULL;) {
        letter++;
        map[letter] = get_next_line(fd);
    }
    close(fd);
    return (map);
}

struct s_var direction_sprite(sfSprite *player, int a, int move, sfClock *clock, struct s_var var)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 100 && var.move != 0 && a == 1) {
        sfClock_restart(clock);
        sfSprite_move(player, (sfVector2f){20, 0});
        sfSprite_setTextureRect(player, (sfIntRect){100, 101 + (var.move * 101), 100, 101});
        var.move++;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 100 && var.move != 0 && a == 2) {
        sfClock_restart(clock);
        sfSprite_move(player, (sfVector2f){-20, 0});
        sfSprite_setTextureRect(player, (sfIntRect){0, 101 + (var.move * 101), 100, 101});
        var.move++;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 100 && var.move != 0 && a == 3) {
        sfClock_restart(clock);
        sfSprite_move(player, (sfVector2f){0, -20});
        sfSprite_setTextureRect(player, (sfIntRect){0 + (var.move * 101),  0, 100, 101});
        var.move++;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 100 && var.move != 0 && a == 4) {
        sfClock_restart(clock);
        sfSprite_move(player, (sfVector2f){0, 20});
        sfSprite_setTextureRect(player, (sfIntRect){200, 101 + (var.move * 101), 100, 101});
        var.move++;
    }
    if (var.move > 2) {
        sfSprite_setPosition(player, (sfVector2f){var.x - 20 , var.y - 50});
        var.move = 0;
    }
    return (var);
}

sys launch(sys sys, char **map)
{
    if (sys.var.move == 0) sys = event_function(sys, sys.event);
    sys.var = direction_sprite(sys.sprite.player, sys.var.direction, sys.var.move, sys.clock, sys.var);
    sys = display(sys);
    return (sys);
}

int main(int ac, char **av)
{
    sys sys = init_sys();
    int temp = 0;
    sfMusic *music = set_music_game("music/entralink.ogg");
    sfMusic *cave = set_music_game("music/grotte.ogg");

    sys.state = in_menu;
    sfSprite_setPosition(sys.sprite.player, (sfVector2f){sys.var.x - 20 , sys.var.y - 50});
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' &&
        av[1][2] == '\0') {
        help(sys);
    }
    while (sfRenderWindow_isOpen(sys.window)) {
        sys.mouse_pos = sfMouse_getPositionRenderWindow(sys.window);
        if (sys.state == 8) {
            sfMusic_setVolume(music, 0);
            sfMusic_setVolume(cave, 0);
            sys = fight(sys);
        }
        if (sys.state == in_menu || sys.state == in_pause) {
            sfMusic_setVolume(music, 50);
            sfMusic_setVolume(cave, 0);
            sys = menu(sys);
        }
        if (sys.state == in_map) {
            sfMusic_setVolume(music, 0);
            sfMusic_setVolume(cave, 50);
            view_player(sys.var.a, sys.var.b, sys.window);
            sys = launch(sys, sys.map);
        }
        if (sys.state == in_inventory) {
            set_view(0, 0, sys.window);
            sfRenderWindow_drawSprite(sys.window, sys.inventor_bg->sprite, 0);
            sys = display_inventory(&sys, sys.inventor_bg);
        }
        if (sys.state == 84) sfRenderWindow_close(sys.window);
        if (sys.state == in_shop) {
            set_view(0, 0, sys.window);
            sys = display_shop(&sys, sys.shop_bg, sys.btn_buy);
            if (sys.state == in_map) {
                sys.var.y = sys.var.y + 50;
                sys.var.b = sys.var.b + 50;
                view_player(sys.var.a, sys.var.b, sys.window);
            }
        }
        if (sys.var.x / 50 == 91 && sys.var.y / 50 == 43) sys.state = in_shop;
        if (sys.var.x / 50 == 82 && sys.var.y / 50 == 79) sys.state = in_shop;
        if (sys.var.x / 50 == 90 && sys.var.y / 50 == 81) sys.state = in_shop;
        if (sys.var.x / 50 == 97 && sys.var.y / 50 == 78) sys.state = in_shop;
        if (sys.var.x / 50 == 97 && sys.var.y / 50 == 48) sys.state = in_shop;
        if (sys.var.x / 50 == 97 && sys.var.y / 50 == 43) sys.state = in_shop;
        if (sys.var.y / 50 <= 29 && sys.var.x / 50 >= 89 && sys.var.x / 50 <= 91) {
            sys.state = 8;
        }
        sfRenderWindow_display(sys.window);
    }
    free_function(sys.map);
    sfMusic_destroy(music);
    sfMusic_destroy(cave);
    sfRenderWindow_destroy(sys.window);
    return (0);
}
