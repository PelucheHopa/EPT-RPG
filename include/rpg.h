/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** defender.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define RPG_H_
#ifdef RPG_H_

#include "my.h"

enum state_possible {
    in_inventory,
    in_shop,
    in_map,
    in_menu,
    in_pause
};

struct s_player
{
    int gold;
    int atk;
    int def;
    int pv;
    int skill_one;
    int skill_two;
    int skill_tree;
};

struct s_menu
{
    sfSprite *pause_menu;
    sfSprite *title;
    sfSprite *brum;
    sfSprite *brumtwo;
    sfSprite *resume;
    sfSprite *start;
    sfSprite *leave;
    sfSprite *save;
    sfSprite *resume_two;
    sfSprite *start_two;
    sfSprite *leave_two;
    sfSprite *save_two;
    sfSprite *music;
    sfSprite *help;
};

struct s_sprite
{
    struct s_menu menu;
    sfSprite *town;
    sfSprite *player;
    sfSprite *help;
    sfIntRect rect;
    sfSprite *toit;
    sfSprite *mappicture;
    sfSprite *interface;
    sfSprite *inventory;
    sfSprite *skill_one;
    sfSprite *skill_two;
    sfSprite *skill_tree;
    sfSprite *skill_for;
    sfSprite *hero;
    sfSprite *but_one;
    sfSprite *but_two;
    sfSprite *but_tree;
    sfSprite *but_for;
    sfSprite *monster_one;
    sfSprite *background;
};

struct s_var
{
    int move;
    int direction;
    int quest;
    int world;
    int x;
    int y;
    int stack_y;
    int stack_x;
    int a;
    int b;
    int line;
};

typedef struct s_system
{
    int compt_a;
    int compt_b;
    image_s *inventor_bg;
    image_s *shop_bg;
    image_s *btn_buy;
    int state;
    char **map;
    char **dial_one;
    char **dial_two;
    char **dial_tree;
    sfVector2i mouse_pos;
    inventory_s **inventor;
    inventory_s **shop;
    sfVector2f vec;
    struct s_var var;
    struct s_sprite sprite;
    struct s_player player;
    sfRenderWindow *window;
    sfEvent event;
    int dial_status;
    sfClock *clock;
    int turn;
    int life_monster;
}sys;

sfMusic *set_music_game(char *str);

void my_putchar(char c);

void my_putstr(char const *str);

sfRenderWindow *set_window(void);

sfSprite *set_sprite(char *path, int x, int y);

sys event_function(sys sys, sfEvent event);

struct s_var event_one(struct s_var var, sfRenderWindow *window, char **map);

struct s_var event_two(struct s_var var, sfRenderWindow *window, char **map);

struct s_player init_player(void);
//view
void view_player(int a, int b, sfRenderWindow *window);

sfView *set_view(int a, int b, sfRenderWindow *window);

//init
struct s_var init_struct_var(void);

struct s_sprite init_struct_sprite(void);

//display
void free_function(char **map);

sys display(sys sys);

sys fight(sys sys);
//save
void input_save(char *value, char *data, int fd);

void write_file(struct s_player player, struct s_var var);

int recup_data(char *str);

int research_data(char **file, char *search);

char **recup_file(void);

sys display_inventory(sys *systm, image_s *inventor_bg);

sys display_shop(sys *systm, image_s *bg, image_s *btn_buy);

sys init_sys(void);

char **take_map(char *path);

void display_pause(sys sys, sfVector2i coord, int b, int a);

int display_menu(sys sys, sfVector2i coord, int b, int a);

void smoke_function(sys sys);

void display_big(sys sys);

int receive_choice(sfVector2i coord, int status);

sys menu(sys sys);

#endif
