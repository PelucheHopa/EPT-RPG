/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shop
*/

#include "my.h"
#include "rpg.h"

int is_press_btn(sfVector2i mouse, sfEvent event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        return (pressed);
    }
    return (not_pressed);
}

int buy_it(sfEvent event, sfVector2i mouse)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        return (1);
    }
    return (0);
}

sys buy_item(sys *systm, image_s *btn, sfVector2i mouse, int gold)
{
    sfEvent event;
    sfFloatRect rect;
    sfFloatRect btn_rect = sfSprite_getGlobalBounds(btn->sprite);
    static int id = 0;
    static int btn_press = 0;

    while (sfRenderWindow_pollEvent(systm->window, &event)) {
        if (event.type == sfEvtClosed) sfRenderWindow_close(systm->window);
        if (sfKeyboard_isKeyPressed(sfKeyX)) {
            systm->state = in_map;
            return (systm[0]);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft) && btn_press == 0) {
            id = get_rect(systm->shop, mouse);
            if (id == -1)
                return(systm[0]);
            rect = sfSprite_getGlobalBounds(systm->shop[id]->sprite);
            if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
                btn_press = 1;
            }
            return (systm[0]);
        }
    }
    if (btn_press == 1 && sfFloatRect_contains(&btn_rect, mouse.x, mouse.y) && is_press_btn(mouse, event) == pressed) {
        btn_press = 0;
        systm->inventor[id]->state = buy;
        return (systm[0]);
    }
    return (systm[0]);
}

void draw_shop(inventory_s **inventor, sfRenderWindow *window)
{
    for (size_t i = 0; inventor[i] != NULL; i++) {
        if (inventor[i]->state == buy) {
            sfRenderWindow_drawSprite(window, inventor[i]->sprite, 0);
        }
    }
}

sys display_shop(sys *systm, image_s *bg, image_s *btn_buy)
{
    sfRenderWindow_clear(systm->window, sfBlack);
    sfRenderWindow_drawSprite(systm->window, bg->sprite, 0);
    sfRenderWindow_drawSprite(systm->window, btn_buy->sprite, 0);
    systm[0] = buy_item(systm, btn_buy, systm->mouse_pos, 1000);
    draw_shop(systm->shop, systm->window);
    return (systm[0]);
}
