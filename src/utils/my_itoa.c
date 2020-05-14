/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** Convert int to char
*/

#include "my.h"

char *my_itoa(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (my_intlen(nb) + 1));

    if (!str)
        return (NULL);
    if (nb < 0) {
        nb *= -1;
        str[i++] = '-';
    }
    (nb == 0) ? str[i++] = '0' : 0;
    while (nb != 0) {
        str[i++] = nb % 10 + '0';
        nb /= 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}
