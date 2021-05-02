/*
** EPITECH PROJECT, 2020
** New Folder
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

enum sell {
    buy,
    not_buy
};

enum btn_state {
    pressed,
    not_pressed
};

typedef struct windows_t
{
    sfRenderWindow *window;
    sfVideoMode mode;
    char *title;
}window_s;

typedef struct image_t
{
    sfSprite *sprite;
    sfTexture *texture;
}image_s;


typedef struct button_t
{
    image_s image;
    sfIntRect hitbox;

}button_s;

typedef struct inventory_t
{
    char *name;
    int state;
    int cost;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect *rect;
    sfVector2i position;
}inventory_s;

image_s createImage(char *filepath, sfBool isRepeated);
void destroy_Image(image_s image) ;
sfIntRect creat_int_rect(int top, int left, int width, int height);
sfRenderWindow *initialisation_window(sfRenderWindow *window, char *str);
void close_window(sfRenderWindow *window);
image_s *set_background(char *img_path);
image_s *create_img(char *file_path);
void start_game();
inventory_s **init_inventory(void);
char *my_strcpy(char *dest, char const *src);
void set_state(inventory_s **imgs, int state);
void set_cost(inventory_s **imgs, int price);
int get_rect(inventory_s **invent, sfVector2i mouse_position);

#endif
