/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Loader Management
*/

#include "my_rpg.h"
#include "my_yml.h"
#include "my_callback.h"

char *get_field(const char *name, const char *data)
{
    int i = 0;
    char **line = my_split(data, " :");

    while (line != NULL && line[i] != NULL) {
        if (my_strcmp(line[i], name) == 0)
            return (line[i + 1]);
        i++;
    }
    return (NULL);
}

void *get_function(const char *name, const char *data)
{
    int i = 0;
    char *callback = get_field(name, data);

    while (name_callback[i] != NULL && fct_callback[i] != NULL) {
        if (my_strcmp(callback, name_callback[i]) == 0)
            return (fct_callback[i]);
        i++;
    }
    return (NULL);
}
