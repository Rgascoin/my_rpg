/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Env Management
*/

#include "my_rpg.h"

char *get_env(char **env, char *name)
{
    int i = 0;
    char **line = NULL;

    while (env != NULL && env[i] != NULL) {
        line = my_split(env[i], "=");
        if (my_strcmp(line[0], name) == 0)
            return (line[1]);
        i++;
    }
    return (NULL);
}
