/*
** EPITECH PROJECT, 2019
** write
** File description:
** save.h
*/

#ifndef __SAVE__H__
#define __SAVE__H__
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stddef.h>


typedef struct s_save {
    int atk;
    int def;
    int pv;
    int pos_x;
    int pos_y;
    int quest;
}save_t; 

void my_putchar(char);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char *);
char *my_getstr(int nb);

#endif
