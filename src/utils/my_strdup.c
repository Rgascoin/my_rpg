/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** Copy the string
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len + 1));

    if (!dest)
        return (NULL);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
