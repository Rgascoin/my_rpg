/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Audio Loader Management
*/

#include "my_rpg.h"

static bool load_audio(audios_t **audios, config_t *audio)
{
    char *name = get_field("name", audio->data);
    char *path = get_field("path", audio->data);

    if (!name || !path)
        return (false);
    create_audio(audios, name, path);
    if (!get_audio(*audios, name))
        return (false);
    return (true);
}

bool load_audios(audios_t **audios, const char *path)
{
    bool status = true;
    config_t *config = NULL;
    config_t *element = NULL;

    if (!load_config(&config, path))
        return (false);
    element = config;
    while (element != NULL) {
        if (my_strcmp(element->name, "audio") == 0)
            status = load_audio(audios, element);
        if (!status)
            return (false);
        element = element->next;
    }
    return (true);
}
