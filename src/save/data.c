/*
** EPITECH PROJECT, 2019
** write
** File description:
** assembl.c
*/

#include <stdio.h>
#include "save.h"
#include "rpg.h"
#include "get_next_line.h"

void input_save(char *value, char *data, int fd)
{
    write(fd, data, my_strlen(data));
    write(fd, value, my_strlen(value));
    write(fd, "\n", 1);
}

void write_file(struct s_player player, struct s_var var)
{
    int fd = open("save/save", O_CREAT|O_TRUNC |O_RDWR, 0664);

    input_save(my_getstr(player.gold), "GOLD=", fd);
    input_save(my_getstr(player.atk), "ATK=", fd);
    input_save(my_getstr(player.def), "DEF=", fd);
    input_save(my_getstr(player.pv), "PV=", fd);
    input_save(my_getstr(var.x / 50), "X=", fd);
    input_save(my_getstr(var.y / 50), "Y=", fd);
    input_save(my_getstr(var.world), "WORLD=", fd);
    close(fd);
}

int recup_data(char *str)
{
    int data = 0;
    int x = 0;
    int m = 0;

    for (; str[x] != '='; x++);
    x++;
    for (; str[x] != '\0'; x++, m++)
        str[m] = str[x];
    for (; str[m] != '\0'; m++)
        str[m] = '\0';
    data = my_getnbr(str);
    return (data);
}

int research_data(char **file, char *search)
{
    int y = 0;
    int x = 0;

    for (int valid = 0; file[y] != NULL && valid == 0; y++) {
        for (x = 0; file[y][x] != '\0' && search[x] != '\0' && file[y][x] == search[x]; x++);
        if (file[y][x] == '=' && search[x] == '\0') valid = 1;
    }
    y--;
    return (recup_data(file[y]));
}

char **recup_file(void)
{
    int fd = open("save/save", O_RDWR, 0664);
    char **file = NULL;
    int data = 0;

    file = malloc(sizeof(char *) * (50));
    file[0] = get_next_line(fd);
    for (int x = 0; file[x] != NULL;) {
        x++;
        file[x] = get_next_line(fd);
    }
    close(fd);
    return (file);
}
