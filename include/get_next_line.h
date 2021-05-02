/*
** EPITECH PROJECT, 2019
** include
** File description:
** include
*/

#define GET_H_
#ifdef GET_H_

#define READ_SIZE 42

struct s_str
{
    char *after;
    int lock;
    int valid;
    int block;
};

struct s_int
{
    char *buff;
    int a;
    int b;
};

char *get_next_line(int fd);

void my_putchar (char c);

void my_putcherror(char c);

void my_putstrerror(char const *str);

int my_getnbr(char const *str);

#endif
