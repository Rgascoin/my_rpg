/*
** EPITECH PROJECT, 2019
** my_split
** File description:
** Split string
*/

#include "my.h"

static bool is_delim(const char c, const char *delim)
{
    int i = 0;

    while (delim != NULL && delim[i] != '\0') {
        if (delim[i] == c)
            return (true);
        i++;
    }
    return (false);
}

static int count_word(char const *str, const char *delim)
{
    int i = 0;
    int count = 0;

    while (str != NULL && str[i] != '\0') {
        if (!is_delim(str[i], delim)
            && (is_delim(str[i + 1], delim) || str[i + 1] == '\0'))
            count++;
        i++;
    }
    return (count);
}

char **my_split(char const *str, const char *delim)
{
    int i = 0;
    int words = count_word(str, delim);
    char *ptr = my_strdup(str);
    char *tmp = NULL;
    char **array = malloc(sizeof(char *) * (words + 1));

    while (i < words) {
        while (*ptr != '\0' && (is_delim(*ptr, delim) || *ptr == ' '))
            ptr++;
        tmp = ptr;
        while (*ptr != '\0' && !is_delim(*ptr, delim))
            ptr++;
        *ptr = '\0';
        array[i] = tmp;
        (i < words - 1) ? ptr++ : ptr;
        i++;
    }
    array[i] = NULL;
    return (array);
}
