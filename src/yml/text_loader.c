/*
** EPITECH PROJECT, 2019
** my_cgraph
** File description:
** Text Loader Management
*/

#include "my_rpg.h"

static bool load_text(texts_t **texts, config_t *text)
{
    char *name = get_field("name", text->data);
    char *path = get_field("font", text->data);
    char *str = get_field("str", text->data);
    sfVector2f pos = {my_atoi(get_field("pos.x", text->data)),
        my_atoi(get_field("pos.y", text->data))};

    if (!name || !path || !str)
        return (false);
    create_text(texts, name, path);
    if (!get_text(*texts, name))
        return (false);
    init_text(get_text(*texts, name), pos, str);
    return (true);
}

bool load_texts(texts_t **texts, const char *path)
{
    bool status = true;
    config_t *config = NULL;
    config_t *element = NULL;

    if (!load_config(&config, path))
        return (false);
    element = config;
    while (element != NULL) {
        if (my_strcmp(element->name, "text") == 0)
            status = load_text(texts, element);
        if (!status)
            return (false);
        element = element->next;
    }
    return (true);
}
