/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "rpg.h"

int get_rect(inventory_s **invent, sfVector2i mouse_position)
{
    int i = 0;
    sfFloatRect my_rect;

    while (invent[i] != NULL) {
        my_rect = sfSprite_getGlobalBounds(invent[i]->sprite);;
        if (sfFloatRect_contains(&my_rect, mouse_position.x, mouse_position.y)) {
            return (i);
        }
        i++;
    }
    return (0);
}

void draw_invetory(sys *systm, sfRenderWindow *window)
{
    for (size_t i = 0; systm->inventor[i] != NULL; i++) {
        if (systm->inventor[i]->state == buy) {
            sfRenderWindow_drawSprite(window, systm->inventor[i]->sprite, 0);
        }
    }
}

void set_position(int id, int id_old_pos, inventory_s **inventory)
{
    static sfVector2f tmp;

    tmp = inventory[id]->pos;
    inventory[id]->pos = inventory[id_old_pos]->pos;
    inventory[id_old_pos]->pos = tmp;
    sfSprite_setPosition(inventory[id]->sprite, inventory[id]->pos);
    sfSprite_setPosition(inventory[id_old_pos]->sprite, inventory[id_old_pos]->pos);
}

sys *check_event(sys *systm, sfVector2i mouse_position)
{
    sfEvent event;
    sfFloatRect rect = sfSprite_getGlobalBounds(systm->inventor[0]->sprite);
    int id = 0;
    static int change = 0;
    static int id_old_pos = -1;


    while (sfRenderWindow_pollEvent(systm->window, &event)) {
        if (event.type == sfEvtClosed) sfRenderWindow_close(systm->window);
        if (sfMouse_isButtonPressed(sfMouseLeft) && change == 0 && id_old_pos == -1) { //rm event.type == sfEvtMouseButtonPressed &&
            id = get_rect(systm->inventor, mouse_position);
            rect = sfSprite_getGlobalBounds(systm->inventor[id]->sprite);
            if (sfFloatRect_contains(&rect, mouse_position.x, mouse_position.y)) {
                change = 1;
                id_old_pos = id;
                return (systm);
            }
            return (systm);
        }
        if ( sfMouse_isButtonPressed(sfMouseLeft) && change == 1 && id_old_pos != -1) { // rm event.type == sfEvtMouseButtonPressed &&
            id = get_rect(systm->inventor, mouse_position);
            rect = sfSprite_getGlobalBounds(systm->inventor[id]->sprite);
            if (sfFloatRect_contains(&rect, mouse_position.x, mouse_position.y)) {
                change = 0;
                set_position(id, id_old_pos, systm->inventor);
                id_old_pos = -1;
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyX)) systm->state = in_map;
    }
    return (systm);
}

sys display_inventory(sys *systm, image_s *inventor_bg)
{
    if (systm->state == in_inventory) {
        sfRenderWindow_clear(systm->window, sfBlack);
        sfRenderWindow_drawSprite(systm->window, inventor_bg->sprite, 0);
        systm->mouse_pos = sfMouse_getPositionRenderWindow(systm->window);
        systm = check_event(systm, systm->mouse_pos);
        draw_invetory(systm, systm->window);
        sfRenderWindow_display(systm->window);
    }
    return (systm[0]);
}
