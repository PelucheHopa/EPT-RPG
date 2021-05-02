/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_shop
*/

#include "rpg.h"

void set_cost(inventory_s **imgs, int price)
{
    int i = 0;

    while (imgs[i] != NULL) {
        imgs[i]->cost = price;
        i++;
    }
}

