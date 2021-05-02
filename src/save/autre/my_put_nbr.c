/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** nbr
*/

void my_putchar(char);

int my_put_nbr(int nb)
{
    int count = 1;
    int disp = 0;

    while ((nb/count) > 9)
        count = count * 10;
    while (count != 0) {
        disp = 48 + (nb/count);
        nb = nb % count;
        my_putchar(disp);
        count = count / 10;
    }
    return (nb);
}
