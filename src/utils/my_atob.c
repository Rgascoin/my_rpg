/*
** EPITECH PROJECT, 2019
** my_atob
** File description:
** Convert Arg to Bool
*/

#include "my.h"

bool my_atob(char const *str)
{
    if (!str)
        return (false);
    return (my_strcmp(str, "true") == 0
        || my_strcmp(str, "1") == 0 ? true : false);
}
