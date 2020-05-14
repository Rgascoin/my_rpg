/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Count number of char in a string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str != NULL && str[i] != '\0')
        i++;
    return (i);
}
