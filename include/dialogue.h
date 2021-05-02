/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rpg.h
*/

#include <stdlib.h>
#include <SFML/Graphics.h>

#ifndef DIALOGUE_H
#define DIALOGUE_H

typedef struct win_s
{
    sfRenderWindow *win;
    sfEvent event;
}win_t;

typedef struct bub_s
{
    sfIntRect rect;
    sfSprite *spt;
    sfTexture *text;
    sfVector2f tpos;
}bub_t;

typedef struct dial
{
    sfText **txt;
    sfVector2f pos;
}util_t;

struct s_talk
{
    bub_t *bub;
    util_t *util;
    win_t *win;
    char **dial;
};

char **text(char *pathtext);

int dialogue(char **dial, int x, sfRenderWindow *w, bub_t *b, util_t *u, sfVector2f vec);

int init_talk(char **dial, int x, sfRenderWindow *w, sfVector2f vec);

#endif
