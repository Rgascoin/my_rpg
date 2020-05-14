/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Compare two strings
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (-2);
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
        i++;
    }
    return (0);
}
