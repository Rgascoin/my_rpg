/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Audio Management
*/

#include "my_cgraph.h"

bool create_audio(audios_t **audios, const char *name, const char *path)
{
    audios_t *element = malloc(sizeof(*element));

    if (!element)
        return (false);
    element->name = name;
    element->sf_music = sfMusic_createFromFile(path);
    if (!element->sf_music)
        return (false);
    element->next = *audios;
    *audios = element;
    return (true);
}

audios_t *get_audio(audios_t *audios, const char *name)
{
    audios_t *element = audios;

    while (element != NULL) {
        if (my_strcmp(element->name, name) == 0)
            return (element);
        element = element->next;
    }
    return (NULL);
}

static bool destroy_first(audios_t **audios)
{
    audios_t *element = *audios;
    audios_t *next = NULL;

    if (!element)
        return (false);
    next = element->next;
    sfMusic_destroy(element->sf_music);
    free (element);
    *audios = next;
    return (true);
}

bool destroy_audio(audios_t **audios, const char *name)
{
    audios_t *element = *audios;
    audios_t *next = NULL;

    if (!element)
        return (false);
    if (my_strcmp(element->name, name) == 0 || element->next == NULL) {
        destroy_first(audios);
        return (true);
    }
    while (element->next != NULL) {
        if (my_strcmp(element->next->name, name) == 0) {
            next = element->next->next;
            sfMusic_destroy(element->next->sf_music);
            free(element->next);
            element->next = next;
            return (true);
        }
        element = element->next;
    }
    return (false);
}
