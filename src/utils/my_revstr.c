/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Reverses a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    char tmp;
    int len = my_strlen(str) - 1;

    while (i < len) {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        len--;
        i++;
    }
    return (str);
}
