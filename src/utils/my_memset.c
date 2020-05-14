/*
** EPITECH PROJECT, 2019
** my_memset
** File description:
** Initialize string value
*/

#include "my.h"

void my_memset(void *s, int c, int size)
{
    int i = 0;
    char *str = (char *) s;

    while (str != NULL && i < size)
        str[i++] = (char) c;
}
