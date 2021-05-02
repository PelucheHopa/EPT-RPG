/*
** EPITECH PROJECT, 2020
** event
** File description:
** event
*/

#include "dialogue.h"
#include "rpg.h"
#include "get_next_line.h"

int collision(char **map, int x, int y, int choice)
{
    x = x / 50;
    y = y / 50;
    if (choice == 1 && (map[y][x + 1] == '.' || \
        map[y][x + 1] == '>')) return (1);
    if (choice == 2 && x > 0 && (map[y][x - 1] == '.' || \
        map[y][x - 1] == '<')) return (1);
    if (choice == 3 && map[y + 1] != NULL && \
        (map[y + 1][x] == '.' || map[y + 1][x] == '_')) return (1);
    if (choice == 4 && y > 0 && map[y - 1][x] == '.') return (1);
    return (0);
}

struct s_var event_two(struct s_var var, sfRenderWindow *window, char **map)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (collision(map, var.x, var.y, 1) == 1) {
            var.x = var.x + 50;
            if (var.a + 850 <= 5000 && var.stack_x == 0) var.a = var.a + 50;
            else if (var.a + 850 > 5000)
                var.stack_x = var.stack_x + 1;
            if (var.stack_x < 0) var.stack_x++;
            var.move = 1;
        }
        var.direction = 1;
        view_player(var.a, var.b, window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (collision(map, var.x, var.y, 2) == 1) {
            var.x = var.x - 50;
            if (var.a - 50 >= 0 && var.stack_x == 0) var.a = var.a - 50;
            else if (var.a - 50 < 0)
                var.stack_x = var.stack_x - 1;
            if (var.stack_x > 0) var.stack_x--;
        view_player(var.a, var.b, window);
        var.move = 1;
        }
        var.direction = 2;
    }
    return (var);
}

struct s_var event_one(struct s_var var,
                       sfRenderWindow *window, char **map)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (collision(map, var.x, var.y, 4) == 1) {
            var.y = var.y - 50;
            if (var.b - 50 >= 0 && var.stack_y == 0) var.b = var.b - 50;
            else if (var.b - 50 < 0)
                var.stack_y = var.stack_y - 1;
            if (var.stack_y > 0) var.stack_y--;
            var.move = 1;
        }
        var.direction = 3;
        view_player(var.a, var.b, window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (collision(map, var.x, var.y, 3) == 1) {
            var.y = var.y + 50;
            if (var.b + 650 <= 5000 && var.stack_y == 0) var.b = var.b + 50;
            else if (var.b + 650 > 5000)
                var.stack_y = var.stack_y + 1;
            if (var.stack_y < 0) var.stack_y++;
            var.move = 1;
        }
        var.direction = 4;
        view_player(var.a, var.b, window);
    }
    return (var);
}

sys event_function(sys sys, sfEvent event)
{
    int protect = 0;
    sfVector2i coord = sfMouse_getPositionRenderWindow(sys.window);

    protect = sys.var.line;
    while (sfRenderWindow_pollEvent(sys.window, &event)) {
        if (sfKeyboard_isKeyPressed(sfKeyA) && sys.dial_status == 1)
            sys.var.line = sys.var.line + 1;
        if (sfKeyboard_isKeyPressed(sfKeySpace)) sys.state = in_pause;
        if (event.type == sfEvtClosed) sfRenderWindow_close(sys.window);
        if (sys.var.line == 0) {
            sys.var = event_one(sys.var, sys.window, sys.map);
            sys.var = event_two(sys.var, sys.window, sys.map);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) && coord.x > 17 &&     \
            coord.x < 87 && coord.y > 512 && coord.y < 590)
            sys.state = in_inventory;
    }
    if (sys.var.line - protect == 2) sys.var.line = protect + 1;
    return (sys);
}
