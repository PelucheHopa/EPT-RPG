/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "dialogue.h"
#include "rpg.h"
#include "get_next_line.h"

struct s_player init_player(void)
{
    struct s_player player;
    char **file = recup_file();

    player.gold = research_data(file, "GOLD");
    player.atk = research_data(file, "ATK");
    player.def = research_data(file, "DEF");
    player.pv = research_data(file, "PV");
    return (player);
}

struct s_var init_struct_var(void)
{
    struct s_var var;
    char **file = recup_file();

    var.move = 0;
    var.direction = 0;
    var.x = research_data(file, "X");
    var.y = research_data(file, "Y");
    var.line = 0;
    var.x = var.x * 50;
    var.y = var.y * 50;
    var.stack_x = 0;
    var.stack_y = 0;
    var.a = var.x - 400;
    var.b = var.y - 300;
    return (var);
}

struct s_sprite init_struct_sprite(void)
{
    struct s_sprite s;

    s.rect = (sfIntRect){200, 101, 100, 101};
    s.town = set_sprite("picture/png/road.png", 0, 0);
    s.player = set_sprite("picture/png/player2.png", 0, 0);
    s.monster_one = set_sprite("picture/png/monster.png", 0, 0);
    s.skill_one = set_sprite("picture/png/one.png", 0, 0);
    s.skill_two = set_sprite("picture/png/two.png", 0, 0);
    s.skill_tree = set_sprite("picture/png/tree.png", 0, 0);
    s.skill_for = set_sprite("picture/png/for.png", 0, 0);
    s.but_for = set_sprite("picture/png/but.png", 0, 0);
    s.but_tree = set_sprite("picture/png/but.png", 0, 0);
    s.but_two = set_sprite("picture/png/but.png", 0, 0);
    s.but_one = set_sprite("picture/png/but.png", 0, 0);
    s.hero = set_sprite("picture/png/hero.png", 0, 0);
    s.help = set_sprite("picture/png/help.png", 0, 0);
    s.background = set_sprite("picture/png/background.jpg", 0, 0);
    sfSprite_setTextureRect(s.player, s.rect);
    s.toit = set_sprite("picture/png/Oxurtoit.png", 0, 0);
    s.inventory = set_sprite("picture/png/inventory.png", -100, -100);
    s.interface = set_sprite("picture/png/interface.png", -100, -100);
    s.menu.start = set_sprite("picture/png/start.png", -100, -100);
    s.menu.resume = set_sprite("picture/png/resume.png", -100, -100);
    s.menu.leave = set_sprite("picture/png/leave.png", -100, -100);
    s.menu.save = set_sprite("picture/png/save.png", -100, -100);
    s.menu.start_two = set_sprite("picture/png/start2.png", -100, -100);
    s.menu.resume_two = set_sprite("picture/png/resume2.png", -100, -100);
    s.menu.leave_two = set_sprite("picture/png/leave2.png", -100, -100);
    s.menu.save_two = set_sprite("picture/png/save2.png", -100, -100);
    s.menu.pause_menu = set_sprite("picture/png/pause_menu.png", 0, 0);
    s.menu.title = set_sprite("picture/png/title.jpg", 0, 0);
    s.menu.brum = set_sprite("picture/png/brum.png", 0, 0);
    s.menu.brumtwo = set_sprite("picture/png/brum.png", 0, -1000);
    return (s);
}

sys init_sys(void)
{
    sys sys;

    sys.dial_status = 0;
    sys.inventor = init_inventory();
    sys.shop = init_inventory();
    set_cost(sys.shop, 200);
    set_state(sys.shop, buy);
    sys.map = take_map("./map/road");
    sys.dial_one = text("text/dialogue_one");
    sys.dial_two = text("text/dialogue_two");
    sys.dial_tree = text("text/dialogue_tree");
    sys.player = init_player();
    sys.window = set_window();
    sys.var = init_struct_var();
    sys.sprite = init_struct_sprite();
    sys.vec = sfSprite_getPosition(sys.sprite.player);
    set_view(sys.var.a, sys.var.b, sys.window);
    sys.inventor_bg = set_background("inventory_assets/inventory_bg.png");
    sys.shop_bg = set_background("inventory_assets/inventory_bg.png");
    sys.btn_buy = create_img("inventory_assets/buy.png");
    sfSprite_setTextureRect(sys.btn_buy->sprite, (sfIntRect) {0, 0, 100, 45});
    sfSprite_setPosition(sys.btn_buy->sprite, (sfVector2f){200, 400});
    sys.clock = sfClock_create();
    return (sys);
}
