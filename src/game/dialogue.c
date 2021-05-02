/*
** EPITECH PROJECT, 2020
** window
** File description:
** window
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "dialogue.h"

int event(win_t *w, int x)
{
    while (sfRenderWindow_pollEvent(w->win, &w->event)) {
        if ((w->event).type == sfEvtClosed)
            sfRenderWindow_close(w->win);
        if (sfKeyboard_isKeyPressed(sfKeyRight))
             x++;
    }
    return (x);
}

bub_t *init_spt(char *filepath)
{
    bub_t *s = malloc(sizeof(bub_t));

    s->text = sfTexture_createFromFile(filepath, &s->rect);
    s->spt = sfSprite_create();
    s->tpos.x = 0;
    s->tpos.y = 0;
    sfSprite_setTexture(s->spt, s->text, sfTrue);
    sfSprite_setPosition(s->spt, (sfVector2f){-100, -100});
    return (s);
}

char **text(char *pathtext)
{
    char **text = NULL;
    int fd = 0;

    text = malloc(sizeof(char *) * (50));
    fd = open(pathtext, O_RDONLY);
    //limit == 42
    text[0] = get_next_line(fd);
    for (int x = 0; text[x] != NULL;) {
        x++;
        text[x] = get_next_line(fd);
    }
    close(fd);
    return (text);
}

util_t *init_txt(char **dial)
{
    util_t *u = malloc(sizeof(util_t));
    sfFont *font = sfFont_createFromFile("./text/atwriter.ttf");
    int compt = 0;

    u->txt = malloc(sizeof(sfText *) * (50));
    for (int x = 0; dial[x] != NULL; x++, compt = compt + 20) {
        u->txt[x] = sfText_create();
        sfText_setFont(u->txt[x], font);
        sfText_setCharacterSize(u->txt[x], 15);
        sfText_setString(u->txt[x], dial[x]);
        u->pos.x = 800;
        u->pos.y = 800;
        sfText_setPosition(u->txt[x], u->pos);
    }
    return (u);
}

int dialogue(char **dial, int x, sfRenderWindow *w, bub_t *b, util_t *u, sfVector2f vec)
{
    if (dial[x + 3] != NULL) {
        sfSprite_setPosition(b->spt, (sfVector2f){vec.x - 100, vec.y + 200});
        sfRenderWindow_drawSprite(w, b->spt, NULL);
        u->pos.x = vec.x - 90;
        u->pos.y = vec.y + 210;
        sfText_setPosition(u->txt[x], u->pos);
        u->pos.x = vec.x - 90;
        u->pos.y = vec.y + 230;
        sfText_setPosition(u->txt[x + 1], u->pos);
        u->pos.x = vec.x - 90;
        u->pos.y = vec.y + 250;
        sfText_setPosition(u->txt[x + 2], u->pos);
        u->pos.x = vec.x - 90;
        u->pos.y = vec.y + 270;
        sfText_setPosition(u->txt[x + 3], u->pos);
        sfRenderWindow_drawText(w, u->txt[x], NULL);
        sfRenderWindow_drawText(w, u->txt[x + 1], NULL);
        sfRenderWindow_drawText(w, u->txt[x + 2], NULL);
        sfRenderWindow_drawText(w, u->txt[x + 3], NULL);
    }
    if (dial[x + 3] == NULL) return 0;
    return (x);
}

int init_talk(char **dial, int x, sfRenderWindow *w, sfVector2f vec)
{
    struct s_talk talk;

    talk.bub = init_spt("./picture/png/dialog_bar2.png");
    talk.util = init_txt(dial);
    x = dialogue(dial, x, w, talk.bub, talk.util, vec);
    free(talk.util->txt);
    return (x);
}
