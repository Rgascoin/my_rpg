/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Concat two strings
*/

#include "my.h"

char *my_strcat(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));

    if (!str)
        return (NULL);
    while (s1 != NULL && s1[i] != '\0')
        str[k++] = s1[i++];
    while (s2 != NULL && s2[j] != '\0')
        str[k++] = s2[j++];
    str[k] = '\0';
    return (str);
}
