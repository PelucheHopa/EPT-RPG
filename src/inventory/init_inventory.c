/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_inventory
*/

#include "my.h"

inventory_s *create_inventory(char *img_path, sfVector2f position)
{
    inventory_s *inevntory_img;
    sfIntRect rect = creat_int_rect(0, 0, 35, 35);

    inevntory_img = malloc(sizeof(inventory_s));
    inevntory_img->pos.x = position.x;
    inevntory_img->pos.y = position.y;
    inevntory_img->texture = sfTexture_createFromFile(img_path, NULL);
    inevntory_img->sprite = sfSprite_create();
    sfSprite_setTextureRect(inevntory_img->sprite, rect);
    sfSprite_setPosition(inevntory_img->sprite, position);
    sfSprite_setTexture(inevntory_img->sprite, inevntory_img->texture, 0);
    return (inevntory_img);
}

void init_other_img(inventory_s **imgs)
{
    imgs[5] = create_inventory("inventory_assets/item_6.png", (sfVector2f) {410.0, 90.0});
    imgs[5]->name = my_strcpy(imgs[5]->name, "img5");
    imgs[6] = create_inventory("inventory_assets/item_7.png", (sfVector2f) {460.0, 90.0});
    imgs[6]->name = my_strcpy(imgs[6]->name, "img6");
    imgs[7] = create_inventory("inventory_assets/item_8.png", (sfVector2f) {500.0, 90.0});
    imgs[7]->name = my_strcpy(imgs[7]->name, "img7");
    imgs[8] = create_inventory("inventory_assets/item_9.png", (sfVector2f) {550.0, 90.0});
    imgs[8]->name = my_strcpy(imgs[8]->name, "img8");
    imgs[9] = NULL;
}

void set_state(inventory_s **imgs, int state)
{
    int i = 0;

    while (imgs[i] != NULL) {
        imgs[i]->state = state;
        i++;
    }
}

void change_item_price(inventory_s **imgs, int id, int price)
{
    imgs[id]->cost = price;
}

inventory_s **init_inventory(void)
{
    inventory_s **imgs = NULL;

    imgs = malloc(sizeof(inventory_s) * 10);
    imgs[0] = create_inventory("inventory_assets/item_1.png", (sfVector2f) {160.0, 90.0});
    imgs[0]->name = my_strcpy(imgs[0]->name, "img0");
    imgs[1] = create_inventory("inventory_assets/item_2.png", (sfVector2f) {210.0, 90.0});
    imgs[1]->name = my_strcpy(imgs[1]->name, "img1");
    imgs[2] = create_inventory("inventory_assets/item_3.png", (sfVector2f) {260.0, 90.0});
    imgs[2]->name = my_strcpy(imgs[2]->name, "img2");
    imgs[3] = create_inventory("inventory_assets/item_4.png", (sfVector2f) {310.0, 90.0});
    imgs[3]->name = my_strcpy(imgs[3]->name, "img3");
    imgs[4] = create_inventory("inventory_assets/item_5.png", (sfVector2f) {360.0, 90.0});
    imgs[4]->name = my_strcpy(imgs[4]->name, "img4");
    init_other_img(imgs);
    set_state(imgs, not_buy);
    return (imgs);
}