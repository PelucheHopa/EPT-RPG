/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str)
{
    int i = 0;
    int symb = 1;
    int n = 0;

    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-')
            symb *= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        n = (n * 10) + str[i] - 48;
        i++;
    }
    return (n * symb);
}