/*
** EPITECH PROJECT, 2019
** my_config
** File description:
** Config Management
*/

#include "my_config.h"

bool create_config(config_t **config, const char *name, char *data)
{
    config_t *element = my_calloc(1, sizeof(*element));

    if (!element)
        return (false);
    element->name = name;
    element->data = data;
    element->next = *config;
    *config = element;
    return (true);
}

config_t *get_config(config_t *config, const char *name)
{
    config_t *element = config;

    while (element != NULL) {
        if (my_strcmp(element->name, name) == 0)
            return (element);
        element = element->next;
    }
    return (NULL);
}

static bool destroy_first(config_t **config)
{
    config_t *element = *config;
    config_t *next = NULL;

    if (!element)
        return (false);
    next = element->next;
    free(element);
    *config = next;
    return (true);
}

bool destroy_config(config_t **config, const char *name)
{
    config_t *element = *config;
    config_t *next = NULL;

    if (my_strcmp(element->name, name) == 0 || element->next == NULL) {
        destroy_first(config);
        return (true);
    }
    while (element->next != NULL) {
        if (my_strcmp(element->next->name, name) == 0) {
            next = element->next->next;
            free(element->next);
            element->next = next;
            return (true);
        }
        element = element->next;
    }
    return (false);
}
