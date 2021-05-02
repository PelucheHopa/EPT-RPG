/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** nothing
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int diece = 1;

    for (;nb / diece != 0 ; diece = diece * 10);
    diece = diece / 10;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    while (diece != 0) {
        my_putchar(nb / diece + 48);
        nb = nb % diece;
        diece = diece / 10;
    }
    return (diece);
}
